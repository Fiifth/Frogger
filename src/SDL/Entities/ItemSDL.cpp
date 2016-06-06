/*
 * ItemSDL.cpp
 *
 *  Created on: 18-mrt.-2016
 *      Author: msn-w
 */

#include <ItemSDL.h>
#include <iostream>
using namespace frogger_sdl;

ItemSDL::ItemSDL(SDLdata* sdldata, frogger::Row* row, int x, int ind) :
		sdldata(sdldata)
{
	itemTex=sdldata->getTextureVector('I');
	effect = ind;
	queryW(row->getHeight());
	ani = sdldata->getItemAni(ind).clone();
	setProperties(row, sdldata->getScrW(), sdldata->getScrH(), x,w, true);

}

ItemSDL::~ItemSDL()
{
	delete (ani);
}

frogger_sdl::ItemSDL::ItemSDL(SDLdata* sdldata):sdldata(sdldata)
{
	itemTex=sdldata->getTextureVector('I');
}

void ItemSDL::draw()
{
	sdldata->renderTexture(itemTex->at(ani->getIndex()), sdldata->getRen(), x, *y, &w, h,row->isDirLeft(), true);
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
	itemTex=sdldata->getTextureVector('I');
	ani = sdldata->getItemAni(ind).clone();
	queryW(row->getHeight());
	setProperties(row, sdldata->getScrW(), sdldata->getScrH(), row->isDirLeft() ? *sdldata->getScrW() : -w, w, visible);
}

void frogger_sdl::ItemSDL::queryW(int height)
{
	w=sdldata->getDW(itemTex->at(ani->getIndex()), height);
}
