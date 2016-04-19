/*
 * FactorySDL.h
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */


#ifndef FACTORYSDL_H_
#define FACTORYSDL_H_
#include "Obstacle.h"
#include "Player.h"
#include "Factory.h"
#include "Window.h"
#include "Events.h"
#include "SDLdata.h"
#include "Row.h"
#include "Lane.h"
#include "Item.h"
#include "Projectile.h"
#include "ProjectileSDL.h"

using namespace std;

class FactorySDL : public Factory {
public:
	FactorySDL();
	virtual ~FactorySDL();
	virtual Player* createPlayer(int x,int y,int w,int h,int speedH,int speedV,int number);
	virtual Obstacle* createObstacle(Row* row,int x,int y,int w,int h);
	virtual Lane* createLane(Row* row,int x,int y,int w,int h);
	virtual Item* createItem(Row* row,int x,int y,int w,int h,int type);
	virtual Projectile* createProjectile(Entity* entity,int speed,int type);
	virtual Obstacle* createObstacle(Row* row);
	virtual Lane* createLane(Row* row);
	virtual Item* createItem(Row* row,int type);
	virtual Window* createWindow();
	virtual Events* createEvents();
	SDLdata* sdldata;
};


#endif /* FACTORYSDL_H_ */
