/*
 * Factory.h
 *
 *  Created on: 22 Feb 2016
 *      Author: Kwinten
 */

#ifndef ABSTRACT_FACTORY_H_
#define ABSTRACT_FACTORY_H_

#include "Abstract/Entities/Obstacle.h"
#include "Abstract/Entities/Player.h"
#include "Abstract/Window.h"
#include "Abstract/Events.h"
#include "Abstract/Row.h"
#include "Abstract/Entities/Lane.h"
#include "Abstract/Entities/Projectile.h"
#include "Abstract/Entities/Item.h"
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
