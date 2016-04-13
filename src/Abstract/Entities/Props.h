/*
 * Pops.h
 *
 *  Created on: 17-mrt.-2016
 *      Author: msn-w
 */

#ifndef ABSTRACT_PROPS_H_
#define ABSTRACT_PROPS_H_
#include "Entity.h"
#include "Row.h"

class Props :public Entity {
public:
	Props();
	virtual ~Props();
	void setRow(Row* row);
	Row* getRow();
	void moveForward();
	bool isRoom();
	bool isVisible() const;
	void setVisible(bool visible);
	virtual void draw()=0;
	virtual int coll(Entity* entity,bool type)=0;
	//type true=player, false=bullet return type of effect 0=no effect, 1 player dies, 2-6 object disappears and player gets effect
	virtual bool roomForItem()=0;
	virtual bool itemAbsent()=0;


	bool isTurned() const;
	void setTurned(bool turned);



protected:
	Row* row;
	bool visible;
	bool turned=false;
	bool isTurenedByAni=false;
};

#endif /* ABSTRACT_PROPS_H_ */
