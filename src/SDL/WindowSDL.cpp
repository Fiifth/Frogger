/*
 * windowSDL.cpp
 *
 *  Created on: Feb 29, 2016
 *      Author: fifth
 */

#include "WindowSDL.h"
#include <iostream>
#include <math.h>

#include <string>
#include "SDLdata.h"
#include <vector>

#include <algorithm>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <ctime>
#include <ratio>
#include <chrono>
#include <Windows.h>

using namespace std;
using namespace std::chrono;
using namespace frogger_sdl;

WindowSDL::WindowSDL(SDLdata* sdldata) :
		sdldata(sdldata), ren(NULL), win(NULL)
{
	MenuTextures=sdldata->getMenuTextures();
	White ={255, 255, 255,255};
	Black ={0, 0, 0,0};
}

WindowSDL::~WindowSDL()
{
	TTF_CloseFont(Sans1);
	TTF_CloseFont(Sans2);
}

void WindowSDL::makeWindow(int ScreenWidth, int ScreenHeight,	int dataWindowHeight, char const* title)
{

	setProp(ScreenWidth, ScreenHeight, dataWindowHeight, title);
	sdldata->setScreenDimension(WIDTH, gameWindowHeight);

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	win = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED,	SDL_WINDOWPOS_CENTERED, *WIDTH, *HEIGHT, SDL_WINDOW_SHOWN);
	ren = SDL_CreateRenderer(win, -1,	SDL_RENDERER_ACCELERATED);

	sdldata->setRen(ren);
	sdldata->createTextures();
	updateScreen();
}
void WindowSDL::generateBackground(vector<frogger::Row*>* rows)
{
		std::vector<SDL_Texture*> backTextures = sdldata->getBackTextures();
		for (frogger::Row* row : *rows)
		{
			int y = *row->getLocY();
			int height = row->getHeight();
			int x = 0, width = 0;
			int textureLocation = row->getRowProperties()->getType()=='C' ? 1 : 0;
			textureLocation =row->getRowProperties()->getType()=='A'|| row->getRowProperties()->getType()=='E'|| row->getRowProperties()->getType()=='D' ?2 : textureLocation;

			while (x <= *getWidth())
			{
				sdldata->renderTexture(backTextures.at(textureLocation), ren, x,y, &width, height, 0,true);
				x = x + width;
			}
		}

}
void WindowSDL::dislayData(list<frogger::Player*>* players)
{
	string newString;
int i=1;
	for (frogger::Player* pl:*players)
	{
		newString=newString+" ||Player"+std::to_string(i)+"|| ";
		newString=newString+"Score: ";
		newString=newString+std::to_string(pl->getScore());
		newString=newString+" Proj: ";
		newString=newString+std::to_string(pl->getProjectiles());
		newString=newString+" life: ";
		newString=newString+std::to_string(pl->getLife());
		newString=newString+" time: ";
		newString=newString+std::to_string(pl->getRemainingTime());
		newString=newString+"  ";
		i++;
	}

	if ((oldString!=newString)&& !(surfaceMessage == nullptr))
	{
		SDL_FreeSurface(surfaceMessage);
		SDL_DestroyTexture(Message);
		TTF_CloseFont(Sans1);
		Sans1 = nullptr;
		surfaceMessage = nullptr;
		Message = nullptr;
	}


	if (surfaceMessage == nullptr)
	{
		Sans1 = TTF_OpenFont("c:\\sans.ttf",*HEIGHT-*dataWindowHeight-5 );
		//surfaceMessage = TTF_RenderText_Blended(Sans, newString.c_str(), Black);
		surfaceMessage=TTF_RenderText_Shaded(Sans1,newString.c_str(),Blue,Black);
		Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
	}

	int iW, iH;
	SDL_QueryTexture(Message, NULL, NULL, &iW, &iH);

	SDL_Rect Message_rect;
	Message_rect.x = 0;
	Message_rect.y = *dataWindowHeight;
	Message_rect.w = (iW<=*WIDTH)?iW:*WIDTH;
	Message_rect.h = iH;

	SDL_RenderCopyEx(ren, Message, NULL, &Message_rect, 0, NULL, SDL_FLIP_NONE);

	oldString=newString;

}
void WindowSDL::setBackground(int index)
{
	sdldata->renderTexture((*MenuTextures).at(index), sdldata->getRen(),	0, 0, WIDTH, *HEIGHT, 0,false);
}
void WindowSDL::updateScreen()
{
	endP = chrono::high_resolution_clock::now();
	int difference=std::chrono::duration_cast<std::chrono::milliseconds>(endP- startP).count();
	int delay=((15-difference))>=0?((15-difference)):0;
	SDL_Delay(delay);
	SDL_RenderPresent(ren);
	startP = chrono::high_resolution_clock::now();
	SDL_RenderClear(ren);

}

void WindowSDL::displayHighScore(std::vector<int> highScore)
{
	if (Sans2==nullptr)
		Sans2 = TTF_OpenFont("c:\\sans.ttf", 40);
	int i=0;
	SDL_Rect Message_rect;
	for(int score :highScore)
	{
		std::string highScore1=(std::to_string(i+1)+". "+std::to_string(score));

		SDL_Surface* surfaceMessage = TTF_RenderText_Blended(Sans2, highScore1.c_str(),Black);
		SDL_Texture* Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);

		int iW, iH;
			SDL_QueryTexture(Message, NULL, NULL, &iW, &iH);
			Message_rect.x = (*WIDTH/2)-iW/2;
					Message_rect.y = ((*HEIGHT)*2)/5+(iH*i);
				Message_rect.w = iW;
				Message_rect.h = iH;

		SDL_RenderCopyEx(ren, Message, NULL, &Message_rect, 0, NULL, SDL_FLIP_NONE);
		SDL_FreeSurface(surfaceMessage);
		SDL_DestroyTexture(Message);
		i++;
	}


}

void WindowSDL::saveCurrentWindowImage()
{
	rowsBackgroundGenerated = SDL_CreateRGBSurface(0, *WIDTH, *HEIGHT, 32,
			0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);

	if (rowsBackgroundGenerated)
	{
		SDL_RenderReadPixels(ren, NULL, SDL_GetWindowPixelFormat(win),
				rowsBackgroundGenerated->pixels,
				rowsBackgroundGenerated->pitch);
		backgourndTexture = SDL_CreateTextureFromSurface(ren,	rowsBackgroundGenerated);
	}
	temp = true;
}

void frogger_sdl::WindowSDL::drawLineUnder(frogger::MenuButton* mode,
		frogger::MenuButton* numPlay, frogger::MenuButton* diff)
{
	SDL_Texture* line=sdldata->getLine();
	//int x, int y,	int* w, int h, int angle
	int w;
	sdldata->renderTexture(line, sdldata->getRen(),	mode->getX()-mode->getH(), mode->getY(), &w, mode->getH(), 0,true);
	sdldata->renderTexture(line, sdldata->getRen(),	diff->getX()-diff->getH(), diff->getY(), &w, diff->getH(), 0,true);
	sdldata->renderTexture(line, sdldata->getRen(),	numPlay->getX()-numPlay->getH(), numPlay->getY(), &w, numPlay->getH(), 0,true);


}
