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
using namespace frogger;

SDLdata::SDLdata()
{
	screenWidth = 640;
	screenHeight = 480;
	re = NULL;
	backgroundTex = NULL;
}

using namespace std;
SDLdata::~SDLdata()
{
}

void SDLdata::renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y,
		int* w, int* h, int angle)
{
	int aQ, wQ, hQ;
	Uint32 fQ;
	SDL_QueryTexture(tex, &fQ, &aQ, &wQ, &hQ);

	if (*w == 0)
	{
		*w = (float) (((float) *h) / (float) hQ) * wQ;
	}
	else if (*h == 0)
	{
		*h = (float) (((float) *w) / (float) wQ) * hQ;
	}
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = *w;
	dst.h = *h;

	SDL_RendererFlip temp = SDL_FLIP_NONE;
	if (angle == 1)
	{
		temp = SDL_FLIP_HORIZONTAL;
		angle = 0;
	}
	SDL_RenderCopyEx(ren, tex, NULL, &dst, angle, NULL, temp);
}
void SDLdata::getDependWAndH(SDL_Texture* tex, int* w, int* h)
{
	int aQ, wQ, hQ;
	Uint32 fQ;
	SDL_QueryTexture(tex, &fQ, &aQ, &wQ, &hQ);

	if (*w == 0)
	{
		*w = (float) (((float) *h) / (float) hQ) * wQ;
	}
	else if (*h == 0)
	{
		*h = (float) (((float) *w) / (float) wQ) * hQ;
	}
}
SDL_Renderer* SDLdata::getRen()
{
	return re;
}
void SDLdata::setRen(SDL_Renderer* rende)
{
	re = rende;
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

	string imagePathBack = "C:/frogger/menu.png";
	string quitSel ="C:/frogger/quitSel.png";
	string startSel ="C:/frogger/startSel.png";
	string highSel ="C:/frogger/highSel.png";
	string HighScore="C:/frogger/highScore.png";
	string HighScoreBackSel="C:/frogger/highScoreBackSel.png";
	string imagePathBackground1 = "C:/frogger/back1.png";
	string imagePathBackground2 = "C:/frogger/back2.png";
	string imagePathBackground3 = "C:/frogger/back3.png";

	backgroundTex = IMG_LoadTexture(re, imagePathBack.c_str());
	quitSelTex = IMG_LoadTexture(re, quitSel.c_str());
	startSelTex = IMG_LoadTexture(re, startSel.c_str());
	highSelTex = IMG_LoadTexture(re, highSel.c_str());
	HighScoreTex=IMG_LoadTexture(re, HighScore.c_str());
	HighScoreBackSelTex=IMG_LoadTexture(re, HighScoreBackSel.c_str());
	backTex.push_back(IMG_LoadTexture(re, imagePathBackground1.c_str()));
	backTex.push_back(IMG_LoadTexture(re, imagePathBackground2.c_str()));
	backTex.push_back(IMG_LoadTexture(re, imagePathBackground3.c_str()));

	obstiAni=
	{
		getAnimator({"o1.png"},{1}),
		getAnimator({"o2.png"},{1}),
		getAnimator({"o3.png"},{1}),
		getAnimator({"o4.png"},{1}),
		getAnimator({"o5.png"},{1}),
		getAnimator({"o6.png"},{1}),
		getAnimator({"o7.png"},{1}),
		getAnimator({"o8.png"},{1}),
		getAnimator({"o9.png"},{1}),
		getAnimator({"o10.png"},{1}),
		getAnimator({"o11.png"},{1}),
		getAnimator({"o12.png"},{1}),
		getAnimator({"o13.png"},{1})
	};
	laneAni=
	{
			getAnimator({"lane1.png","lane2.png","lane3.png"},{40,5,10}),
			getAnimator({"lane4.png"},{1}),
			getAnimator({"o13.png"},{1}),
			getAnimator({"turtle1.png","turtle2.png"},{20,20}),
			getAnimator({"lane5.png"},{1}),
			getAnimator({"turtle1.png","turtle2.png","turtle1.png","turtle2.png","turtle3.png","turtle4.png","turtle5.png","turtle6.png" ,"turtle4.png","turtle3.png"},{40,40,40,40,20,10,10,-70,10,20})
	};
	itemAni=
	{
			getAnimator({"item.png"},{1})
	};
	playerAni=
	{
			getAnimator({"frog1.png","frog2.png"},{1,0}),
			getAnimator({"frog3.png","frog4.png"},{1,0})
	};
	projAni=
	{
			getAnimator({"proj.png"},{1})
	};

}

SDL_Texture* SDLdata::getBackgroundTexture()
{
	return backgroundTex;
}

std::vector<SDL_Texture*> SDLdata::getPlayerTextures()
{
	return playerTex;
}

std::vector<SDL_Texture*> SDLdata::getObstTextures()
{
	return ObstTex;
}

std::vector<SDL_Texture*> SDLdata::getItemTextures()
{
	return itemTex;
}

std::vector<SDL_Texture*> SDLdata::getLaneTextures()
{
	return laneTex;
}

std::vector<SDL_Texture*> SDLdata::getBackTextures()
{
	return backTex;
}

void SDLdata::setScreenDimension(int width, int height, int dataWindowHeight)
{
	screenHeight = height - dataWindowHeight;
	screenWidth = width;
}

Animator SDLdata::getItemAni(int ind)
{
	return itemAni.at(ind);
}

Animator SDLdata::getLaneAni(int ind)
{
	return laneAni.at(ind);
}

Animator SDLdata::getObstiAni(int ind)
{
	return obstiAni.at(ind);
}

Animator SDLdata::getPlayerAni(int ind)
{
	//return playerAni.at((rand()%(playerRangeEnd-playerRangeStart))+playerRangeStart);
	return playerAni.at(ind);
}

Animator SDLdata::getAnimator(std::vector<std::string> paths,
		std::vector<int> ratio)
{
	vector<SDL_Texture*> textures;
	string dir="C:/frogger/";
	for (string temp : paths)
	{
		textures.push_back(IMG_LoadTexture(re, (dir+temp).c_str()));
	}
	Animator temp(textures, ratio);
	return temp;
}

int SDLdata::getScreenHeight() const
{
	return screenHeight;
}

void SDLdata::setScreenHeight(int screenHeight)
{
	this->screenHeight = screenHeight;
}

int SDLdata::getScreenWidth() const
{
	return screenWidth;
}

void SDLdata::setScreenWidth(int screenWidth)
{
	this->screenWidth = screenWidth;
}


Animator SDLdata::getProjAni(int ind)
{
	return projAni.at(ind);
}

SDL_Texture* SDLdata::getBackgroundTex()
{
	return backgroundTex;
}

SDL_Texture* SDLdata::getHighSelTex()
{
	return highSelTex;
}

SDL_Texture* SDLdata::getQuitSelTex()
{
	return quitSelTex;
}

SDL_Texture* SDLdata::getStartSelTex()
{
	return startSelTex;
}

SDL_Texture* SDLdata::getHighScoreTex()
{
	return HighScoreTex;
}

SDL_Texture* SDLdata::getHighScoreBackSel()
{
	return HighScoreBackSelTex;
}
