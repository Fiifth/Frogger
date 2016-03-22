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
SDL_Renderer* re;

SDLdata::SDLdata()
{
	screenWidth=640;
	screenHeight=480;
	re=NULL;
	backgroundTex=NULL;

}

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
	SDL_RenderCopyEx(ren, tex, NULL, &dst,angle,NULL,SDL_FLIP_NONE);
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
	std::string imagePathBack ="C:/frogger/background.png";
	backgroundTex=IMG_LoadTexture(re, imagePathBack.c_str());

	std::string imagePath ="C:/frogger/frog1.png";
	playerTex.push_back((IMG_LoadTexture(re, imagePath.c_str())));
	std::string imagePath2 ="C:/frogger/frog2.png";
	playerTex.push_back((IMG_LoadTexture(re, imagePath2.c_str())));

	std::string imagePathEnemy ="C:/frogger/enemy1.png";
	ObstTex.push_back(IMG_LoadTexture(re, imagePathEnemy.c_str()));
	 imagePathEnemy ="C:/frogger/enemy2.png";
	ObstTex.push_back(IMG_LoadTexture(re, imagePathEnemy.c_str()));
	imagePathEnemy ="C:/frogger/enemy3.png";
	ObstTex.push_back(IMG_LoadTexture(re, imagePathEnemy.c_str()));

	std::string imagePathLane ="C:/frogger/lane1.png";
	laneTex.push_back(IMG_LoadTexture(re, imagePathLane.c_str()));
	std::string magePathLane2 ="C:/frogger/lane2.png";
		laneTex.push_back(IMG_LoadTexture(re, magePathLane2.c_str()));
	std::string imagePathItem ="C:/frogger/item.png";
	itemTex.push_back(IMG_LoadTexture(re, imagePathItem.c_str()));

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

void SDLdata::setScreenDimension(int width,int height)
{
	screenWidth=width;
	screenHeight=height;
}
