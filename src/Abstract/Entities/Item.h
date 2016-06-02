/*
 * Item.h
 *
 *  Created on: 18-mrt.-2016
 *      Author: msn-w
 */

#ifndef ABSTRACT_ENTITIES_ITEM_H_
#define ABSTRACT_ENTITIES_ITEM_H_
#include "Props.h"
#include "Entity.h"
#include "Player.h"
namespace frogger
{
class Item: public frogger::Props
{
public:
	Item();
	virtual ~Item();
	virtual void draw()=0;
	void collision(Player* player);
	bool roomForItem();
	bool itemAbsent();
	void effectOnPlayer(Player* player);
	int effect;
	bool itemListEmpty()
		{
			return false;
		};
	bool spawnItem()
	{
		return false;
	}
	;
	bool fire()
	{
		return false;
	}
	;

};
}

#endif /* ABSTRACT_ENTITIES_ITEM_H_ */
