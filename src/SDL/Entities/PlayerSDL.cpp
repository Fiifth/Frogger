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

{
	ani=sdldata->getPlayerAni().clone();
	sethSpeed(speedH);
	setvSpeed(speedV);
	setSize(w,h);
	setLocation(x,y);
	setScreenSize(sdldata->getScreenWidth(),sdldata->getScreenHeight());
}

PlayerSDL::~PlayerSDL() {}

void PlayerSDL::draw()
{
	//int direction=0;//1=up,2=right,3=down,4=left;
	int angle=0;
	angle=(getDirection()==2)?90:angle;
	angle=(getDirection()==3)?180:angle;
	angle=(getDirection()==4)?270:angle;
	//int angle=getDirection();
	int animationState=(getCounter()>0)?1:0;
	ani->setCurrentTexture(animationState);
	setCounter(getCounter()>0?(getCounter()-1):0);
	ani->setCounter(getCounter());
	sdldata->renderTexture(ani->getTexture(),sdldata->getRen(),x,y,&w,&h,angle);
}

