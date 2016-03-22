/*
 * Enemy.h
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */
#include "Props.h"
#include "Entity.h"
#include "Row.h"
#ifndef ENEMY_H_
#define ENEMY_H_

class Obstacle :public Props{
public:
	Obstacle();
	virtual ~Obstacle();
	virtual void draw()=0;
	bool coll(int xPos,int width,int row);

};

#endif /* ENEMY_H_ */
