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
	White =
	{	255, 255, 255,255};
	Black =
	{	0, 0, 0,0};
}

WindowSDL::~WindowSDL()
{
	TTF_CloseFont(Sans);
}

void WindowSDL::makeWindow(int ScreenWidth, int ScreenHeight,
		int dataWindowHeight, char const* title)
{
	setProp(ScreenWidth, ScreenHeight, dataWindowHeight, title);
	sdldata->setScreenDimension(ScreenWidth, ScreenHeight, dataWindowHeight);
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	win = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	ren = SDL_CreateRenderer(win, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	//
	sdldata->setRen(ren);
	sdldata->createTextures();
	updateScreen();
	//startP = chrono::high_resolution_clock::now();
	//SDL_RenderPresent(ren);
	//SDL_RenderPresent(ren);
	//endP = chrono::high_resolution_clock::now();
	//int difference=std::chrono::duration_cast<std::chrono::milliseconds>(endP- startP).count();
	//cout<<difference<<endl;

}
void WindowSDL::generateBackground(vector<frogger::Row*>* rows)
{
	bool changed=false;
	unsigned int i=0;
	if(rowsBackgroundGenerated != nullptr)
	{
		if(rows->size()==rowsOld.size())
		{
			for (i =0;i<rows->size();i++)
			{
				bool temp=rows->at(i)->getLocY()==rowsOld.at(i)->getLocY();
				changed=temp?changed:true;
				temp=rows->at(i)->getType()==rowsOld.at(i)->getType();
				changed=temp?changed:true;
			}
		}
		else
			changed=true;
	}
	//	changed=true;
	if (rowsBackgroundGenerated == nullptr||changed)
	{
		rowsOld.clear();
		setBackground('A');
		std::vector<SDL_Texture*> backTextures = sdldata->getBackTextures();
		for (frogger::Row* row : *rows)
		{
			rowsOld.push_back(row->clone());
			int y = row->getLocY();
			int height = row->getHeight();
			//int x = 0-rand()%20, width = 0;
			int x = 0, width = 0;
			int textureLocation = row->getType()=='C' ? 1 : 0;
			textureLocation =row->getType()=='A'|| row->getType()=='E'|| row->getType()=='D' ?2 : textureLocation;
			sdldata->getDependWAndH(backTextures.at(textureLocation), &width,
					&height);

			while (x <= getWidth())
			{
				sdldata->renderTexture(backTextures.at(textureLocation), ren, x,
						y, &width, &height, 0);
				x = x + width;
			}
		}

		saveCurrentWindowImage();
	}
	else
	{
		sdldata->renderTexture(backgourndTexture, ren, 0, 0, &WIDTH, &HEIGHT, 0);

	}
}
void WindowSDL::dislayData(list<frogger::Player*>* players)
{
//auto start_time=chrono::steady_clock::now();
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
		TTF_CloseFont(Sans);
		Sans = nullptr;
		surfaceMessage = nullptr;
		Message = nullptr;
	}


	if (surfaceMessage == nullptr)
	{
		Sans = TTF_OpenFont("c:\\sans.ttf", 40);
		//surfaceMessage = TTF_RenderText_Blended(Sans, newString.c_str(), Black);
		surfaceMessage=TTF_RenderText_Shaded(Sans,newString.c_str(),Black,White);
		Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
	}

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 0; //WIDTH/2;  //controls the rect's x coordinate
	Message_rect.y = HEIGHT - dataWindowHeight; // controls the rect's y coordinte
	Message_rect.w = WIDTH; // controls the width of the rect
	Message_rect.h = dataWindowHeight; // controls the height of the rect

	SDL_RenderCopyEx(ren, Message, NULL, &Message_rect, 0, NULL, SDL_FLIP_NONE);

	oldString=newString;

}
void WindowSDL::setBackground(char state)
{
	SDL_Texture* temp;
	if (state=='A')
		temp=sdldata->getBackgroundTexture();
	else if (state=='B')
		temp=sdldata->getStartSelTex();
	else if (state=='C')
		temp=sdldata->getHighSelTex();
	else if (state=='D')
		temp=sdldata->getQuitSelTex();
	else if (state=='E')
			temp=sdldata->getHighScoreTex();
	else if (state=='F')
		temp=sdldata->getHighScoreBackSel();

	sdldata->renderTexture(temp, sdldata->getRen(),	0, 0, &WIDTH, &HEIGHT, 0);
}
void WindowSDL::updateScreen()
{
	//int correction=0;
	//endP = chrono::high_resolution_clock::now();
	//int difference=std::chrono::duration_cast<std::chrono::milliseconds>(endP- startP).count();
	//while(difference<15)
	//{
	//correction++;
	//int delay=((15-difference))>=0?((15-difference)):0;
	//int delay=((19-difference))>=0?(ceil((19-(float)difference)/2)):0;
	//SDL_Delay(delay);
	//endP = chrono::high_resolution_clock::now();
	//difference=std::chrono::duration_cast<std::chrono::milliseconds>(endP- startP).count();
	//}
	//cout<<difference-15<<":"<<correction<<endl;
	//startP = chrono::high_resolution_clock::now();
	SDL_RenderPresent(ren);

}

void WindowSDL::displayHighScore(int score1, int score2, int score3, int score4)
{
	string scoreS = to_string(score1);
	string lifeS = to_string(score2);
	string projS = to_string(score3);
	string timeS = to_string(score4);
	string text = "HighScore1: " + scoreS + " HighScore2: " + lifeS
			+ " HighScore3: " + projS + "      your score: " + timeS;

	TTF_Font* Sans = TTF_OpenFont("c:\\sans.ttf", 60);
	SDL_Color White ={ 255, 255, 255, 255 };
	SDL_Color Black ={ 0, 0, 0, 0 };

	//auto start_time=chrono::steady_clock::now();
	SDL_Surface* surfaceMessage = TTF_RenderText_Blended(Sans, text.c_str(),
			White);
	//auto end_time=chrono::steady_clock::now();
	SDL_Texture* Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 0; //WIDTH/2;  //controls the rect's x coordinate
	Message_rect.y = HEIGHT - dataWindowHeight; // controls the rect's y coordinte
	Message_rect.w = WIDTH; // controls the width of the rect
	Message_rect.h = dataWindowHeight; // controls the height of the rect

	SDL_RenderCopyEx(ren, Message, NULL, &Message_rect, 0, NULL, SDL_FLIP_NONE);
	TTF_CloseFont(Sans);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}

void WindowSDL::saveCurrentWindowImage()
{
	rowsBackgroundGenerated = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32,
			0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);

	if (rowsBackgroundGenerated)
	{
		SDL_RenderReadPixels(ren, NULL, SDL_GetWindowPixelFormat(win),
				rowsBackgroundGenerated->pixels,
				rowsBackgroundGenerated->pitch);
		backgourndTexture = SDL_CreateTextureFromSurface(ren,
				rowsBackgroundGenerated);
	}
	temp = true;
}
