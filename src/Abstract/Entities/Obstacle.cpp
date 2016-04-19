/*
 * Enemy.cpp
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */


#include <Obstacle.h>
#include "Factory.h"

Obstacle::Obstacle()
{
}

Obstacle::~Obstacle() {
}

int Obstacle::coll(Player* player, bool type) {
	if (!isTurned())
	return (((player->getY()>=(y)&&player->getY()<(y+h))||(player->getY()+player->getH()>(y)&&player->getY()+player->getH()<=(y+h)))&&((player->getX()>=(x)&&player->getX()<=(x+w))||(player->getX()+player->getW()>=(x)&&player->getX()+player->getW()<=(x+w))));
	else
		return 0;
}

bool Obstacle::roomForItem()
{
	return false;
}

bool Obstacle::fire()
{
	projectileList.push_back(F->createProjectile(this,5,0));


	return true;
}
