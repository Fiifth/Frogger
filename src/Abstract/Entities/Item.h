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

class Item :public Props{
public:
	Item();
	virtual ~Item();
	virtual void draw()=0;
	int coll(Entity* entity,bool type);
	bool roomForItem();
	bool itemAbsent();
	int effect=3;
};

#endif /* ABSTRACT_ENTITIES_ITEM_H_ */
