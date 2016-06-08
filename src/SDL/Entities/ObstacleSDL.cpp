/*
 * EnemySDL.cpp
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#include <ObstacleSDL.h>
#include <stdlib.h>
#include "SDL.h"
#include "Window.h"
#include <string>
using namespace frogger_sdl;

frogger_sdl::ObstacleSDL::ObstacleSDL(SDLdata* sdldata):sdldata(sdldata)
{
	obstTex=sdldata->getTextureVector('O');
}

ObstacleSDL::~ObstacleSDL()
{
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

void frogger_sdl::ObstacleSDL::queryW(int height)
{
	w=sdldata->getDW(obstTex->at(ani->getIndex()), height);
}
