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

bool Lane::roomForItem()
{
	//height item = row->getHeight();
	int itemX=row->isDirLeft()?screenWidth:-row->getHeight();
	return (getX()<=itemX)&&(getX()+getW()>=row->getHeight()+itemX);
}

