/*
 * ProjectileSDL.cpp
 *
 *  Created on: 4-apr.-2016
 *      Author: msn-w
 */

#include <ProjectileSDL.h>
using namespace frogger_sdl;

ProjectileSDL::ProjectileSDL(SDLdata* sdldata, char direction, int Xstart,int Ystart, int* Ypoint, int size, int speed, int ind) :
		sdldata(sdldata)
{
	projTex=sdldata->getTextureVector('B');
	ani = sdldata->getProjAni(ind).clone();
	directionR = direction;
	speedR = speed;
	dividerR = 0;
	this->h = size;
	queryW(h);
	setProperties(nullptr, sdldata->getScrW(), sdldata->getScrH(), Xstart,w, true);

	if (Ypoint != nullptr)
		y = Ypoint;
	else
		yR = Ystart;
}

ProjectileSDL::~ProjectileSDL()
{
	delete (ani);
}

frogger_sdl::ProjectileSDL::ProjectileSDL(SDLdata* sdldata):sdldata(sdldata)
{
	projTex=sdldata->getTextureVector('B');
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
