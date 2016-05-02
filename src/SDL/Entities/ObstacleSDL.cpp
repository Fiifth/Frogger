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
	setDirection(row->isDirLeft() ? 4 : 2);
	setSpeed(row->getSpeed());
	divider = row->getDivider();
	setSize(0, h);
	setScreenSize(sdldata->getScreenWidth(), sdldata->getScreenHeight());
	int wn = 0, hn = h;
	sdldata->getDependWAndH(ani->getTexture(), &wn, &hn);
	setSize(wn, hn);
	setLocation(x, row->getLocY());
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
		sdldata->renderTexture(ani->getTexture(), sdldata->getRen(), x, y, &w,
				&h, angle);
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
	//1=up,2=right,3=down,4=left;
	setDirection(row->isDirLeft() ? 4 : 2);
	setSpeed(row->getSpeed());
	divider = row->getDivider();
	setSize(0, row->getHeight());
	setScreenSize(sdldata->getScreenWidth(), sdldata->getScreenHeight());
	int wn = 0, hn = row->getHeight();
	sdldata->getDependWAndH(ani->getTexture(), &wn, &hn);
	setSize(wn, hn);
	int xloc = row->isDirLeft() ? screenWidth : -getW();
	setLocation(xloc, row->getLocY());
	previousX = x;

}
