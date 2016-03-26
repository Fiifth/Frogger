/*
 * LaneSDL.cpp
 *
 *  Created on: 18-mrt.-2016
 *      Author: msn-w
 */

#include <LaneSDL.h>
#include "Row.h"
#include <stdlib.h>
#include <iostream>

 LaneSDL::LaneSDL(SDLdata* sdldata,Row* row,int x,int y,int w,int h) :sdldata(sdldata),textures(sdldata->getLaneTextures())
{
	setRow(row);
	setSpeed(row->getSpeed());
	setSize(0,h);
	setScreenSize(sdldata->getScreenWidth(),sdldata->getScreenHeight());
	tex=textures.at(rand()%2);
	int wn=0,hn=h;
	sdldata->getDependWAndH(tex,&wn, &hn);
	setSize(wn,hn);
	int xloc=row->isDirection()?screenWidth:-getW();
	setLocation(xloc,row->getLocY());
	ratio={0};
	ani=nullptr;
}
LaneSDL::~LaneSDL() {
	delete(ani);
}

LaneSDL::LaneSDL(SDLdata* sdldata, Row* row) :sdldata(sdldata),textures(sdldata->getLaneTextures())
{
	setRow(row);
	setSpeed(row->getSpeed());
	setSize(0,row->getHeight());
	setScreenSize(sdldata->getScreenWidth(),sdldata->getScreenHeight());
	tex=textures.at(rand()%2);
	int wn=0,hn=row->getHeight();
	sdldata->getDependWAndH(tex,&wn, &hn);
	setSize(wn,hn);
	int xloc=row->isDirection()?screenWidth:-getW();
	setLocation(xloc,row->getLocY());
	//std::vector<SDL_Texture*> textures;
	std::vector<SDL_Texture*>::const_iterator first = textures.begin();
	std::vector<SDL_Texture*>::const_iterator last = textures.begin() + 3;
	std::vector<SDL_Texture*> newVec(first, last);
	ratio={10,3,3};
	ani=new Animator(newVec,ratio);
	//TODO give animator instead of textures
	//Set animator in vector and choose random from that vector when creating object lane
}

void LaneSDL::draw()
{
	int angle=0;
	angle=row->isDirection()?1:0;
	sdldata->renderTexture(ani->getTexture(),sdldata->getRen(),x,y,&w,&h,angle);
}
