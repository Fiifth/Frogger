/*
 * Lane.cpp
 * These are the type of objects where a player can stand on (when it isn't turned). They are the opposite of the obstacle object.
 * When the lane object is visible and not turned a player that stands on the lane will automatically follow the object.
 *
 * The lane can be turned by the animator. When the object is turned it will behave like an obstacle.
 *
 * In classic game mode the player will need to hit all the lane objects on the last row to complete the level. When a player hits the lane
 * on this row it will be turned as well.
 *
 * The lane itself can create item objects when creating the object.
 *
 *  Created on: 18-mrt.-2016
 *      Author: Kwinten
 */

#include <Abstract/Entities/Lane.h>
#include "Abstract/Factory.h"
using namespace frogger;
Lane::Lane()
{
}

Lane::~Lane()
{
	for(Item* item:itemList)
	delete(item);
	itemList.clear();
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
		Item* item=F->createItem1();
		item->setEffect(row->getRowProperties()->getItemType());
		item->setAni(itemAni->at(item->getEffect()).clone());
		item->queryW(row->getHeight());
		item->setProperties(row,screenWidth,screenHeight, x + ((rand() % (w - h))),item->getW(),true);
		itemList.push_back(item);
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

void frogger::Lane::setItemAniList(std::vector<frogger::Animator>* itemAni)
{
	this->itemAni=itemAni;
}
