/*
 * Factory.h
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */

#ifndef FACTORY_H_
#define FACTORY_H_

#include "Obstacle.h"
#include "Player.h"
#include "Window.h"
#include "WindowSDL.h"
#include "Events.h"
#include "SDLdata.h"
#include "Row.h"
#include "Lane.h"
#include "Projectile.h"
#include "Item.h"
#include <levelGenerator/RowProp.h>

using namespace std;
namespace frogger
{
	class Factory
	{
		public:
			Factory();
			virtual ~Factory();
			virtual Window* createWindow()=0;
			virtual Events* createEvents()=0;
			virtual Row* createRow(char direction, int locY, int width,	int number, RowProp* rowprop);
			virtual Player* createPlayer1()=0;
			virtual Obstacle* createObstacle1()=0;
			virtual Lane* createLane1()=0;
			virtual Item* createItem1()=0;
			virtual Projectile* createProjectile1()=0;
	};
}
#endif /* FACTORY_H_ */
