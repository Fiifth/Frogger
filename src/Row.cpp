/*
 * Row.cpp
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#include "Row.h"
#include <iostream>

Row::Row(bool direction, int speed, int divider, int locY, int height,int number,
		char type, int ObsticleSpawnChance,	int itemSpawnChance,int shootChance) :
		direction(direction), laneRow(false), speed(speed), divider(divider), locY(
				locY), height(height), number(number),type(type),ObsticleSpawnChance(ObsticleSpawnChance),
				itemSpawnChance(itemSpawnChance),shootChance(shootChance)
{

}

Row::~Row()
{
}

bool Row::isDirLeft() const
{
	return direction;
}

int Row::getLocY() const
{
	return locY;
}

int Row::getNumber() const
{
	return number;
}

int Row::getSpeed() const
{
	return speed;
}

int Row::getHeight() const
{
	return height;
}

bool Row::isLaneRow() const
{
	return laneRow;
}

void Row::setLaneRow(bool laneRow)
{
	this->laneRow = laneRow;
}

int Row::getDivider() const
{
	return divider;
}

void Row::setDivider(int divider)
{
	this->divider = divider;
}

int Row::getItemSpawnChance() const
{
	return itemSpawnChance;
}

int Row::getItemTypeChance() const
{
	return itemTypeChance;
}

int Row::getObsticleSpawnChance() const
{
	return ObsticleSpawnChance;
}

int Row::getShootChance() const
{
	return shootChance;
}

int Row::getTextureRangeE() const
{
	return textureRangeE;
}

int Row::getTextureRangeS() const
{
	return textureRangeS;
}

char Row::getType() const
{
	return type;
}

void Row::setSpeed(int speed)
{
	this->speed = speed;
}

void Row::setLocY(int locY)
{
	this->locY = locY;
}
