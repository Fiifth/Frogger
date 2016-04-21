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
void Item::collision(Player* player) {
	//return (((player->getY()>=(y)&&player->getY()<(y+h))||(player->getY()+player->getH()>(y)&&player->getY()+player->getH()<=(y+h)))&&((player->getX()>=(x)&&player->getX()<=(x+w))||(player->getX()+player->getW()>=(x)&&player->getX()+player->getW()<=(x+w))))?3:0;
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
