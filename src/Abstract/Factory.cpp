/*
 * Factory.cpp
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */

#include "Factory.h"
using namespace frogger;


using namespace std;

Factory::Factory()
{
}

Factory::~Factory()
{
}


Row* Factory::createRow(bool direction, int locY, int width, int number,const RowProp* rowprop)
{
	return new Row(direction, locY, width,number,rowprop);
}
