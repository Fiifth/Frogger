/*
 * LaneSDL.cpp
 *
 *  Created on: 18-mrt.-2016
 *      Author: msn-w
 */

#include <LaneSDL.h>
using namespace frogger_sdl;

LaneSDL::LaneSDL(SDLdata* sdldata, frogger::Row* row, frogger::Factory* F,	bool visible, int x) :
		sdldata(sdldata)
{
	laneTex=sdldata->getTextureVector('L');
	setF(F);
	int ind = row->getRandomLaneInd();
	ani = sdldata->getLaneAni(ind).clone();
	queryW(row->getHeight());
	setProperties(row, sdldata->getScrW(), sdldata->getScrH(), x,w , visible);
	spawnItem();
}
LaneSDL::~LaneSDL()
{
	delete (ani);
}

LaneSDL::LaneSDL(SDLdata* sdldata, frogger::Row* row, frogger::Factory* F,
		bool visible) :
		sdldata(sdldata)
{
	laneTex=sdldata->getTextureVector('L');
	setF(F);
	int ind=row->getRandomLaneInd();
	ani = sdldata->getLaneAni(ind).clone();
	queryW(row->getHeight());
	setProperties(row, sdldata->getScrW(), sdldata->getScrH(), row->isDirLeft() ? *sdldata->getScrW() : -w, w, visible);
	spawnItem();
}

frogger_sdl::LaneSDL::LaneSDL(SDLdata* sdldata):sdldata(sdldata)
{
	laneTex=sdldata->getTextureVector('L');
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
