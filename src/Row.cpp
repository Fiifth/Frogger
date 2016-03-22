/*
 * Row.cpp
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#include "Row.h"


Row::Row(bool direction,int speed,int locY,int height, int number):direction(direction),laneRow(false),speed(speed),locY(locY), height(height),number(number)
{

}

Row::~Row() {
}

bool Row::isDirection() const {
	return direction;
}

int Row::getLocY() const {
	return locY;
}

int Row::getNumber() const {
	return number;
}

int Row::getSpeed() const {
	return speed;
}

int Row::getHeight() const {
	return height;
}

bool Row::isLaneRow() const {
	return laneRow;
}

void Row::setLaneRow(bool laneRow) {
	this->laneRow = laneRow;
}
