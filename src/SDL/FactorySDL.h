/*
 * FactorySDL.h
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */

#ifndef FACTORYSDL_H_
#define FACTORYSDL_H_

#include "Obstacle.h"
#include "ObstacleSDL.h"
#include "Player.h"
#include "PlayerSDL.h"
#include "Window.h"
#include "WindowSDL.h"
#include "Lane.h"
#include "LaneSDL.h"
#include "Factory.h"
#include "Row.h"
#include "Events.h"
#include "EventsSDL.h"
#include "SDLdata.h"
#include "Item.h"
#include "ItemSDL.h"
#include "Projectile.h"
#include "ProjectileSDL.h"

namespace frogger_sdl
{
	class FactorySDL: public frogger::Factory
	{
		public:
			FactorySDL();
			virtual ~FactorySDL();

			virtual frogger::Window* createWindow();
			virtual frogger::Events* createEvents();

			virtual frogger::Player* createPlayer1();
			virtual frogger::Obstacle* createObstacle1();
			virtual frogger::Lane* createLane1();
			virtual frogger::Item* createItem1();
			virtual frogger::Projectile* createProjectile1();


		protected:
			SDLdata* sdldata;
	};
}

#endif /* FACTORYSDL_H_ */
