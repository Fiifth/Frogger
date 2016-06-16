/*
 * FactorySDL.h
 *
 *  Created on: 22 Feb 2016
 *      Author: Kwinten
 */

#ifndef SDL_FACTORYSDL_H_
#define SDL_FACTORYSDL_H_

#include "Abstract/Entities/Obstacle.h"
#include "SDL/Entities/ObstacleSDL.h"
#include "Abstract/Entities/Player.h"
#include "SDL/Entities/PlayerSDL.h"
#include "Abstract/Window.h"
#include "SDL/WindowSDL.h"
#include "Abstract/Entities/Lane.h"
#include "SDL/Entities/LaneSDL.h"
#include "Abstract/Factory.h"
#include "Abstract/Row.h"
#include "Abstract/Events.h"
#include "SDL/EventsSDL.h"
#include "SDL/SDLdata.h"
#include "Abstract/Entities/Item.h"
#include "SDL/Entities/ItemSDL.h"
#include "Abstract/Entities/Projectile.h"
#include "SDL/Entities/ProjectileSDL.h"

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
