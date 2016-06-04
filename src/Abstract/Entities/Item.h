/*
 * Item.h
 *
 *  Created on: 18-mrt.-2016
 *      Author: Kwinten
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
	void effectOnPlayer(Player* player);
	bool itemListEmpty();

protected:
	int effect;

};
}

#endif /* ABSTRACT_ENTITIES_ITEM_H_ */
