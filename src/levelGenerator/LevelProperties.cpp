/*
 * LevelProperties.cpp
 *
 *  Created on: 23-apr.-2016
 *      Author: msn-w
 */

#include <levelGenerator/LevelProperties.h>

LevelProperties::LevelProperties(char mode) :mode(mode)
{
	firstRow=new RowProp(0,0,'A',0,0,0,true,false,{1},{0},{0});
	lastRow=new RowProp(0,0,'E',100,100,0,true,false,getVec(10,11),{2},{0});
	middleRow=new RowProp(0,0,'D',50,50,0,true,false,getVec(10,11),{0},{0});
	level1();
}

LevelProperties::~LevelProperties()
{
	// TODO Auto-generated destructor stub
}

void LevelProperties::level1()
{
	seg1=new RowProp(1,0,'B',40,30,100,true,false,getVec(0,8),{0,3,4,5},{1});
	seg2=new RowProp(2,0,'B',50,10,20,true,false,getVec(0,8),{0,3,4,5},{1});
	seg3=new RowProp(1,0,'C',40,30,70,false,true,getVec(0,8),{0,3,4,5},{1});
	seg4=new RowProp(2,0,'C',50,10,70,false,true,getVec(0,8),{0,3,4,5},{1});
}

const RowProp* LevelProperties::getFirstRow() const
{
	return firstRow;
}

const RowProp* LevelProperties::getLastRow() const
{
	return lastRow;
}

const RowProp* LevelProperties::getMiddleRow() const
{
	return middleRow;
}

const RowProp* LevelProperties::getSeg1() const
{
	return seg1;
}

const RowProp* LevelProperties::getSeg2() const
{
	return seg2;
}

const RowProp* LevelProperties::getSeg3() const
{
	return seg3;
}

const RowProp* LevelProperties::getSeg4() const
{
	return seg4;
}

std::vector<int> LevelProperties::getVec(int a, int b)
{
	std::vector<int> temp;
	for(int i=a;i<=b;i++)
	{
		temp.push_back(i);
	}
	return temp;

}

char LevelProperties::getMode() const
{
	return mode;
}

void LevelProperties::setMode(char mode)
{
	this->mode = mode;
}
