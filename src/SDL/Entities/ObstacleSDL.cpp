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

ObstacleSDL::ObstacleSDL(SDLdata* sdldata, frogger::Row* row,	frogger::Factory* F, bool visible, int x) :
		sdldata(sdldata)
{
	setF(F);
	ani = sdldata->getObstiAni(row->getRandomObsInd()).clone();
	setProperties(row, sdldata->getScrW(), sdldata->getScrH(), x,	sdldata->getDW(ani->getTex(), row->getHeight()), visible);
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
		sdldata->renderTexture(ani->getTex(), sdldata->getRen(), x, *y, &w, h, row->isDirLeft(), true);
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

ObstacleSDL::ObstacleSDL(SDLdata* sdldata, frogger::Row* row, frogger::Factory* F, bool visible) :
		sdldata(sdldata)
{
	setF(F);
	ani = sdldata->getObstiAni(row->getRandomObsInd()).clone();
	int wi = sdldata->getDW(ani->getTex(), row->getHeight());
	setProperties(row, sdldata->getScrW(), sdldata->getScrH(),row->isDirLeft() ? *sdldata->getScrW() : -wi, wi, visible);
	previousX = x;
}
