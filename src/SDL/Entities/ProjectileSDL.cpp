/*
 * ProjectileSDL.cpp
 *
 *  Created on: 4-apr.-2016
 *      Author: msn-w
 */

#include <ProjectileSDL.h>
#include <iostream>
using namespace frogger_sdl;


ProjectileSDL::ProjectileSDL(SDLdata* sdldata, char direction, int Xstart,
		int Ystart, int size, int speed, int ind) :
		sdldata(sdldata)
{
	//1=up,2=right,3=down,4=left;
	ani = sdldata->getProjAni(ind).clone();
	setDirection(direction);
	setSpeed(speed);
	divider = 0;
	setSize(0, size);
	setScreenSize(sdldata->getScreenWidth(), sdldata->getScreenHeight());
	int wn = 0, hn = size;
	sdldata->getDependWAndH(ani->getTexture(), &wn, &hn);
	setSize(wn, hn);
	setLocation(Xstart, Ystart);
	this->setVisible(true);
}

ProjectileSDL::~ProjectileSDL()
{
	delete (ani);
}

void ProjectileSDL::draw()
{ //int direction=0;//1=up,2=right,3=down,4=left;
	int angle = 0;
	angle = (getDirection() == 'R') ? 90 : angle;
	angle = (getDirection() == 'D') ? 180 : angle;
	angle = (getDirection() == 'L') ? 270 : angle;
	sdldata->renderTexture(ani->getTexture(), sdldata->getRen(), x, y, &w, &h,
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

