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
	std::vector<int> lane1Ratio={40,5,10};
	std::vector<int> lane2Ratio={1};
	std::vector<int> obs1Ratio={1};
	std::vector<int> obs2Ratio={1};
	std::vector<int> obs3Ratio={1};
	std::vector<int> item1Ratio={1};
	std::vector<int> player1Ratio={1,0};
	vector<SDL_Texture*> lane1;
	//vector<SDL_Texture*> lane2;
	vector<SDL_Texture*> obst1;
	vector<SDL_Texture*> obst2;
	vector<SDL_Texture*> obst3;
	vector<SDL_Texture*> item1;
	vector<SDL_Texture*> player1;


	string imagePathBack ="C:/frogger/background.png";
	string playerPath1 ="C:/frogger/frog1.png";
	string playerPath2 ="C:/frogger/frog2.png";
	string imagePathEnemy1 ="C:/frogger/enemy1.png";
	string imagePathEnemy2 ="C:/frogger/enemy2.png";
	string imagePathEnemy3 ="C:/frogger/enemy3.png";
	string imagePathLane1 ="C:/frogger/lane1.png";
	string imagePathLane2 ="C:/frogger/lane2.png";
	string imagePathLane3 ="C:/frogger/lane3.png";
	string imagePathBackground1 ="C:/frogger/back1.png";
	string imagePathBackground2 ="C:/frogger/back2.png";
	string imagePathBackground3 ="C:/frogger/back3.png";
	string imagePathItem ="C:/frogger/item.png";

	backgroundTex=IMG_LoadTexture(re, imagePathBack.c_str());
	backTex.push_back(IMG_LoadTexture(re, imagePathBackground1.c_str()));
	backTex.push_back(IMG_LoadTexture(re, imagePathBackground2.c_str()));
	backTex.push_back(IMG_LoadTexture(re, imagePathBackground3.c_str()));

	playerTex.push_back((IMG_LoadTexture(re, playerPath1.c_str())));
	playerTex.push_back((IMG_LoadTexture(re, playerPath2.c_str())));
	ObstTex.push_back(IMG_LoadTexture(re, imagePathEnemy1.c_str()));
	ObstTex.push_back(IMG_LoadTexture(re, imagePathEnemy2.c_str()));
	ObstTex.push_back(IMG_LoadTexture(re, imagePathEnemy3.c_str()));
	laneTex.push_back(IMG_LoadTexture(re, imagePathLane1.c_str()));
	laneTex.push_back(IMG_LoadTexture(re, imagePathLane2.c_str()));
	laneTex.push_back(IMG_LoadTexture(re, imagePathLane3.c_str()));
	itemTex.push_back(IMG_LoadTexture(re, imagePathItem.c_str()));

	player1.push_back((IMG_LoadTexture(re, playerPath1.c_str())));
	player1.push_back((IMG_LoadTexture(re, playerPath2.c_str())));
	obst1.push_back(IMG_LoadTexture(re, imagePathEnemy1.c_str()));
	obst2.push_back(IMG_LoadTexture(re, imagePathEnemy2.c_str()));
	obst3.push_back(IMG_LoadTexture(re, imagePathEnemy3.c_str()));
	lane1.push_back(IMG_LoadTexture(re, imagePathLane1.c_str()));
	lane1.push_back(IMG_LoadTexture(re, imagePathLane2.c_str()));
	lane1.push_back(IMG_LoadTexture(re, imagePathLane3.c_str()));
	item1.push_back(IMG_LoadTexture(re, imagePathItem.c_str()));

	Animator obs1Ani(obst1,obs1Ratio);
	Animator obs2Ani(obst2,obs2Ratio);
	Animator obs3Ani(obst3,obs3Ratio);
	Animator lane1Ani(lane1,lane1Ratio);
	Animator item1Ani(item1,item1Ratio);
	Animator player1Ani(player1,player1Ratio);

	obstiAni={obs1Ani,obs2Ani,obs3Ani};
	laneAni={lane1Ani};
	playerAni={player1Ani};
	itemAni={item1Ani};
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
	return laneAni.front();
}

Animator SDLdata::getObstiAni() {
	return obstiAni.front();
}

Animator SDLdata::getPlayerAni() {
	return playerAni.front();
}
