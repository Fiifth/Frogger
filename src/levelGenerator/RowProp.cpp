/*
 * LevelProperties.cpp
 *
 *  Created on: 23-apr.-2016
 *      Author: msn-w
 */

#include <levelGenerator/RowProp.h>
using namespace frogger;

RowProp::RowProp(int speed,int divider,char type,int obstRate,int itemRate,
		int shootRate, bool obstacleVis,bool laneVis,std::vector<int> obstIndexes,
		std::vector<int> laneIndexes,std::vector<int> itemTypeChance)
: speed(speed),divider(divider), type(type), obstRate(obstRate), itemRate(itemRate),
 shootRate(shootRate),obstacleVis(obstacleVis),laneVis(laneVis), obstIndexes(obstIndexes),
 laneIndexes(laneIndexes),itemTypeChance(itemTypeChance)
{
	// TODO Auto-generated constructor stub

}

RowProp::~RowProp()
{
	// TODO Auto-generated destructor stub
}

int RowProp::getDivider() const
{
	return divider;
}

int RowProp::getItemRate() const
{
	return itemRate;
}

int RowProp::getObsticleRate() const
{
	return obstRate;
}

int RowProp::getShootRate() const
{
	return shootRate;
}

int RowProp::getSpeed() const
{
	return speed;
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

const std::vector<int>& RowProp::getItemTypeChance() const
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

