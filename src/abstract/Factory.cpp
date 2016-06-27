/*
 * Factory.cpp
 *
 * Used to create objects
 *
 *  Created on: 22 Feb 2016
 *      Author: Kwinten
 */

#include <abstract/Factory.h>
using namespace frogger;

Factory::Factory()
{
}

Factory::~Factory()
{
}

Row* Factory::createRow(char direction, int locY, int width, int number,RowProp* rowprop)
{
	return new Row(direction, locY, width, number, rowprop);
}
