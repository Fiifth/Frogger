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

bool Item::coll(int xPos, int width,int row)
{
	return (row==getRow()->getNumber()&&((xPos>=(x)&&xPos<=(x+w))||(xPos+width>=(x)&&xPos+width<=(x+w))));
}
