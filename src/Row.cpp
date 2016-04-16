/*
 * Row.cpp
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#include "Row.h"


Row::Row(bool direction,int speed,int divider,int locY,int height, int number):direction(direction),laneRow(false),speed(speed),divider(divider),locY(locY), height(height),number(number)
{

}

Row::~Row() {
}

bool Row::isDirLeft() const {
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

int Row::getDivider() const {
	return divider;
}

void Row::setDivider(int divider) {
	this->divider = divider;
}
