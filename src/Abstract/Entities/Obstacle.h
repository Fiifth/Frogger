/*
 * Enemy.h
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include "Props.h"
#include "Entity.h"
#include "Row.h"
#include <iostream>
#include "Player.h"
#include "Projectile.h"
#include <list>


class Obstacle :public Props{
public:
	Obstacle();
	virtual ~Obstacle();
	virtual void draw()=0;
	int coll(Player* player,bool type);
	bool roomForItem();
	bool itemAbsent(){return true;};
	bool fire();
	bool spawnItem(){return false;};
protected:
	std::list<Projectile*>projectileList;
};

#endif /* ENEMY_H_ */
