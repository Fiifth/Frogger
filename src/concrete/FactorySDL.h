/*
 * FactorySDL.h
 *
 *  Created on: 22 Feb 2016
 *      Author: Kwinten
 */

#ifndef CONCRETE_FACTORYSDL_H_
#define CONCRETE_FACTORYSDL_H_

#include <abstract/entities/Item.h>
#include <abstract/entities/Lane.h>
#include <abstract/entities/Obstacle.h>
#include <abstract/entities/Player.h>
#include <abstract/entities/Projectile.h>
#include <abstract/Events.h>
#include <abstract/Factory.h>
#include <abstract/Row.h>
#include <abstract/Window.h>
#include <concrete/entities/ItemSDL.h>
#include <concrete/entities/LaneSDL.h>
#include <concrete/entities/ObstacleSDL.h>
#include <concrete/entities/PlayerSDL.h>
#include <concrete/entities/ProjectileSDL.h>
#include <concrete/EventsSDL.h>
#include <concrete/SDLdata.h>
#include <concrete/WindowSDL.h>

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
