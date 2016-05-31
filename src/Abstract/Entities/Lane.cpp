/*
 * Lane.cpp
 *
 *  Created on: 18-mrt.-2016
 *      Author: msn-w
 */

#include <Lane.h>
#include "Factory.h"
using namespace frogger;
Lane::Lane()
{

}

Lane::~Lane()
{
}

void Lane::collision(Player* player)
{
	if (colli(player))
	{
		if ((isTurned()))
		{
			player->hit();
		}
		else if (isVisible())
			player->followRow(row);
		else if ((row->getRowProperties()->getType())=='E')
		{
			player->resetPosition();
			itemList.clear();
			turned=true;
			visible=true;
			//set texture
		}
	}

	itemList.remove_if(collisionS(player));
}

bool Lane::roomForItem()
{
	//height item = row->getHeight();
	int itemX = row->isDirLeft() ? *screenWidth : -row->getHeight();
	return (getX() <= itemX) && (getX() + getW() >= row->getHeight() + itemX);
}

bool Lane::spawnItem()
{
	if ((rand() % 100) <*itemRate)
	{
		itemList.push_back(
		F->createItem(row, x + ((rand() % (w - h))), *y, w, h, 0));
	}
	return true;
}

bool Lane::itemListEmpty()
{
	if (itemList.empty()&&row->getRowProperties()->getType()=='E')
	{
		//ani turn
		turned=true;
	}
	return itemList.empty();
}
