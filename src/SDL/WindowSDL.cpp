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
#include <vector>;

using namespace std;


WindowSDL::WindowSDL(SDLdata* sdldata):sdldata(sdldata), ren(NULL)
{}

WindowSDL::~WindowSDL() {
}

void WindowSDL::makeWindow(int ScreenWidth, int ScreenHeight,char const* title)
{
	setProp(ScreenWidth,ScreenHeight,title);
	sdldata->setScreenDimension(ScreenWidth,ScreenHeight);
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *win = SDL_CreateWindow(TITLE, 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	sdldata->setRen(ren);
	sdldata->createTextures();
	setBackground();
	updateScreen();
}
void WindowSDL::generateBackground(vector<Row*>* rows)
{
	std::vector<SDL_Texture*> backTextures=sdldata->getBackTextures();
	for(Row* row:*rows)
	{
		int numberOfRows=(getHeight()/row->getHeight())-1;
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
void WindowSDL::setBackground()
{
	sdldata->renderTexture(sdldata->getBackgroundTexture(),sdldata->getRen(),0,0,&WIDTH,&HEIGHT,0);
}
void WindowSDL::updateScreen()
{
	SDL_RenderPresent(ren);
}
