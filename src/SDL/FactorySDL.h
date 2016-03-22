/*
 * FactorySDL.h
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */
#include "Obstacle.h"
#include "Player.h"
#include "Factory.h"
#include "Window.h"
#include "Events.h"
#include "SDLdata.h"
#include "Row.h"
#include "Lane.h"
#include "Item.h"

#ifndef FACTORYSDL_H_
#define FACTORYSDL_H_

using namespace std;

class FactorySDL : public Factory {
public:
	FactorySDL();
	virtual ~FactorySDL();
	virtual Player* createPlayer(int x,int y,int w,int h,int speedH,int speedV);
	virtual Obstacle* createObstacle(Row* row,int x,int y,int w,int h);
	virtual Lane* createLane(Row* row,int x,int y,int w,int h);
	virtual Item* createItem(Row* row,int x,int y,int w,int h);
	virtual Window* createWindow();
	virtual Events* createEvents();
	SDLdata* sdldata;
};


#endif /* FACTORYSDL_H_ */
