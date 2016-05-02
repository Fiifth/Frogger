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
namespace frogger_sdl
{
class FactorySDL: public frogger::Factory
{
public:
	FactorySDL();
	virtual ~FactorySDL();
	virtual frogger::Player* createPlayer(int x, int y, int w, int h, int speedH,
			int speedV, int number);
	virtual frogger::Obstacle* createObstacle(frogger::Row* row,bool visible, int x, int y, int w, int h);
	virtual frogger::Lane* createLane(frogger::Row* row,bool visible, int x, int y, int w, int h);
	virtual frogger::Item* createItem(frogger::Row* row, int x, int y, int w, int h, int type);
	virtual frogger::Projectile* createProjectile(frogger::Entity* entity, int speed, int type);
	virtual frogger::Obstacle* createObstacle(frogger::Row* row,bool visible);
	virtual frogger::Lane* createLane(frogger::Row* row,bool visible);
	virtual frogger::Item* createItem(frogger::Row* row, int type);
	virtual frogger::Window* createWindow();
	virtual frogger::Events* createEvents();
	SDLdata* sdldata;
};
}

#endif /* FACTORYSDL_H_ */
