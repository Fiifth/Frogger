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

int Lane::coll(int xPos, int YPos, int height, int width, bool type) {
	if (isTurned())
		return (((YPos>=(y)&&YPos<(y+h))||(YPos+height>(y)&&YPos+height<=(y+h)))&&((xPos>=(x)&&xPos<=(x+w))||(xPos+width>=(x)&&xPos+width<=(x+w))));
	else
		return 0;
}

bool Lane::roomForItem()
{
	//height item = row->getHeight();
	int itemX=row->isDirLeft()?screenWidth:-row->getHeight();
	return (getX()<=itemX)&&(getX()+getW()>=row->getHeight()+itemX);
}

