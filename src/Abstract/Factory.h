/*
 * Factory.h
 *
 *  Created on: 22 Feb 2016
 *      Author: Kwinten
 */

#ifndef ABSTRACT_FACTORY_H_
#define ABSTRACT_FACTORY_H_

#include <abstract/entities/Item.h>
#include <abstract/entities/Lane.h>
#include <abstract/entities/Obstacle.h>
#include <abstract/entities/Player.h>
#include <abstract/entities/Projectile.h>
#include <abstract/Events.h>
#include <abstract/Row.h>
#include <abstract/Window.h>
#include <levelGenerator/RowProp.h>

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
#endif /* ABSTRACT_FACTORY_H_ */
