/*
 * Item.h
 *
 *  Created on: 18-mrt.-2016
 *      Author: msn-w
 */

#ifndef ABSTRACT_ENTITIES_ITEM_H_
#define ABSTRACT_ENTITIES_ITEM_H_
#include "Props.h"

class Item :public Props{
public:
	Item();
	virtual ~Item();
	virtual void draw()=0;
	bool coll(int xPos,int width,int row);
	bool roomForItem();
	bool itemAbsent();
};

#endif /* ABSTRACT_ENTITIES_ITEM_H_ */
