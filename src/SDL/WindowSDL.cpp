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


WindowSDL::WindowSDL(SDLdata* sdldata):sdldata(sdldata), ren(NULL),win(NULL)
{

		White = {255, 255, 255,255};
		Black = {0, 0, 0,0};
}

WindowSDL::~WindowSDL() {
	TTF_CloseFont(Sans);
}

void WindowSDL::makeWindow(int ScreenWidth, int ScreenHeight,int dataWindowHeight,char const* title)
{
	setProp(ScreenWidth,ScreenHeight,dataWindowHeight,title);
	sdldata->setScreenDimension(ScreenWidth,ScreenHeight,dataWindowHeight);
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init() ;
	win = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC );
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
void WindowSDL::generateBackground(vector<Row*>* rows)
{
	if (rowsBackgroundGenerated==nullptr)
	{
		std::vector<SDL_Texture*> backTextures=sdldata->getBackTextures();
		for(Row* row:*rows)
		{
			int numberOfRows=(sdldata->getScreenHeight()/row->getHeight())-1;
			int y=row->getLocY();
			int height=row->getHeight();
			int x=0,width=0;
			int textureLocation=row->isLaneRow()?1:0;
			textureLocation=(row->getNumber()==0)||(row->getNumber()==numberOfRows)?2:textureLocation;
			sdldata->getDependWAndH(backTextures.at(textureLocation),&width,&height);

			while(x<=getWidth())
			{
				sdldata->renderTexture(backTextures.at(textureLocation),ren,x,y,&width,&height,0);
				x=x+width;
			}
		}
			saveCurrentWindowImage();
	}
	else
	{
		sdldata->renderTexture(backgourndTexture,ren,0,0,&WIDTH,&HEIGHT,0);

	}
}
void WindowSDL::dislayData(int score,int life,int projectiles,int time)
{
//auto start_time=chrono::steady_clock::now();

	if(valueChanged(score, life, projectiles, time)&&!(surfaceMessage==nullptr))
	{
		SDL_FreeSurface(surfaceMessage);
		SDL_DestroyTexture(Message);
		 TTF_CloseFont(Sans);
		 Sans=nullptr;
		surfaceMessage=nullptr;
		Message=nullptr;
	}

	string scoreS = to_string(score);
	string lifeS = to_string(life);
	string projS = to_string(projectiles);
	string timeS=to_string(time);
	string text="Score: "+scoreS+" lives: "+lifeS+" Projectiles: "+projS+" time: "+timeS;

	if(surfaceMessage==nullptr)
	{
		Sans = TTF_OpenFont("c:\\sans.ttf", 40);
	surfaceMessage =  TTF_RenderText_Blended(Sans, text.c_str(), Black);
	Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
	}


	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 0;//WIDTH/2;  //controls the rect's x coordinate
	Message_rect.y = HEIGHT-dataWindowHeight; // controls the rect's y coordinte
	Message_rect.w = WIDTH/2; // controls the width of the rect
	Message_rect.h = dataWindowHeight; // controls the height of the rect

	SDL_RenderCopyEx(ren, Message, NULL, &Message_rect,0,NULL,SDL_FLIP_NONE);

	setOldParameters(score,life,projectiles, time);
	//auto end_time=chrono::steady_clock::now();
	//cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << endl;
}
void WindowSDL::setBackground()
{
	sdldata->renderTexture(sdldata->getBackgroundTexture(),sdldata->getRen(),0,0,&WIDTH,&HEIGHT,0);
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

void WindowSDL::displayHighScore(int score1, int score2, int score3,
		int score4) {
	string scoreS = to_string(score1);
		string lifeS = to_string(score2);
		string projS = to_string(score3);
		string timeS=to_string(score4);
		string text="HighScore1: "+scoreS+" HighScore2: "+lifeS+" HighScore3: "+projS+"      your score: "+timeS;


		TTF_Font* Sans = TTF_OpenFont("c:\\sans.ttf", 60);
		SDL_Color White = {255, 255, 255,255};
		SDL_Color Black = {0, 0, 0,0};

		//auto start_time=chrono::steady_clock::now();
		SDL_Surface* surfaceMessage =  TTF_RenderText_Blended(Sans, text.c_str(), White);
		//auto end_time=chrono::steady_clock::now();
		SDL_Texture* Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);


		SDL_Rect Message_rect; //create a rect
		Message_rect.x = 0;//WIDTH/2;  //controls the rect's x coordinate
		Message_rect.y = HEIGHT-dataWindowHeight; // controls the rect's y coordinte
		Message_rect.w = WIDTH; // controls the width of the rect
		Message_rect.h = dataWindowHeight; // controls the height of the rect



		SDL_RenderCopyEx(ren, Message, NULL, &Message_rect,0,NULL,SDL_FLIP_NONE);
		TTF_CloseFont(Sans);
		SDL_FreeSurface(surfaceMessage);
		SDL_DestroyTexture(Message);
}

void WindowSDL::saveCurrentWindowImage() {
	   rowsBackgroundGenerated = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);

	   if(rowsBackgroundGenerated)
	   {
	      SDL_RenderReadPixels(ren, NULL, SDL_GetWindowPixelFormat(win), rowsBackgroundGenerated->pixels, rowsBackgroundGenerated->pitch);
	      backgourndTexture=SDL_CreateTextureFromSurface(ren,rowsBackgroundGenerated);
	   }
	   temp=true;
}
