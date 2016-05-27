/*
 * Row.cpp
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#include "Row.h"
#include <iostream>
using namespace frogger;


Row::Row(char direction, int locY, int height,int number,const RowProp* rowProperties) :
		direction(direction), locY(	locY), height(height), number(number),rowProperties(rowProperties)
{

}

Row::~Row()
{
}

bool Row::isDirLeft() const
{
	return direction=='L';
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
	return rowProperties->getSpeed();
}

int Row::getHeight() const
{
	return height;
}


int Row::getDivider() const
{
	return rowProperties->getDivider();
}


int Row::getItemRate() const
{
	return rowProperties->getItemRate();
}


int Row::getObsticleRate() const
{
	return rowProperties->getObsticleRate();
}

int Row::getShootRate() const
{
	return rowProperties->getShootRate();
}


char Row::getType() const
{
	return rowProperties->getType();
}

void Row::setLocY(int locY)
{
	this->locY = locY;
}
Row* Row::clone()
{
	return new Row(*this);
}

bool Row::isLaneVis() const
{
	return rowProperties->getLaneVis();
}

bool Row::isObstacleVis() const
{
	return rowProperties->getObstacleVis();
}

const RowProp* Row::getRowProperties() const
{
	return rowProperties;
}

int Row::getRandomObsInd()
{
	return rowProperties->getObstIndexes().at(rand()%rowProperties->getObstIndexes().size());
}

int Row::getRandomLaneInd()
{
	return rowProperties->getLaneIndexes().at(rand()%rowProperties->getLaneIndexes().size());
}

void Row::setRowProperties(const RowProp* rowProp)
{
	rowProperties=rowProp;
}

char frogger::Row::getDirection() const {
	return direction;
}

void frogger::Row::setDirection(char direction) {
	this->direction = direction;
}
