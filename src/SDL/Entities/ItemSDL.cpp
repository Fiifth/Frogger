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
	setProperties(row,sdldata->getScrW(), sdldata->getScrH(),x,sdldata->getDW(ani->getTex(), row->getHeight()),true);
}

ItemSDL::~ItemSDL()
{
	delete (ani);
}

void ItemSDL::draw()
{
	int angle = 0;
	angle = row->isDirLeft() ? 1 : 0;
	sdldata->renderTexture(ani->getTex(), sdldata->getRen(), x,*y, &w, h,
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
	int wi=sdldata->getDW(ani->getTex(), row->getHeight());
	setProperties(row,sdldata->getScrW(), sdldata->getScrH(), row->isDirLeft() ? *sdldata->getScrW() : -wi,wi,visible);

}
