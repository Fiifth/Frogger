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
	void moveHor();
	bool isRoom();
	bool isVisible() const;
	void setVisible(bool visible);
	virtual void draw()=0;
	virtual bool coll(int xPos,int width,int row)=0;
	virtual bool roomForItem()=0;
	virtual bool itemAbsent()=0;

protected:
	Row* row;
	bool visible;
};

#endif /* ABSTRACT_PROPS_H_ */
