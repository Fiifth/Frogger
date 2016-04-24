/*
 * Row.cpp
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#include "Row.h"
#include <iostream>

Row::Row(bool direction, int speed, int divider, int locY, int height,int number,
		char type, int ObsticleSpawnChance,	int itemSpawnChance,int shootChance,bool obstacleVis,
		bool laneVis,int aROS, int aROE,int aRLS,int aRLE) :
		direction(direction), laneRow(false), speed(speed), divider(divider), locY(
				locY), height(height), number(number),type(type),ObsticleSpawnChance(ObsticleSpawnChance),
				itemSpawnChance(itemSpawnChance),shootChance(shootChance),obstacleVis(obstacleVis),	laneVis(laneVis),
				aROS(aROS), aROE(aROE),aRLS(aRLS),aRLE(aRLE)
{

}
Row::Row(bool direction, int locY, int height,int number,RowProp* rowProperties) :
		direction(direction), locY(	locY), height(height), number(number)
{
		int speed=rowProperties->getSpeed();
		int divider=rowProperties->getDivider();
		char type=rowProperties->getType();
		int aROS;
		int aROE;
		int aRLS;
		int aRLE;
		int ObsticleSpawnChance=rowProperties->getObsticleSpawnChance();
		int itemSpawnChance=rowProperties->getItemSpawnChance();
		int shootChance=rowProperties->getShootChance();
		int itemTypeChance=0;
		bool obstacleVis=rowProperties->getObstacleVis();
		bool laneVis=rowProperties->getLaneVis();
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
Row* Row::clone()
{
	return new Row(*this);
}

int Row::getRle() const
{
	return aRLE;
}

int Row::getRls() const
{
	return aRLS;
}

int Row::getRoe() const
{
	return aROE;
}

int Row::getRos() const
{
	return aROS;
}
