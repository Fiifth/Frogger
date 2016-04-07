/*
 * FactorySDL.cpp
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */

#include "Obstacle.h"
#include "ObstacleSDL.h"
#include "Player.h"
#include <PlayerSDL.h>
#include "FactorySDL.h"
#include "SDL.h"
#include "EventsSDL.h"
#include "LaneSDL.h"
#include "ItemSDL.h"
#include "ProjectileSDL.h"

#include "Window.h"
#include "WindowSDL.h"
#include "Row.h"


using namespace std;

FactorySDL::FactorySDL() {sdldata=new SDLdata();}

FactorySDL::~FactorySDL() {}

Player* FactorySDL::createPlayer(int x,int y,int w,int h,int speedH,int speedV)
{
	return new PlayerSDL(sdldata,x,y,w,h,speedH,speedV);
}
Obstacle* FactorySDL::createObstacle(Row* row,int x,int y,int w,int h)
{
	return new ObstacleSDL(sdldata,row,x,y,w,h);
}
Window* FactorySDL::createWindow()
{
	return new WindowSDL(sdldata);
}

Events* FactorySDL::createEvents()
{
	return new EventsSDL();
}

Lane* FactorySDL::createLane(Row* row, int x, int y, int w,int h)
{
	return new LaneSDL(sdldata,row,x,y,w,h);
}

Item* FactorySDL::createItem(Row* row, int x, int y, int w,int h)
{
	return new ItemSDL(sdldata,row,x,y,w,h);
}

Obstacle* FactorySDL::createObstacle(Row* row)
{
	return new ObstacleSDL(sdldata,row);
}

Lane* FactorySDL::createLane(Row* row)
{
	return new LaneSDL(sdldata,row);
}

Item* FactorySDL::createItem(Row* row)
{
	return new ItemSDL(sdldata,row);
}

Projectile* FactorySDL::createProjectile(int direction,int Xstart,int Ystart,int size,int speed)
{
	return new ProjectileSDL(sdldata,direction,Xstart,Ystart,size,speed);
}
