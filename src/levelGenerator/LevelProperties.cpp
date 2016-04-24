/*
 * LevelProperties.cpp
 *
 *  Created on: 23-apr.-2016
 *      Author: msn-w
 */

#include <levelGenerator/LevelProperties.h>

LevelProperties::LevelProperties()
{
	firstRow=new RowProp(0,0,'A',0,0,0,0,0,true,false,1,1,0,0);
	lastRow=new RowProp(0,0,'E',0,0,100,100,0,true,false,1,1,0,0);
	middleRow=new RowProp(0,0,'D',0,0,50,50,0,true,false,1,1,0,0);
	level1();
//speed,divider,type,textureRangeS,textureRangeE,ObsticleSpawnChance,itemSpawnChance,shootChance);
}

LevelProperties::~LevelProperties()
{
	// TODO Auto-generated destructor stub
	//bool obstacleVis,bool laneVis
}

void LevelProperties::level1()
{
	seg1=new RowProp(1,0,'B',0,0,40,30,70,true,false,0,0,0,0);
	seg2=new RowProp(2,0,'B',0,0,50,10,20,true,false,0,0,0,0);
	seg3=new RowProp(1,0,'C',0,0,40,10,0,false,true,0,0,0,0);
	seg4=new RowProp(2,0,'C',0,0,50,10,0,false,true,0,0,0,0);
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
