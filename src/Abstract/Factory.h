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

class Factory
{
public:
	Factory();
	virtual ~Factory();
	virtual Player* createPlayer(int x, int y, int w, int h, int speedH,
			int speedV, int number)=0;
	virtual Obstacle* createObstacle(Row* row, bool visible, int x, int y,
			int w, int h)=0;
	virtual Lane* createLane(Row* row, bool visible, int x, int y, int w,
			int h)=0;
	virtual Item* createItem(Row* row, int x, int y, int w, int h, int type)=0;
	virtual Obstacle* createObstacle(Row* row, bool visible)=0;
	virtual Lane* createLane(Row* row, bool visible)=0;
	virtual Item* createItem(Row* row, int type)=0;
	virtual Projectile* createProjectile(Entity* entity, int speed, int type)=0;
	virtual Window* createWindow()=0;
	virtual Events* createEvents()=0;
	virtual Row* createRow(bool direction,int locY,	int width, int number, const RowProp* rowprop);
};

#endif /* FACTORY_H_ */
