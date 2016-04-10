/*
 * Lane.cpp
 *
 *  Created on: 18-mrt.-2016
 *      Author: msn-w
 */

#include <Lane.h>
#include "Entity.h"
#include <iostream>

Lane::Lane() {

}

Lane::~Lane() {
}

int Lane::coll(Entity* entity, bool type) {
	if (isTurned())
		return (((entity->getY()>=(y)&&entity->getY()<(y+h))||(entity->getY()+entity->getH()>(y)&&entity->getY()+entity->getH()<=(y+h)))&&((entity->getX()>=(x)&&entity->getX()<=(x+w))||(entity->getX()+entity->getW()>=(x)&&entity->getX()+entity->getW()<=(x+w))));
	else
		return 0;
}

bool Lane::roomForItem()
{
	//height item = row->getHeight();
	int itemX=row->isDirLeft()?screenWidth:-row->getHeight();
	return (getX()<=itemX)&&(getX()+getW()>=row->getHeight()+itemX);
}

