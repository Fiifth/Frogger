/*
 * Pops.cpp
 *
 *  Created on: 17-mrt.-2016
 *      Author: msn-w
 */

#include <Props.h>
#include "Row.h"
#include <iostream>

Props::Props(): row(nullptr),visible(true){
}

Props::~Props() {
}

void Props::setRow(Row* row) {
	this->row = row;
}

Row* Props::getRow(){
	return row;
}
void Props::moveForward()
{
	//1=up,2=right,3=down,4=left;
	if(direction==2)
		move(row->getSpeed(),0,true);
	else if (direction==4)
		move(-row->getSpeed(),0,true);
	else if ((direction==1))
		move(0,-row->getSpeed(),true);
	else if (direction==3)
		move(0,row->getSpeed(),true);
}
bool Props::isRoom()
{
	//bool temp=((x>0)&&(x<getWidth()-getW()));

	return ((x>0)&&(x<getWidth()-getW()));
}

bool Props::isVisible() const {
	return visible;
}

void Props::setVisible(bool visible) {
	this->visible = visible;
}

int Props::getDirection() const {
	return direction;
}

void Props::setDirection(int direction) {
	this->direction = direction;
}
