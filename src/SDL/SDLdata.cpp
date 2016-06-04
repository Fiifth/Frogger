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
using namespace frogger_sdl;

SDLdata::SDLdata()
{
}
SDLdata::~SDLdata()
{
	deleteTextures(menuTextures);
	deleteTextures(backTex);
	deleteTextures(animatorTexCollection);
}

void SDLdata::renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y,
		int* w, int h, int angle, bool ratio)
{
	if (ratio)
		*w = getDW(tex, h);

	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = *w;
	dst.h = h;

	SDL_RendererFlip temp = SDL_FLIP_NONE;
	if (angle == 1)
	{
		temp = SDL_FLIP_HORIZONTAL;
		angle = 0;
	}
	SDL_RenderCopyEx(ren, tex, NULL, &dst, angle, NULL, temp);
}
int SDLdata::getDW(SDL_Texture* tex, int h)
{
	int aQ, wQ, hQ;
	Uint32 fQ;
	SDL_QueryTexture(tex, &fQ, &aQ, &wQ, &hQ);
	return (float) (((float) h) / (float) hQ) * wQ;;
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
	SDL_RenderCopy(re, texB, NULL, NULL);
}
void SDLdata::updateScreen()
{
	SDL_RenderPresent(re);
}
void SDLdata::createTextures()
{
	std::string path = "C:/frogger/menu/";

	SDL_Texture* B = IMG_LoadTexture(re, (path + "B.png").c_str());
	SDL_Texture* BH = IMG_LoadTexture(re, (path + "BH.png").c_str());
	SDL_Texture* BHE = IMG_LoadTexture(re, (path + "BHE.png").c_str());
	SDL_Texture* BQ = IMG_LoadTexture(re, (path + "BQ.png").c_str());
	SDL_Texture* BS = IMG_LoadTexture(re, (path + "BS.png").c_str());
	SDL_Texture* BST = IMG_LoadTexture(re, (path + "BST.png").c_str());
	SDL_Texture* G = IMG_LoadTexture(re, (path + "G.png").c_str());
	SDL_Texture* GM = IMG_LoadTexture(re, (path + "GM.png").c_str());
	SDL_Texture* GR = IMG_LoadTexture(re, (path + "GR.png").c_str());
	SDL_Texture* H = IMG_LoadTexture(re, (path + "H.png").c_str());
	SDL_Texture* HB = IMG_LoadTexture(re, (path + "HB.png").c_str());
	SDL_Texture* S = IMG_LoadTexture(re, (path + "S.png").c_str());
	SDL_Texture* SB = IMG_LoadTexture(re, (path + "SB.png").c_str());
	SDL_Texture* V = IMG_LoadTexture(re, (path + "V.png").c_str());
	SDL_Texture* VM = IMG_LoadTexture(re, (path + "VM.png").c_str());
	SDL_Texture* VN = IMG_LoadTexture(re, (path + "VN.png").c_str());
	menuTextures=
	{	B,BH,BHE,BQ,BS,BST,G,GM,GR,H,HB,S,SB,V,VM,VN};
	line = IMG_LoadTexture(re, (path + "line.png").c_str());

	std::string imagePathBackground1 = "C:/frogger/back1.png";
	std::string imagePathBackground2 = "C:/frogger/back2.png";
	std::string imagePathBackground3 = "C:/frogger/back3.png";

	backTex.push_back(IMG_LoadTexture(re, imagePathBackground1.c_str()));
	backTex.push_back(IMG_LoadTexture(re, imagePathBackground2.c_str()));
	backTex.push_back(IMG_LoadTexture(re, imagePathBackground3.c_str()));

	obstiAni=
	{
		getAnimator(
				{	"o1.png"},
				{	0}),
		getAnimator(
				{	"o2.png"},
				{	0}),
		getAnimator(
				{	"o3.png"},
				{	0}),
		getAnimator(
				{	"o4.png"},
				{	0}),
		getAnimator(
				{	"o5.png"},
				{	0}),
		getAnimator(
				{	"o6.png"},
				{	0}),
		getAnimator(
				{	"o7.png"},
				{	0}),
		getAnimator(
				{	"o8.png"},
				{	0}),
		getAnimator(
				{	"o9.png"},
				{	0}),
		getAnimator(
				{	"o10.png"},
				{	0}),
		getAnimator(
				{	"o11.png"},
				{	0}),
		getAnimator(
				{	"o12.png"},
				{	0}),
		getAnimator(
				{	"o13.png"},
				{	0})
	};
	laneAni=
	{
		getAnimator(
				{	"lane1.png","lane2.png","lane3.png"},
				{	40,5,10}),
		getAnimator(
				{	"lane4.png"},
				{	0}),
		getAnimator(
				{	"o13.png"},
				{	0}),
		getAnimator(
				{	"turtle1.png","turtle2.png"},
				{	20,20}),
		getAnimator(
				{	"lane5.png"},
				{	0}),
		getAnimator(
				{	"turtle1.png","turtle2.png","turtle1.png","turtle2.png","turtle3.png","turtle4.png","turtle5.png","turtle6.png" ,"turtle4.png","turtle3.png"},
				{	40,40,40,40,30,20,20,-70,10,20})
	};
	itemAni=
	{
		getAnimator(
				{	"item1.png"},
				{	0}),
		getAnimator(
				{	"item2.png"},
				{	0}),
		getAnimator(
				{	"item3.png"},
				{	0})
	};
	playerAni=
	{
		getAnimator(
				{	"frog1.png","frog2.png"},
				{	1,0}),
		getAnimator(
				{	"frog3.png","frog4.png"},
				{	1,0})
	};
	projAni=
	{
		getAnimator(
				{	"proj.png"},
				{	0})
	};

}



std::vector<SDL_Texture*> SDLdata::getBackTextures()
{
	return backTex;
}

void SDLdata::setScreenDimension(int* gameWidth, int* gameHeight)
{
	screenHeight = gameHeight;
	screenWidth = gameWidth;
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
	return playerAni.at(ind);
}

Animator SDLdata::getAnimator(std::vector<std::string> paths,	std::vector<int> ratio)
{
	std::vector<SDL_Texture*> textures;
	std::string dir = "C:/frogger/";
	for (std::string temp : paths)
	{
		textures.push_back(IMG_LoadTexture(re, (dir + temp).c_str()));
		animatorTexCollection.push_back(textures.back());
	}
	Animator temp(textures, ratio);
	return temp;
}

int* SDLdata::getScrH() const
{
	return screenHeight;
}

void SDLdata::setScreenHeight(int* screenHeight)
{
	this->screenHeight = screenHeight;
}

int* SDLdata::getScrW() const
{
	return screenWidth;
}

void SDLdata::setScreenWidth(int* screenWidth)
{
	this->screenWidth = screenWidth;
}

Animator SDLdata::getProjAni(int ind)
{
	return projAni.at(ind);
}

std::vector<SDL_Texture*>* frogger_sdl::SDLdata::getMenuTextures()
{
	return &menuTextures;
}

SDL_Texture* frogger_sdl::SDLdata::getLine()
{
	return line;
}

void frogger_sdl::SDLdata::deleteTextures(std::vector<SDL_Texture*> textureVector)
{
	for(SDL_Texture* tex:textureVector)
		SDL_DestroyTexture(tex);
}

