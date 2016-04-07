/*
 * Factory.h
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */
#include <Obstacle.h>
#include <Player.h>
#include "Window.h"
#include "WindowSDL.h"
#include "Events.h"
#include "SDLdata.h"
#include "Row.h"
#include "Lane.h"
#include "Projectile.h"
#include "Item.h"
#ifndef FACTORY_H_
#define FACTORY_H_

using namespace std;

class Factory {
public:
	Factory();
	virtual ~Factory();
	virtual Player* createPlayer(int x,int y,int w,int h,int speedH,int speedV)=0;
	virtual Obstacle* createObstacle(Row* row,int x,int y,int w,int h)=0;
	virtual Lane* createLane(Row* row,int x,int y,int w,int h)=0;
	virtual Item* createItem(Row* row,int x,int y,int w,int h)=0;
	virtual Obstacle* createObstacle(Row* row)=0;
	virtual Lane* createLane(Row* row)=0;
	virtual Item* createItem(Row* row)=0;
	virtual Projectile* createProjectile(int direction,int Xstart,int Ystart,int size,int speed)=0;
	virtual Window* createWindow()=0;
	virtual Events* createEvents()=0;
	virtual Row* createRow(bool direction,int speed,int locY,int width, int number);
};


#endif /* FACTORY_H_ */
