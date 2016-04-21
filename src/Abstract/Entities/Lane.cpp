/*
 * Lane.cpp
 *
 *  Created on: 18-mrt.-2016
 *      Author: msn-w
 */

#include <Lane.h>
#include "Factory.h"
Lane::Lane() {

}

Lane::~Lane() {
}

void Lane::collision(Player* player)
{
	if (colli(player))
	{
		if((isTurned()))
			player->hit();
		else if (isVisible())
			player->followRow(row);
	}

	itemList.remove_if(collisionS(player));
}

bool Lane::roomForItem()
{
	//height item = row->getHeight();
	int itemX=row->isDirLeft()?screenWidth:-row->getHeight();
	return (getX()<=itemX)&&(getX()+getW()>=row->getHeight()+itemX);
}

bool Lane::spawnItem()
{
	itemList.push_back(F->createItem(row,x+((rand()%(w-h))),y,w,h,0));
	//itemList.push_back(F->createItem(row,0));
	//std::cout<<"new"<<itemList.size()<<endl;
	return true;
}
