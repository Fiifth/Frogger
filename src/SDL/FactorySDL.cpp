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

frogger::Window* FactorySDL::createWindow()
{
	return new WindowSDL(sdldata);
}

frogger::Events* FactorySDL::createEvents()
{
	return new EventsSDL();
}


frogger::Player* frogger_sdl::FactorySDL::createPlayer1()
{
	return new PlayerSDL(sdldata);
}



frogger::Projectile* frogger_sdl::FactorySDL::createProjectile1()
{
	return new ProjectileSDL(sdldata);
}

frogger::Obstacle* frogger_sdl::FactorySDL::createObstacle1()
{
	return new ObstacleSDL(sdldata);
}

frogger::Lane* frogger_sdl::FactorySDL::createLane1()
{
	return new LaneSDL(sdldata);
}

frogger::Item* frogger_sdl::FactorySDL::createItem1()
{
	return new ItemSDL(sdldata);
}
