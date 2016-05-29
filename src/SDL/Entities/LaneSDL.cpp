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
using namespace frogger_sdl;

LaneSDL::LaneSDL(SDLdata* sdldata, frogger::Row* row, frogger::Factory* F,bool visible, int x, int y, int w,
		int h) :
		sdldata(sdldata)
{
	setVisible(visible);
	setF(F);
	int ind=row->getRandomLaneInd();
	ani = sdldata->getLaneAni(ind).clone();
	setRow(row);
	setProperties(); //pointer: screenWidth,Height normal: visibility,factory,row,w,x
	//TODO remove h,w,visible from parameters
	this->x=x;
	setSize(0, h);
	setScreenSize(sdldata->getScreenWidth(), sdldata->getScreenHeight());
	int wn = 0, hn = h;
	wn=sdldata->getDependW(ani->getTexture(), wn, hn);
	setSize(wn, hn);
	if ((rand() % 100) <*itemRate)
	{
		spawnItem();
	}
}
LaneSDL::~LaneSDL()
{
	delete (ani);
}

LaneSDL::LaneSDL(SDLdata* sdldata, frogger::Row* row, frogger::Factory* F,bool visible) :
		sdldata(sdldata)
{
	setVisible(visible);
	setF(F);
	int ind=row->getRandomLaneInd();
	ani = sdldata->getLaneAni(ind).clone();
	setRow(row);
	setProperties();
	setSize(0, row->getHeight());
	setScreenSize(sdldata->getScreenWidth(), sdldata->getScreenHeight());
	int wn = 0, hn = row->getHeight();
	wn=sdldata->getDependW(ani->getTexture(), wn, hn);
	setSize(wn, hn);
	int xloc = row->isDirLeft() ? screenWidth : -getW();
this->x=xloc;

	if ((rand() % 100) < *itemRate)
	{
		spawnItem();
	}
}

void LaneSDL::draw()
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
	itemList.remove_if(drawMoveRemove());
}
