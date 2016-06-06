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
	obstTex=sdldata->getTextureVector('O');
	setF(F);
	int ind=row->getRandomObsInd();
	ani = sdldata->getObstiAni(ind).clone();
queryW(row->getHeight());
	setProperties(row, sdldata->getScrW(), sdldata->getScrH(), x,	w, visible);
	setPrevX();
}

ObstacleSDL::~ObstacleSDL()
{
	delete (ani);
}

frogger_sdl::ObstacleSDL::ObstacleSDL(SDLdata* sdldata):sdldata(sdldata)
{
	obstTex=sdldata->getTextureVector('O');
}

void ObstacleSDL::draw()
{
	if (isVisible())
	{
		sdldata->renderTexture(obstTex->at(ani->getIndex()), sdldata->getRen(), x, *y, &w, h, row->isDirLeft(), true);
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
	obstTex=sdldata->getTextureVector('O');
	setF(F);
	ani = sdldata->getObstiAni(row->getRandomObsInd()).clone();
	queryW(row->getHeight());
	setProperties(row, sdldata->getScrW(), sdldata->getScrH(),row->isDirLeft() ? *sdldata->getScrW() : -w, w, visible);
	setPrevX();

}

void frogger_sdl::ObstacleSDL::queryW(int height)
{
	w=sdldata->getDW(obstTex->at(ani->getIndex()), height);
}
