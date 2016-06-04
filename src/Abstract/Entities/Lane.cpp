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
		if (isTurned())
		{
			player->hit();
		}
		else if (isVisible())
			player->followRow(row);
		else if ((row->getRowProperties()->getType()) == 'E')
		{
			//Player collides with a lane that is on the last row of classic frogger mode
			player->resetPosition();
			itemList.clear();
			turned = true;
			visible = true;
		}
	}

	itemList.remove_if(collisionS(player));
}

void Lane::spawnItem()
{
	if ((rand() % 100) < *itemRate)
	{
		itemList.push_back(	F->createItem(row, x + ((rand() % (w - h))), row->getRowProperties()->getItemType()));
	}
}

bool Lane::itemListEmpty()
{
	return itemList.empty();
}

bool frogger::Lane::collisionS::operator ()(Item* item) const
{
	if (item->colli(player))
	{
		item->effectOnPlayer(player);
		delete (item);
		return true;
	}
	else
		return false;
}
