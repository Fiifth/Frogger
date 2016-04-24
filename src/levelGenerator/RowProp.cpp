/*
 * LevelProperties.cpp
 *
 *  Created on: 23-apr.-2016
 *      Author: msn-w
 */

#include <levelGenerator/RowProp.h>

RowProp::RowProp(int speed,int divider,	char type,	int textureRangeS,
		int textureRangeE,	int ObsticleSpawnChance,int itemSpawnChance,int shootChance,bool obstacleVis,bool laneVis
		,int aROS, int aROE,int aRLS,int aRLE)
: speed(speed),divider(divider), type(type), textureRangeS(textureRangeS),
	textureRangeE(textureRangeE), ObsticleSpawnChance(ObsticleSpawnChance), itemSpawnChance(itemSpawnChance),
 shootChance(shootChance),obstacleVis(obstacleVis),laneVis(laneVis),aROS(aROS), aROE(aROE),aRLS(aRLS),aRLE(aRLE)
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

int RowProp::getItemSpawnChance() const
{
	return itemSpawnChance;
}

int RowProp::getObsticleSpawnChance() const
{
	return ObsticleSpawnChance;
}

int RowProp::getShootChance() const
{
	return shootChance;
}

int RowProp::getSpeed() const
{
	return speed;
}

int RowProp::getTextureRangeE() const
{
	return textureRangeE;
}

int RowProp::getTextureRangeS() const
{
	return textureRangeS;
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
