/*
 * Lane.cpp
 *
 *  Created on: 18-mrt.-2016
 *      Author: msn-w
 */

#include <Lane.h>

Lane::Lane() {
	//propBonus->getX()>temp->getX())&&((propBonus->getX()+propBonus->getW())<(temp->getX()+temp->getW())))

}

Lane::~Lane() {
}

bool roomForItem(int x, int w)
{
	if(x>getX()&&(x+w)<(getX()+getW()))
		return true;
	else
		return false;
}

