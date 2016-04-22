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

Row* Factory::createRow(bool direction, int speed, int divider, int locY,
		int width, int number,char type, int ObsticleSpawnChance,	int itemSpawnChance,int shootChance)
{
	return new Row(direction, speed, divider, locY, width, number,type,ObsticleSpawnChance,itemSpawnChance,shootChance);
}

