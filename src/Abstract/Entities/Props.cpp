/*
 * Pops.cpp
 *
 *  Created on: 17-mrt.-2016
 *      Author: msn-w
 */

#include <Props.h>
#include "Factory.h"
using namespace frogger;

Props::Props() :
		row(nullptr), visible(true), divider(0)
{
}

Props::~Props()
{
}

void Props::setRow(Row* row)
{
	this->row = row;
}

Row* Props::getRow()
{
	return row;
}
void Props::moveForward()
{
	if (row!=nullptr)
	{
		y=row->getLocY();
		setDirection(row->isDirLeft() ? 4 : 2);
		setSpeed(row->getSpeed());
		divider = row->getDivider();
	}
	if (timeToMove())
	{
		//1=up,2=right,3=down,4=left;
		if (direction == 2)
			move(speed, 0, true);
		else if (direction == 4)
			move(-speed, 0, true);
		else if ((direction == 1))
			move(0, -speed, true);
		else if (direction == 3)
			move(0, speed, true);
	}
}
bool Props::isRoom()
{
	return ((x > 0) && (x < getWidth() - getW()));
}

bool Props::isVisible() const
{
	return visible;
}

void Props::setVisible(bool visible)
{
	this->visible = visible;
}

bool Props::isTurned() const
{
	return turned;
}

void Props::setTurned(bool turned)
{
	this->turned = turned;
}

bool Props::timeToMove()
{
	if (dividercounter == 0)
	{

		dividercounter = divider;
		return true;
	}
	else
	{
		dividercounter = dividercounter - 1;
		return false;
	}
}
