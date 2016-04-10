/*
 * Enemy.cpp
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#include <iostream>
#include <Obstacle.h>

Obstacle::Obstacle()
{
}

Obstacle::~Obstacle() {
}

int Obstacle::coll(Entity* entity, bool type) {
	if (!isTurned())
	return (((entity->getY()>=(y)&&entity->getY()<(y+h))||(entity->getY()+entity->getH()>(y)&&entity->getY()+entity->getH()<=(y+h)))&&((entity->getX()>=(x)&&entity->getX()<=(x+w))||(entity->getX()+entity->getW()>=(x)&&entity->getX()+entity->getW()<=(x+w))));
	else
		return 0;
}

bool Obstacle::roomForItem()
{
	return false;
}
