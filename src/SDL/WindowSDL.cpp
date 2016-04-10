/*
 * windowSDL.cpp
 *
 *  Created on: Feb 29, 2016
 *      Author: fifth
 */

#include "WindowSDL.h"
#include <iostream>
#include "SDL.h"
#include <string>
#include "SDLdata.h"
#include <vector>
#include "SDL_ttf.h"
#include <chrono>

using namespace std;


WindowSDL::WindowSDL(SDLdata* sdldata):sdldata(sdldata), ren(NULL)
{}

WindowSDL::~WindowSDL() {
}

void WindowSDL::makeWindow(int ScreenWidth, int ScreenHeight,int dataWindowHeight,char const* title)
{
	setProp(ScreenWidth,ScreenHeight,dataWindowHeight,title);
	sdldata->setScreenDimension(ScreenWidth,ScreenHeight,dataWindowHeight);
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init() ;
	SDL_Window *win = SDL_CreateWindow(TITLE, 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	sdldata->setRen(ren);
	sdldata->createTextures();
	//setBackground();
	updateScreen();
}
void WindowSDL::generateBackground(vector<Row*>* rows)
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
}
void WindowSDL::dislayData(int score,int life,int projectiles,int time)
{

	string scoreS = to_string(score);
	string lifeS = to_string(life);
	string projS = to_string(projectiles);
	string timeS=to_string(time);
	string text="Score: "+scoreS+" lives: "+lifeS+" Projectiles: "+projS+" time: "+timeS;


	TTF_Font* Sans = TTF_OpenFont("c:\\sans.ttf", 40);
	SDL_Color White = {255, 255, 255,255};
	SDL_Color Black = {0, 0, 0,0};

	//auto start_time=chrono::steady_clock::now();
	SDL_Surface* surfaceMessage =  TTF_RenderText_Solid(Sans, text.c_str(), White);
	//auto end_time=chrono::steady_clock::now();
	SDL_Texture* Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);


	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 0;//WIDTH/2;  //controls the rect's x coordinate
	Message_rect.y = HEIGHT-dataWindowHeight; // controls the rect's y coordinte
	Message_rect.w = WIDTH/2; // controls the width of the rect
	Message_rect.h = dataWindowHeight; // controls the height of the rect



	SDL_RenderCopyEx(ren, Message, NULL, &Message_rect,0,NULL,SDL_FLIP_NONE);
	TTF_CloseFont(Sans);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
//	cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << endl;
}
void WindowSDL::setBackground()
{
	sdldata->renderTexture(sdldata->getBackgroundTexture(),sdldata->getRen(),0,0,&WIDTH,&HEIGHT,0);
}
void WindowSDL::updateScreen()
{
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
		Message_rect.y = HEIGHT/2; // controls the rect's y coordinte
		Message_rect.w = WIDTH; // controls the width of the rect
		Message_rect.h = dataWindowHeight*2; // controls the height of the rect



		SDL_RenderCopyEx(ren, Message, NULL, &Message_rect,0,NULL,SDL_FLIP_NONE);
		TTF_CloseFont(Sans);
		SDL_FreeSurface(surfaceMessage);
		SDL_DestroyTexture(Message);
}
