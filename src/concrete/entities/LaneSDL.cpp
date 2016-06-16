/*
 * LaneSDL.cpp
 *
 *  Created on: 18-mrt.-2016
 *      Author: Kwinten
 */

#include <concrete/entities/LaneSDL.h>
using namespace frogger_sdl;

frogger_sdl::LaneSDL::LaneSDL(SDLdata* sdldata):sdldata(sdldata)
{
	laneTex=sdldata->getTextureVector('L');
}

LaneSDL::~LaneSDL()
{
}

void LaneSDL::draw()
{
	if (isVisible())
	{
		sdldata->renderTexture(laneTex->at(ani->getIndex()), sdldata->getRen(), x, *y, &w, h, row->isDirLeft(), true);

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
	itemList.remove_if(drawMoveRemove());
}

void frogger_sdl::LaneSDL::queryW(int height)
{
		w=sdldata->getDW(laneTex->at(ani->getIndex()), height);
}
