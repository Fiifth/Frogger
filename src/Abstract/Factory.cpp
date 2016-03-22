/*
 * Factory.cpp
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */

#include "Factory.h"

using namespace std;

Factory::Factory() {}

Factory::~Factory() {}

Row* Factory::createRow(bool direction,int speed,int locY,int width, int number)
{
	return new Row(direction,speed,locY,width,number);
}

