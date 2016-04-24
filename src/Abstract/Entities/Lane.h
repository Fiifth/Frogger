/*
 * Lane.h
 *
 *  Created on: 18-mrt.-2016
 *      Author: msn-w
 */

#ifndef ABSTRACT_ENTITIES_LANE_H_
#define ABSTRACT_ENTITIES_LANE_H_
#include "Props.h"
#include <iostream>
#include "Player.h"
#include <list>
#include "Item.h"
class Lane: public Props
{
public:
	Lane();
	virtual ~Lane();
	virtual void draw()=0;
	void collision(Player* player);
	bool roomForItem();
	bool itemListEmpty();
	bool itemAbsent()
	{
		return true;
	}
	;
	bool spawnItem();
	bool fire()
	{
		return false;
	}
	;
protected:
	std::list<Item*> itemList;
	struct collisionS
	{
		collisionS(Player* player) :
				player(player)
		{
		}
		Player* player;
		bool operator()(Item* item) const
		{
			if (item->colli(player))
			{
				player->addHighScore(1);
				player->addProjectiles(1);
				delete (item);
				//TODO fix effects
				return true;
			}
			else
				return false;
		}
	};
};

#endif /* ABSTRACT_ENTITIES_LANE_H_ */
