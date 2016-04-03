/*
 * ItemSDL.cpp
 *
 *  Created on: 18-mrt.-2016
 *      Author: msn-w
 */

#include <ItemSDL.h>
#include "Row.h"
#include <stdlib.h>
#include <iostream>


ItemSDL::ItemSDL(SDLdata* sdldata,Row* row,int x,int y,int w,int h) :sdldata(sdldata),textures(sdldata->getItemTextures())
{
	Animator bla=sdldata->getItemAni();
				ani=&bla;
	setRow(row);
			setSpeed(row->getSpeed());
			setSize(0,h);
			setScreenSize(sdldata->getScreenWidth(),sdldata->getScreenHeight());
			tex=textures.at(0);
			//tex=ani->getTexture();
			int wn=0,hn=h;
			sdldata->getDependWAndH(tex,&wn, &hn);
			setSize(wn,hn);
			int xloc=row->isDirection()?screenWidth:-getW();
			setLocation(xloc,row->getLocY());
}

ItemSDL::~ItemSDL() {
	delete(ani);
}

void ItemSDL::draw()
{
	int angle=0;
		angle=row->isDirection()?1:0;
	sdldata->renderTexture(ani->getTexture(),sdldata->getRen(),x,y,&w,&h,angle);
}

ItemSDL::ItemSDL(SDLdata* sdldata, Row* row) :sdldata(sdldata),textures(sdldata->getItemTextures())
{
	ani=sdldata->getItemAni().clone();
	setRow(row);
	setSpeed(row->getSpeed());
	setSize(0,row->getHeight());
	setScreenSize(sdldata->getScreenWidth(),sdldata->getScreenHeight());
	tex=textures.at(0);
	tex=ani->getTexture();
	int wn=0,hn=row->getHeight();
	sdldata->getDependWAndH(tex,&wn, &hn);
	setSize(wn,hn);
	int xloc=row->isDirection()?screenWidth:-getW();
	setLocation(xloc,row->getLocY());
}
