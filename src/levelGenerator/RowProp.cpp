/*
 * LevelProperties.cpp
 * Keeps the properties for prop objects.
 *
 *  Created on: 23-apr.-2016
 *      Author: Kwinten
 */

#include <levelGenerator/RowProp.h>
using namespace frogger;

RowProp::RowProp(int speed, int divider, char type, char mode, int obstRate,
		int itemRate, int shootRate, bool obstacleVis, bool laneVis,
		std::vector<int> obstIndexes, std::vector<int> laneIndexes,
		std::vector<int> itemTypeChance) :
		speed(speed), divider(divider), type(type), mode(mode), obstRate(
				obstRate), itemRate(itemRate), shootRate(shootRate), obstacleVis(
				obstacleVis), laneVis(laneVis), obstIndexes(obstIndexes), laneIndexes(
				laneIndexes), itemTypeChance(itemTypeChance)
{
}

RowProp::~RowProp()
{
}

int* RowProp::getDivider()
{
	return &divider;
}

int* RowProp::getItemRate()
{
	return &itemRate;
}

int RowProp::getObsticleRate() const
{
	return obstRate;
}

int* RowProp::getShootRate()
{
	return &shootRate;
}

int* RowProp::getSpeed()
{
	return &speed;
}

char RowProp::getType() const
{
	return type;
}

bool RowProp::getLaneVis() const
{
	return laneVis;
}

bool RowProp::getObstacleVis() const
{
	return obstacleVis;
}

std::vector<int> RowProp::getItemTypeChance()
{
	return itemTypeChance;
}

const std::vector<int>& RowProp::getLaneIndexes() const
{
	return laneIndexes;
}

const std::vector<int>& RowProp::getObstIndexes() const
{
	return obstIndexes;
}

void frogger::RowProp::increaseProp(int deltaSpe, int deltaDiv,
		int deltaObsRate, int deltaItemRate, int deltaShootRate)
{
	speed = speed + deltaSpe;
	divider = divider + deltaDiv;
	obstRate = obstRate + deltaObsRate;
	itemRate = itemRate + deltaItemRate;
	shootRate = shootRate + deltaShootRate;
}

int frogger::RowProp::getItemType()
{
	int temp = rand() % 100;
	if (temp < itemTypeChance.at(0))
		return 0;
	else if (temp < itemTypeChance.at(0) + itemTypeChance.at(1))
		return 1;
	else
		return 2;
}

char frogger::RowProp::getMode() const
{
	return mode;
}
