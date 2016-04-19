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
class Lane :public Props{
public:
	Lane();
	virtual ~Lane();
	virtual void draw()=0;
	int coll(Player* player,bool type);
	bool roomForItem();
	bool itemAbsent(){return true;};
	bool spawnItem();
	bool fire(){return false;};
protected:
	std::list<Item*>itemList;
};

#endif /* ABSTRACT_ENTITIES_LANE_H_ */
