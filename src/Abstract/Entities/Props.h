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
	virtual int coll(int xPos,int YPos, int height,int width,bool type)=0;
	//type true=player, false=bullet return type of effect 0=no effect, 1 player dies, 2-6 object dissapears and player gets effect
	virtual bool roomForItem()=0;
	virtual bool itemAbsent()=0;
	int getDirection() const;
	void setDirection(int direction);

	int direction=0;//1=up,2=right,3=down,4=left;

protected:
	Row* row;
	bool visible;
};

#endif /* ABSTRACT_PROPS_H_ */
