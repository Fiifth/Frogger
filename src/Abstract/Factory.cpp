/*
 * Factory.cpp
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */

#include "Factory.h"


using namespace std;

Factory::Factory()
{
}

Factory::~Factory()
{
}


Row* Factory::createRow(bool direction, int locY, int width, int number,const RowProp* rowprop)
{
	return new Row(direction, rowprop->getSpeed(), rowprop->getDivider(),
			locY, width, number,rowprop->getType(),rowprop->getObsticleSpawnChance(),
			rowprop->getItemSpawnChance(),rowprop->getShootChance(),rowprop->getObstacleVis(),rowprop->getLaneVis(),
			rowprop->aROS,  rowprop->aROE, rowprop->aRLS, rowprop->aRLE);
}
