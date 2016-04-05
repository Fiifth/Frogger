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

int Item::coll(int xPos, int width,int row,bool type)
{
	return row==getRow()->getNumber()&&((xPos>=(x)&&xPos<=(x+w))||(xPos+width>=(x)&&xPos+width<=(x+w)))?3:0;
}

bool Item::roomForItem()
{
	return false;
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
