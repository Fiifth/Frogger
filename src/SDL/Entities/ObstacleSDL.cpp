/*
 * EnemySDL.cpp
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#include <ObstacleSDL.h>
#include <stdlib.h>
#include <iostream>
#include "SDL.h"
#include "Window.h"
#include <string>

using namespace std;

ObstacleSDL::ObstacleSDL(SDLdata* sdldata,Row* row,int x,int y,int w,int h) :sdldata(sdldata),textures(sdldata->getObstTextures())
{
	Animator bla=sdldata->getObstiAni();
	ani=&bla;
	setRow(row);
	setSpeed(row->getSpeed());
	setSize(0,h);
	setScreenSize(sdldata->getScreenWidth(),sdldata->getScreenHeight());
	tex=textures.at(rand()%3);
	int wn=0,hn=h;
	sdldata->getDependWAndH(tex,&wn, &hn);
	setSize(wn,hn);
	int xloc=row->isDirection()?screenWidth:-getW();
	setLocation(xloc,row->getLocY());
}

ObstacleSDL::~ObstacleSDL() {
}


void ObstacleSDL::draw()
{
	int angle=0;
	angle=row->isDirection()?1:0;
	sdldata->renderTexture(ani->getTexture(),sdldata->getRen(),x,y,&w,&h,angle);
}

ObstacleSDL::ObstacleSDL(SDLdata* sdldata, Row* row) :sdldata(sdldata),textures(sdldata->getObstTextures())
{
		ani=sdldata->getObstiAni().clone();
		setRow(row);
		setSpeed(row->getSpeed());
		setSize(0,row->getHeight());
		setScreenSize(sdldata->getScreenWidth(),sdldata->getScreenHeight());
		tex=textures.at(rand()%3);
		int wn=0,hn=row->getHeight();
		sdldata->getDependWAndH(tex,&wn, &hn);
		setSize(wn,hn);
		int xloc=row->isDirection()?screenWidth:-getW();
		setLocation(xloc,row->getLocY());
}
