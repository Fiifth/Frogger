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

int Obstacle::coll(int xPos, int YPos, int height, int width, bool type) {
	return (((YPos>=(y)&&YPos<(y+h))||(YPos+height>(y)&&YPos+height<=(y+h)))&&((xPos>=(x)&&xPos<=(x+w))||(xPos+width>=(x)&&xPos+width<=(x+w))));
	}

bool Obstacle::roomForItem()
{
	return false;
}
