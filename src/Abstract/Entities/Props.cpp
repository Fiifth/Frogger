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
		row(nullptr), visible(true)
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

	if (timeToMove())
	{
		//1=up,2=right,3=down,4=left;
		if (*direction == 'R')
			move(*speed, 0, true);
		else if (*direction == 'L')
			move(-*speed, 0, true);
		else if ((*direction == 'U'))
			move(0, -*speed, true);
		else if (*direction == 'D')
			move(0, *speed, true);
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
	if (dividerCounter == 0)
	{

		dividerCounter = *divider;
		return true;
	}
	else
	{
		dividerCounter = dividerCounter - 1;
		return false;
	}
}

void frogger::Props::setProperties()
{

		direction=row->getDirection();
		y=row->getLocY();

		speed=row->getRowProperties()->getSpeed();
		divider=row->getRowProperties()->getDivider();
		itemRate=row->getRowProperties()->getItemRate();
		shootRate=row->getRowProperties()->getShootRate();
}
