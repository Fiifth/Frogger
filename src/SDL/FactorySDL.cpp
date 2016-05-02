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
using namespace frogger_sdl;

FactorySDL::FactorySDL()
{
	sdldata = new SDLdata();
}

FactorySDL::~FactorySDL()
{
}

frogger::Player* FactorySDL::createPlayer(int x, int y, int w, int h, int speedH,
		int speedV, int number)
{
	return new PlayerSDL(sdldata, this, x, y, w, h, speedH, speedV, number);
}
frogger::Obstacle* FactorySDL::createObstacle(frogger::Row* row,bool visible, int x, int y, int w, int h)
{
	return new ObstacleSDL(sdldata, row, this,visible, x, y, w, h);
}
frogger::Window* FactorySDL::createWindow()
{
	return new WindowSDL(sdldata);
}

frogger::Events* FactorySDL::createEvents()
{
	return new EventsSDL();
}

frogger::Lane* FactorySDL::createLane(frogger::Row* row,bool visible, int x, int y, int w, int h)
{
	return new LaneSDL(sdldata, row, this,visible, x, y, w, h);
}

frogger::Item* FactorySDL::createItem(frogger::Row* row, int x, int y, int w, int h, int type)
{
	return new ItemSDL(sdldata, row, x, y, w, h, type);
}

frogger::Obstacle* FactorySDL::createObstacle(frogger::Row* row,bool visible)
{
	return new ObstacleSDL(sdldata, row, this,visible);
}

frogger::Lane* FactorySDL::createLane(frogger::Row* row,bool visible)
{
	return new LaneSDL(sdldata, row, this,visible);
}

frogger::Item* FactorySDL::createItem(frogger::Row* row, int type)
{
	return new ItemSDL(sdldata, row, type);
}

frogger::Projectile* FactorySDL::createProjectile(frogger::Entity* entity, int speed, int type)
{
	int x, y;
	int dir = entity->getDirection();
	//int direction=0;//1=up,2=right,3=down,4=left;
	if (dir == 1)
	{
		x = entity->getX();
		y = entity->getY();
	}
	else if (dir == 2)
	{
		x = entity->getX();
		y = entity->getY();
	}
	else if (dir == 3)
	{
		x = entity->getX();
		y = entity->getY();
	}
	else if (dir == 4)
	{
		x = entity->getX();
		y = entity->getY();
	}
	return new ProjectileSDL(sdldata, entity->getDirection(), x, y,
			entity->getH(), speed, type);
}
