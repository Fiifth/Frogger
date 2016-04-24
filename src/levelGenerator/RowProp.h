/*
 * LevelProperties.h
 *
 *  Created on: 23-apr.-2016
 *      Author: msn-w
 */

#ifndef LVLPROP_H_
#define LVLPROP_H_

class RowProp
{
public:
	RowProp(int speed,int divider,	char type,	int textureRangeS,
			int textureRangeE,	int ObsticleSpawnChance,int itemSpawnChance,int shootChance, bool obstacleVis,bool laneVis
			,int aROS, int aROE,int aRLS,int aRLE);
	virtual ~RowProp();
	int getDivider() const;
	int getItemSpawnChance() const;
	int getObsticleSpawnChance() const;
	int getShootChance() const;
	int getSpeed() const;
	int getTextureRangeE() const;
	int getTextureRangeS() const;
	char getType() const;
	bool getLaneVis() const;
	bool getObstacleVis() const;

	int getRle() const
	{
		return aRLE;
	}

	int getRls() const
	{
		return aRLS;
	}

	int getRoe() const
	{
		return aROE;
	}

	int getRos() const
	{
		return aROS;
	}

	int speed;
	int divider;
	char type;
	int textureRangeS;
	int textureRangeE;
	int ObsticleSpawnChance;
	int itemSpawnChance;
	int shootChance;
	bool obstacleVis;
	bool laneVis;
	int aROS=0;//animator range obstacle start
	int aROE=0;
	int aRLS=0; //animator range Lane start
	int aRLE=0;
};

#endif /* LVLPROP_H_ */
