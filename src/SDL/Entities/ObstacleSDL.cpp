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
using namespace frogger_sdl;

using namespace std;

ObstacleSDL::ObstacleSDL(SDLdata* sdldata, frogger::Row* row, frogger::Factory* F,bool visible, int x, int y,
		int w, int h) :
		sdldata(sdldata)
{
	setVisible(visible);
	setF(F);
	int ind=row->getRandomObsInd();
	ani = sdldata->getObstiAni(ind).clone();
	setRow(row);
	setProperties();
	this->x=x;
	setSize(0, h);
	setScreenSize(sdldata->getScreenWidth(), sdldata->getScreenHeight());
	int wn = 0, hn = h;
	wn=sdldata->getDependW(ani->getTexture(), wn, hn);
	setSize(wn, hn);

	setYPointer(row->getYP());
	previousX = x;
}

ObstacleSDL::~ObstacleSDL()
{
	delete (ani);
}

void ObstacleSDL::draw()
{
	if (isVisible())
	{

		int angle = 0;
		angle = row->isDirLeft() ? 1 : 0;
		sdldata->renderTexture(ani->getTexture(), sdldata->getRen(), x, *y, &w,
				h, angle);
		if (ani->isTurned() && !turned)
		{
			isTurenedByAni = true;
			turned = true;
		}
		else if (isTurenedByAni && turned)
		{
			turned = false;
		}
	}
	projectileList.remove_if(drawMoveRemove());
}

ObstacleSDL::ObstacleSDL(SDLdata* sdldata, frogger::Row* row, frogger::Factory* F,bool visible) :
		sdldata(sdldata)
{
	setVisible(visible);
	setF(F);
	int ind=row->getRandomObsInd();
	ani = sdldata->getObstiAni(ind).clone();
	setRow(row);
	setProperties();
	setSize(0, row->getHeight());
	setScreenSize(sdldata->getScreenWidth(), sdldata->getScreenHeight());
	int wn = 0, hn = row->getHeight();
	wn=sdldata->getDependW(ani->getTexture(), wn, hn);
	setSize(wn, hn);
	int xloc = row->isDirLeft() ? screenWidth : -getW();
	this->x=xloc;
	previousX = x;

}
