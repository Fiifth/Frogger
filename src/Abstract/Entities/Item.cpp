/*
 * Item.cpp
 *
 *  Created on: 18-mrt.-2016
 *      Author: msn-w
 */

#include <Item.h>

Item::Item() {
}

Item::~Item() {
}

bool Item::roomForItem()
{
	return false;
}
//
//int xPos, int YPos, int height, int width
int Item::coll(Entity* entity, bool type) {
	return (((entity->getY()>=(y)&&entity->getY()<(y+h))||(entity->getY()+entity->getH()>(y)&&entity->getY()+entity->getH()<=(y+h)))&&((entity->getX()>=(x)&&entity->getX()<=(x+w))||(entity->getX()+entity->getW()>=(x)&&entity->getX()+entity->getW()<=(x+w))))?3:0;
}

bool Item::itemAbsent()
{
	//height item = row->getHeight();
		int itemX=row->isDirLeft()?screenWidth:-row->getHeight();
		int x1=itemX;
		int x2=itemX+row->getHeight();
		int x3=getX();
		int x4=getX()+getW();
		//(x3>x2)||(x4<x1)
		return ((x3>x2)||(x4<x1));
}
