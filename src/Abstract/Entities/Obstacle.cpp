/*
 * Enemy.cpp
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#include <Obstacle.h>

Obstacle::Obstacle()
{
}

Obstacle::~Obstacle() {
}

int Obstacle::coll(int xPos, int width,int row,bool type)
{
	return (row==getRow()->getNumber()&&((xPos>=(x)&&xPos<=(x+w))||(xPos+width>=(x)&&xPos+width<=(x+w))));
}

bool Obstacle::roomForItem()
{
	return false;
}
