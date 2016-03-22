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
void Props::moveHor()
{
	if(!row->isDirection())
	//move(1+(((row->getSpeed())*2)/10),0,true);
		move(row->getSpeed(),0,true);
	else
		move(-row->getSpeed(),0,true);
	//move(-(1+(((row->getSpeed())*3)/10)),0,true);
}
bool Props::isRoom()
{
	bool temp=((x>0)&&(x<getWidth()-getW()));

	return ((x>0)&&(x<getWidth()-getW()));
}

bool Props::isVisible() const {
	return visible;
}

void Props::setVisible(bool visible) {
	this->visible = visible;
}
