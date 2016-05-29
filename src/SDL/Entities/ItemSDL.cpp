/*
 * ItemSDL.cpp
 *
 *  Created on: 18-mrt.-2016
 *      Author: msn-w
 */

#include <ItemSDL.h>
#include "Row.h"
#include <stdlib.h>
#include <iostream>
using namespace frogger_sdl;

ItemSDL::ItemSDL(SDLdata* sdldata, frogger::Row* row, int x, int y, int w, int h,
		int ind) :
		sdldata(sdldata)
{
	ani = sdldata->getItemAni(ind).clone();
	setRow(row);
	setProperties();
	this->x=x;
	setSize(0, h);
	setScreenSize(sdldata->getScreenWidth(), sdldata->getScreenHeight());
	int wn = 0, hn = h;
	wn=sdldata->getDependW(ani->getTexture(), wn, hn);
	setSize(wn, hn);
}

ItemSDL::~ItemSDL()
{
	delete (ani);
}

void ItemSDL::draw()
{
	int angle = 0;
	angle = row->isDirLeft() ? 1 : 0;
	sdldata->renderTexture(ani->getTexture(), sdldata->getRen(), x,*y, &w, h,
			angle);
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

ItemSDL::ItemSDL(SDLdata* sdldata, frogger::Row* row, int ind) :
		sdldata(sdldata)
{
	ani = sdldata->getItemAni(ind).clone();
	setRow(row);
	setProperties();
	setSize(0, row->getHeight());
	setScreenSize(sdldata->getScreenWidth(), sdldata->getScreenHeight());
	int wn = 0, hn = row->getHeight();
	wn=sdldata->getDependW(ani->getTexture(), wn, hn);
	setSize(wn, hn);
	int xloc = row->isDirLeft() ? screenWidth : -getW();
	this->x=xloc;
}
