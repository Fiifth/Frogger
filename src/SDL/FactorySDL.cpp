/*
 * FactorySDL.cpp
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */

#include "FactorySDL.h"

using namespace frogger_sdl;

FactorySDL::FactorySDL()
{
	sdldata = new SDLdata();
}

FactorySDL::~FactorySDL()
{
	delete(sdldata);
}

frogger::Player* FactorySDL::createPlayer(int x, int y, int w, int h,
		int speedH, int speedV, int number)
{
	return new PlayerSDL(sdldata, this, x, y, w, h, speedH, speedV, number);
}
frogger::Obstacle* FactorySDL::createObstacle(frogger::Row* row, bool visible,	int x)
{
	return new ObstacleSDL(sdldata, row, this, visible, x);
}
frogger::Window* FactorySDL::createWindow()
{
	return new WindowSDL(sdldata);
}

frogger::Events* FactorySDL::createEvents()
{
	return new EventsSDL();
}

frogger::Lane* FactorySDL::createLane(frogger::Row* row, bool visible, int x)
{
	return new LaneSDL(sdldata, row, this, visible, x);
}

frogger::Item* FactorySDL::createItem(frogger::Row* row, int x,int type)
{
	return new ItemSDL(sdldata, row, x, type);
}

frogger::Obstacle* FactorySDL::createObstacle(frogger::Row* row, bool visible)
{
	return new ObstacleSDL(sdldata, row, this, visible);
}

frogger::Lane* FactorySDL::createLane(frogger::Row* row, bool visible)
{
	return new LaneSDL(sdldata, row, this, visible);
}

frogger::Item* FactorySDL::createItem(frogger::Row* row, int type)
{
	return new ItemSDL(sdldata, row, type);
}

frogger::Projectile* FactorySDL::createProjectile(frogger::Entity* entity,
		int* Ypoint, int speed, int type)
{
	int x, y;
	char dir = entity->getDirection();
	if (dir == 'U')
	{
		x = entity->getX();
		y = entity->getY();
	}
	else if (dir == 'R')
	{
		x = entity->getX();
		y = entity->getY();
	}
	else if (dir == 'D')
	{
		x = entity->getX();
		y = entity->getY();
	}
	else if (dir == 'L')
	{
		x = entity->getX();
		y = entity->getY();
	}
	return new ProjectileSDL(sdldata, entity->getDirection(), x, y, Ypoint,
			entity->getH(), speed, type);
}
