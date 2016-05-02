/*
 * FrogSDL.cpp
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */

#include "PlayerSDL.h"
#include <iostream>
#include "SDL.h"
#include "Window.h"
#include "Animator.h"
#include <vector>
#include "Projectile.h"
using namespace frogger;

using namespace std;

PlayerSDL::PlayerSDL(SDLdata* sdldata, Factory* F, int x, int y, int w, int h,
		int speedH, int speedV, int number) :
		sdldata(sdldata), textures(sdldata->getPlayerTextures())

{
	setF(F);
	ani = sdldata->getPlayerAni(number).clone();
	sethSpeed(speedH);
	setvSpeed(speedV);
	setSize(w, h);
	setLocation(x, y);
	setStartPosition(x, y);
	setScreenSize(sdldata->getScreenWidth(), sdldata->getScreenHeight());
}

PlayerSDL::~PlayerSDL()
{
}

void PlayerSDL::draw()
{
	if (!isDead())
	{
		//int direction=0;//1=up,2=right,3=down,4=left;
		int angle = 0;
		angle = (getDirection() == 2) ? 90 : angle;
		angle = (getDirection() == 3) ? 180 : angle;
		angle = (getDirection() == 4) ? 270 : angle;

		if(moved)
		{
			ani->setCurrentTextureFor(1,10);
			moved=false;
		}
		sdldata->renderTexture(ani->getTexture(), sdldata->getRen(), x, y, &w,
				&h, angle);
		projectileList.remove_if(drawMoveRemove());

	}
}

