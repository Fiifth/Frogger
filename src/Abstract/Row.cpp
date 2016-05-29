/*
 * Row.cpp
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#include "Row.h"
#include <iostream>
using namespace frogger;


Row::Row(char direction, int locY, int height,int number,RowProp* rowProperties) :
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

int* Row::getLocY()
{
	return &locY;
}

int Row::getNumber() const
{
	return number;
}


int Row::getHeight() const
{
	return height;
}


void Row::setLocY(int NewlocY)
{
	locY = NewlocY;
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

RowProp* Row::getRowProperties()
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

void Row::setRowProperties(RowProp* rowProp)
{
	rowProperties=rowProp;
}

char* frogger::Row::getDirection() {
	return &direction;
}

void frogger::Row::setDirection(char direction) {
	this->direction = direction;
}

int* frogger::Row::getYP() {
	return &locY;
}
