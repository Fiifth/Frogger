/*
 * SDLstuff.cpp
 *
 *  Created on: 7-mrt.-2016
 *      Author: msn-w
 */

#include <SDLdata.h>
#include <string>
#include <SDL_image.h>
#include <iostream>
#include <stdlib.h>
#include "Animator.h"
SDL_Renderer* re;

SDLdata::SDLdata()
{
	screenWidth=640;
	screenHeight=480;
	re=NULL;
	backgroundTex=NULL;
}

using namespace std;
SDLdata::~SDLdata() {}


void SDLdata::renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y, int* w, int* h,int angle){
	int aQ,wQ,hQ;
	Uint32 fQ;
	SDL_QueryTexture(tex, &fQ,&aQ,&wQ,&hQ);

	if(*w==0)
	{
		*w=(float)(((float)*h)/(float)hQ)*wQ;
	}
	else if (*h==0)
	{
		*h=(float)(((float)*w)/(float)wQ)*hQ;
	}
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = *w;
	dst.h = *h;

	SDL_RendererFlip temp=SDL_FLIP_NONE;
	if (angle==1)
	{
	temp=SDL_FLIP_HORIZONTAL;
	angle=0;
	}
	SDL_RenderCopyEx(ren, tex, NULL, &dst,angle,NULL,temp);
	}
void SDLdata::getDependWAndH(SDL_Texture* tex,int* w, int* h)
{
	int aQ,wQ,hQ;
	Uint32 fQ;
	SDL_QueryTexture(tex, &fQ,&aQ,&wQ,&hQ);

	if(*w==0)
	{
		*w=(float)(((float)*h)/(float)hQ)*wQ;
	}
	else if (*h==0)
	{
		*h=(float)(((float)*w)/(float)wQ)*hQ;
	}
}
SDL_Renderer* SDLdata::getRen()
{
	return re;
}
void SDLdata::setRen(SDL_Renderer* rende)
{
	re=rende;
}
void SDLdata::setBackground(SDL_Texture* texB)
{
	SDL_RenderClear(re);
	SDL_RenderCopy(re, texB, NULL, NULL);
}
void SDLdata::updateScreen()
{
	SDL_RenderPresent(re);
}
void SDLdata::createTextures()
{

	string imagePathBack ="C:/frogger/background.png";
	string imagePathBackground1 ="C:/frogger/back1.png";
	string imagePathBackground2 ="C:/frogger/back2.png";
	string imagePathBackground3 ="C:/frogger/back3.png";

	backgroundTex=IMG_LoadTexture(re, imagePathBack.c_str());
	backTex.push_back(IMG_LoadTexture(re, imagePathBackground1.c_str()));
	backTex.push_back(IMG_LoadTexture(re, imagePathBackground2.c_str()));
	backTex.push_back(IMG_LoadTexture(re, imagePathBackground3.c_str()));

	obstiAni={getAnimator({"C:/frogger/enemy1.png"},{1}),getAnimator({"C:/frogger/enemy2.png"},{1}),getAnimator({"C:/frogger/enemy3.png"},{1})};
	laneAni={getAnimator({"C:/frogger/lane1.png","C:/frogger/lane2.png","C:/frogger/lane3.png"},{40,5,10})};
	itemAni={getAnimator({"C:/frogger/item.png"},{1})};
	playerAni={getAnimator({"C:/frogger/frog1.png","C:/frogger/frog2.png"},{1,0})};

}

SDL_Texture* SDLdata::getBackgroundTexture()
{
	return backgroundTex;
}

std::vector<SDL_Texture*> SDLdata::getPlayerTextures() {
	return playerTex;
}

std::vector<SDL_Texture*> SDLdata::getObstTextures() {
	return ObstTex;
}

std::vector<SDL_Texture*> SDLdata::getItemTextures() {
	return itemTex;
}

std::vector<SDL_Texture*> SDLdata::getLaneTextures() {
	return laneTex;
}

std::vector<SDL_Texture*> SDLdata::getBackTextures() {
	return backTex;
}

void SDLdata::setScreenDimension(int width,int height,int dataWindowHeight)
{
	screenHeight=height-dataWindowHeight;
	screenWidth=width;
}

Animator SDLdata::getItemAni() {
	return itemAni.front();
}

Animator SDLdata::getLaneAni() {
	return laneAni.at(rand()%laneAni.size());
}

Animator SDLdata::getObstiAni() {
	return obstiAni.at(rand()%obstiAni.size());
}

Animator SDLdata::getPlayerAni() {
	return playerAni.front();
}

Animator SDLdata::getAnimator(std::vector<std::string> paths,std::vector<int> ratio)
{
	vector<SDL_Texture*> textures;
	for(string temp:paths)
	{
		textures.push_back(IMG_LoadTexture(re, temp.c_str()));
	}
	Animator temp(textures,ratio);
	return temp;
}
