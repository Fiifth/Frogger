/*
 * ProjectileSDL.cpp
 *
 *  Created on: 4-apr.-2016
 *      Author: msn-w
 */

#include <ProjectileSDL.h>
using namespace frogger_sdl;

frogger_sdl::ProjectileSDL::ProjectileSDL(SDLdata* sdldata):sdldata(sdldata)
{
	projTex=sdldata->getTextureVector('B');
}

ProjectileSDL::~ProjectileSDL()
{
}

void ProjectileSDL::draw()
{
	int angle = 0;
	angle = (getDirection() == 'R') ? 90 : angle;
	angle = (getDirection() == 'D') ? 180 : angle;
	angle = (getDirection() == 'L') ? 270 : angle;
	sdldata->renderTexture(projTex->at(ani->getIndex()), sdldata->getRen(), x, *y, &w, h,	angle, true);
	if (ani->isTurned() && !turned)
	{
		isTurenedByAni = true;
		turned = true;
	}
	else if (isTurenedByAni && turned)
		turned = false;
}

void frogger_sdl::ProjectileSDL::queryW(int height)
{
	w=sdldata->getDW(projTex->at(ani->getIndex()), height);
}
