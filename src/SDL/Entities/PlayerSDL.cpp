/*
 * FrogSDL.cpp
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */

#include "PlayerSDL.h"
using namespace frogger_sdl;

frogger_sdl::PlayerSDL::PlayerSDL(SDLdata* sdldata):sdldata(sdldata)
{
	playerTex=sdldata->getTextureVector('P');
}

PlayerSDL::~PlayerSDL()
{
}

void PlayerSDL::draw()
{
	if (!isDead())
	{
		int angle = 0;
		angle = (getDirection() == 'R') ? 90 : angle;
		angle = (getDirection() == 'D') ? 180 : angle;
		angle = (getDirection() == 'L') ? 270 : angle;

		if (moved)
		{
			ani->setCurrentTextureFor(1, 10);
			moved = false;
		}
		sdldata->renderTexture(playerTex->at(ani->getIndex()), sdldata->getRen(), x, *y, &w, h, angle, true);
		projectileList.remove_if(drawMoveRemove());
	}
}

