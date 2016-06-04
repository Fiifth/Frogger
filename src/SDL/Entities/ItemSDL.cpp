/*
 * ItemSDL.cpp
 *
 *  Created on: 18-mrt.-2016
 *      Author: msn-w
 */

#include <ItemSDL.h>
using namespace frogger_sdl;

ItemSDL::ItemSDL(SDLdata* sdldata, frogger::Row* row, int x, int ind) :
		sdldata(sdldata)
{
	effect = ind;
	ani = sdldata->getItemAni(ind).clone();
	setProperties(row, sdldata->getScrW(), sdldata->getScrH(), x,sdldata->getDW(ani->getTex(), row->getHeight()), true);
}

ItemSDL::~ItemSDL()
{
	delete (ani);
}

void ItemSDL::draw()
{
	sdldata->renderTexture(ani->getTex(), sdldata->getRen(), x, *y, &w, h,row->isDirLeft(), true);
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
	int wi = sdldata->getDW(ani->getTex(), row->getHeight());
	setProperties(row, sdldata->getScrW(), sdldata->getScrH(), row->isDirLeft() ? *sdldata->getScrW() : -wi, wi, visible);
}
