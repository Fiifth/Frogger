/*
 * windowSDL.cpp
 * Keeps track of the SDL part of the game area. Drawing background/highscores/player data, managing renderer.
 * Also locks the framerate on 60 fps by sleeping when an update is not yet needed.
 *
 *  Created on: Feb 29, 2016
 *      Author: Kwinten
 */

#include "WindowSDL.h"

using namespace frogger_sdl;

WindowSDL::WindowSDL(SDLdata* sdldata) :
		sdldata(sdldata), ren(NULL), win(NULL)
{
	MenuTextures = sdldata->getMenuTextures();
	white ={255, 255, 255,255};
	black ={0, 0, 0,0};
	blue={173,216,230,0};
}

WindowSDL::~WindowSDL()
{
	TTF_CloseFont(sans1);
	TTF_CloseFont(sans2);

	for(SDL_Texture* highScoreTex:highScoreTexV)
			SDL_DestroyTexture(highScoreTex);

	SDL_DestroyTexture(playerDataTex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

void WindowSDL::makeWindow(int ScreenWidth, int ScreenHeight,int dataWindowHeight, char const* title)
{
	setProp(ScreenWidth, ScreenHeight, dataWindowHeight, title);
	sdldata->setScreenDimension(screenWidth, gameWindowHeight);

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	win = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED,	SDL_WINDOWPOS_CENTERED, *screenWidth, *screenHeight, SDL_WINDOW_SHOWN);
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	sdldata->setRen(ren);
	sdldata->createTextures();
	updateScreen();
}
void WindowSDL::generateBackground(std::vector<frogger::Row*>* rows)
{
	std::vector<SDL_Texture*>* backTextures = sdldata->getBackTextures();
	for (frogger::Row* row : *rows)
	{
		int y = *row->getLocY();
		int height = row->getHeight();
		int x = 0, width = 0;
		char RowType=row->getRowProperties()->getType();

		int textureLocation = RowType == 'C' ? 1 : 2;
		textureLocation =	RowType == 'B' ?	0 : textureLocation;
		while (x <= *getWidth())
		{
			sdldata->renderTexture(backTextures->at(textureLocation), ren, x, y,	&width, height, 0, true);
			x = x + width;
		}
	}
}
void WindowSDL::dislayData(std::list<frogger::Player*>* players)
{
	if (sans1==nullptr)
	{
		sans1 = TTF_OpenFont("c:\\sans.ttf", *dataWindowHeight-6);
	}
	std::string newString;
	int i = 1;
	for (frogger::Player* pl : *players)
	{
		newString = newString + " P" + std::to_string(i) + " ";
		newString = newString + "Score: ";
		newString = newString + std::to_string(pl->getScore());
		newString = newString + " ammo: ";
		newString = newString + std::to_string(pl->getProjectiles());
		if((pl->getRemainingTime()!=-1)&&(!pl->isDead())) //when remaining time =-1 game is in endless mode where you only have 1 life
		{
		newString = newString + " life: ";
		newString = newString + std::to_string(pl->getLife());
		newString = newString + " time: ";
		newString = newString + std::to_string(pl->getRemainingTime());
		}
		newString = newString + "  ";
		i++;
	}

	if ((oldString != newString))
	{
		SDL_DestroyTexture(playerDataTex);
		playerDataTex = nullptr;
	}
	if (playerDataTex == nullptr)
	{
		SDL_Surface* playerData = TTF_RenderText_Shaded(sans1, newString.c_str(), blue,	black);
		playerDataTex = SDL_CreateTextureFromSurface(ren, playerData);
		SDL_FreeSurface(playerData);

		int iW=0, iH=0;
		SDL_QueryTexture(playerDataTex, NULL, NULL, &iW, &iH);
		PlayerMessageRect.x = 0;
		PlayerMessageRect.y = *screenHeight-*dataWindowHeight+3;
		PlayerMessageRect.w = (iW <= *screenWidth) ? iW : *screenWidth;
		PlayerMessageRect.h = iH;
	}

	SDL_RenderCopyEx(ren, playerDataTex, NULL, &PlayerMessageRect, 0, NULL, SDL_FLIP_NONE);
	oldString = newString;
}
void WindowSDL::setBackground(int index)
{
	sdldata->renderTexture((*MenuTextures).at(index), sdldata->getRen(), 0, 0,screenWidth, *screenHeight, 0, false);
}
void WindowSDL::updateScreen()
{
	endP = std::chrono::high_resolution_clock::now();
	int difference = (int) round(std::chrono::duration_cast<std::chrono::milliseconds>(	endP - startP).count());
	int delay = ((13 - difference)) >= 0 ? ((13 - difference)) : 0;
	SDL_Delay(delay);
	SDL_RenderPresent(ren);
	startP = std::chrono::high_resolution_clock::now();
	SDL_RenderClear(ren);
}

void WindowSDL::displayHighScore(std::vector<int> highScore,bool newHighscore)
{
	if (newHighscore)
		makeHighScoreTexture(highScore);
	int i=0;
	for(SDL_Texture* highScoreTex:highScoreTexV)
	{
		SDL_RenderCopyEx(ren, highScoreTex, NULL, &highScoreRectV.at(i), 0, NULL, SDL_FLIP_NONE);
		i++;
	}
}

void WindowSDL::makeHighScoreTexture(std::vector<int> highScore)
{
	for(SDL_Texture* highScoreTex:highScoreTexV)
		SDL_DestroyTexture(highScoreTex);

	highScoreTexV.clear();
	highScoreRectV.clear();

	if (sans2 == nullptr)
		sans2 = TTF_OpenFont("c:\\sans.ttf", 50);
	int i = 0;
	SDL_Rect Message_rect;

	for (int score : highScore)
	{
		SDL_Surface* highScoreSurf;
		SDL_Texture* 	highScoreTex;

		std::string highScore1 = (std::to_string(i + 1) + ". "+ std::to_string(score));

		highScoreSurf= TTF_RenderText_Blended(sans2,	highScore1.c_str(), black);
		highScoreTex = SDL_CreateTextureFromSurface(ren,	highScoreSurf);
		SDL_FreeSurface(highScoreSurf);
		int iW, iH;
		SDL_QueryTexture(highScoreTex, NULL, NULL, &iW, &iH);
		Message_rect.x = (*screenWidth / 2) - iW / 2;
		Message_rect.y = ((*screenHeight) / 3) + (iH * i);
		Message_rect.w = iW;
		Message_rect.h = iH;

		i++;

		highScoreTexV.push_back(highScoreTex);
		highScoreRectV.push_back(Message_rect);
	}
}

void frogger_sdl::WindowSDL::drawLineUnder(frogger::MenuButton* mode,
		frogger::MenuButton* numPlay, frogger::MenuButton* diff)
{
	SDL_Texture* line = sdldata->getLine();
	int w;
	sdldata->renderTexture(line, sdldata->getRen(), mode->getX() - mode->getH(),mode->getY(), &w, mode->getH(), 0, true);
	sdldata->renderTexture(line, sdldata->getRen(), diff->getX() - diff->getH(),diff->getY(), &w, diff->getH(), 0, true);
	sdldata->renderTexture(line, sdldata->getRen(),numPlay->getX() - numPlay->getH(), numPlay->getY(), &w,numPlay->getH(), 0, true);
}
