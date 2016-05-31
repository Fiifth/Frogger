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
	setF(F);
	int ind=row->getRandomLaneInd();
	ani = sdldata->getLaneAni(ind).clone();
	setProperties(row,sdldata->getScrW(), sdldata->getScrH(),x,sdldata->getDW(ani->getTex(), row->getHeight()),visible);
	spawnItem();

}
LaneSDL::~LaneSDL()
{
	delete (ani);
}

LaneSDL::LaneSDL(SDLdata* sdldata, frogger::Row* row, frogger::Factory* F,bool visible) :
		sdldata(sdldata)
{
	setF(F);
	ani = sdldata->getLaneAni(row->getRandomLaneInd()).clone();
	int wi=sdldata->getDW(ani->getTex(), row->getHeight());
	setProperties(row,sdldata->getScrW(), sdldata->getScrH(), row->isDirLeft() ? *sdldata->getScrW() : -wi,wi,visible);
	spawnItem();
}

void LaneSDL::draw()
{
	if (isVisible())
	{
		int angle = 0;
		angle = row->isDirLeft() ? 1 : 0;
		sdldata->renderTexture(ani->getTex(), sdldata->getRen(), x, *y, &w,
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
