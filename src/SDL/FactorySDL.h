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
			virtual frogger::Player* createPlayer(int x, int y, int w, int h,
					int speedH, int speedV, int number);
			virtual frogger::Obstacle* createObstacle(frogger::Row* row, bool visible, int x);
			virtual frogger::Lane* createLane(frogger::Row* row, bool visible,int x);
			virtual frogger::Item* createItem(frogger::Row* row, int x, int type);
			virtual frogger::Projectile* createProjectile(frogger::Entity* entity, int* Ypoint, int speed, int type);
			virtual frogger::Obstacle* createObstacle(frogger::Row* row,bool visible);
			virtual frogger::Lane* createLane(frogger::Row* row, bool visible);
			virtual frogger::Item* createItem(frogger::Row* row, int type);
			virtual frogger::Window* createWindow();
			virtual frogger::Events* createEvents();
		protected:
			SDLdata* sdldata;
	};
}

#endif /* FACTORYSDL_H_ */
