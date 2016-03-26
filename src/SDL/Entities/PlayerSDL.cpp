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

using namespace std;


PlayerSDL::PlayerSDL(SDLdata* sdldata,int x,int y,int w,int h,int speedH,int speedV) :sdldata(sdldata),textures(sdldata->getPlayerTextures())

{//TODO get animator object instead of textures
	sethSpeed(speedH);
	setvSpeed(speedV);
	setSize(w,h);
	setLocation(x,y);
	setScreenSize(sdldata->getScreenWidth(),sdldata->getScreenHeight());
}

PlayerSDL::~PlayerSDL() {}

void PlayerSDL::draw()
{
	int angle=getDirection();
	int animationState=(getCounter()>0)?1:0;
	//TODO set counter/current texture on animator object
	setCounter(getCounter()>0?(getCounter()-1):0);
	sdldata->renderTexture(textures.at(animationState),sdldata->getRen(),x,y,&w,&h,angle);
}

