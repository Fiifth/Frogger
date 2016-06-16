/*
 * Pops.cpp
 *
 * These are the objects a player can interact with (lane/obstacle/item/projectile)
 * They usually have a row object where they take their properties from.
 * (Exception when projectile is created by a player since the player doesn't have a row to give)
 *
 *  Created on: 17-mrt.-2016
 *      Author: Kwinten
 */

#include <Abstract/Entities/Props.h>
#include "Abstract/Factory.h"
using namespace frogger;

Props::Props():	row(nullptr), visible(true),turned(false),isTurenedByAni(false),itemRate(nullptr),shootRate(nullptr)
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
	return ((x > 0) && (x < getScrWidth() - getW()));
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

void frogger::Props::setProperties(Row* row, int* screenWidth,
		int* screenHeight, int x, int w, bool vis)
{
	this->row = row;
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	this->x = x;
	this->w = w;
	this->visible = vis;
	if (row != nullptr) //projectiles do not have rows when shot by a player
	{
		direction = row->getDirection();
		y = row->getLocY();
		this->h = row->getHeight();
		speed = row->getRowProperties()->getSpeed();
		divider = row->getRowProperties()->getDivider();
		itemRate = row->getRowProperties()->getItemRate();
		shootRate = row->getRowProperties()->getShootRate();
	}
}

bool Props::drawMoveRemove::operator ()(Props* prop)
{
	bool temp = false;
	if (!prop->inframe())
	{
		temp = true;
		delete (prop);
	}
	else
	{
		prop->moveForward();
		if (prop->isVisible())
			prop->draw();

	}
	return temp;
}
