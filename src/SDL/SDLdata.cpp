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

using namespace frogger_sdl;

SDLdata::SDLdata()
{
}
SDLdata::~SDLdata()
{
	deleteTextures(menuTextures);
	deleteTextures(backTex);
	deleteTextures(playerTex);
	deleteTextures(ObstTex);
	deleteTextures(laneTex);
	deleteTextures(itemTex);
	deleteTextures(projTex);
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

	fillTextureVectors(&playerTex,"frog",3);
	fillTextureVectors(&ObstTex,"o",12);
	fillTextureVectors(&laneTex,"lane",9);
	fillTextureVectors(&itemTex,"item",2);
	fillTextureVectors(&projTex,"proj",0);

	obstiAni=	{getAnimator({0},{0}),getAnimator({1},{0}),getAnimator({2},{0}),
			getAnimator({3},{0}),getAnimator({4},{0}),getAnimator({5},{0}),
			getAnimator({6},{0}),getAnimator({7},{0}),getAnimator({8},{0}),
			getAnimator({9},{0}),getAnimator({10},{0}),getAnimator({11},{0})};

	laneAni={getAnimator({0,1,2},{40,5,10}),getAnimator({3},{0}),getAnimator({4,5},{20,20}),
			getAnimator({4,5,4,5,6,7,8,9,7,6},{40,40,40,40,30,20,20,-70,10,20})};

	playerAni={getAnimator({0,1},{1,0}),getAnimator({2,3},{1,0})};

	itemAni={getAnimator({0},{0}),getAnimator({1},{0}),getAnimator({2},{0})};

	projAni={getAnimator({0},{0})};


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

frogger::Animator SDLdata::getItemAni(int ind)
{
	return itemAni.at(ind);
}

frogger::Animator SDLdata::getLaneAni(int ind)
{
	return laneAni.at(ind);
}

frogger::Animator SDLdata::getObstiAni(int ind)
{
	return obstiAni.at(ind);
}

frogger::Animator SDLdata::getPlayerAni(int ind)
{
	return playerAni.at(ind);
}

frogger::Animator SDLdata::getAnimator(std::vector<int> indexes,	std::vector<int> ratio)
{
	frogger::Animator temp(indexes, ratio);
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

frogger::Animator SDLdata::getProjAni(int ind)
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

void frogger_sdl::SDLdata::fillTextureVectors(std::vector<SDL_Texture*>* textureVector, std::string prefix,	int endNumber)
{
	std::string dir = "C:/frogger/"+prefix;
		for (int i=0;i<=endNumber;i++)
		{
			std::string completeDir=dir + std::to_string(i)+".png";
			SDL_Texture* tex=IMG_LoadTexture(re, (completeDir).c_str());
			textureVector->push_back(tex);

		}



}

std::vector<SDL_Texture*>* frogger_sdl::SDLdata::getTextureVector(char type)
{
	if(type=='O')
		return &ObstTex;
	else if(type=='L')
		return &laneTex;
	else if(type=='I')
		return &itemTex;
	else if(type=='B')
		return &projTex;
	else
		return &playerTex;
}
