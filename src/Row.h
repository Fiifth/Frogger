/*
 * Row.h
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#ifndef ROW_H_
#define ROW_H_
#include "levelGenerator/RowProp.h"

class Row
{
public:
	Row(bool direction, int speed, int divider, int locY, int height,int number,
			char type, int ObsticleSpawnChance,	int itemSpawnChance,int shootChance,bool obstacleVis,
			bool laneVis,int aROS, int aROE,int aRLS,int aRLE);
	Row(bool direction, int locY, int height,int number,RowProp* rowProperties);
	virtual ~Row();
	bool isDirLeft() const;
	int getLocY() const;
	int getNumber() const;
	int getSpeed() const;
	int getHeight() const;
	bool isLaneRow() const;
	void setLaneRow(bool laneRow);
	int getDivider() const;
	void setDivider(int divider);
	int getItemSpawnChance() const;
	int getItemTypeChance() const;
	int getObsticleSpawnChance() const;
	int getShootChance() const;
	int getTextureRangeE() const;
	int getTextureRangeS() const;
	char getType() const;
	void setSpeed(int speed);
	void setLocY(int locY);
	Row* clone();

	bool isLaneVis() const
	{
		return laneVis;
	}

	bool isObstacleVis() const
	{
		return obstacleVis;
	}

	int getRle() const;
	int getRls() const;
	int getRoe() const;
	int getRos() const;

private:
	bool direction;
	bool laneRow;
	int speed;
	int divider;
	int locY;
	int height;
	int number;
	char type;
	int aROS=0;//animator range obstacle start
	int aROE=0;
	int aRLS=0; //animator range Lane start
	int aRLE=0;
	int ObsticleSpawnChance;
	int itemSpawnChance;
	int shootChance;
	int itemTypeChance=0;
	bool obstacleVis;
	bool laneVis;
};

#endif /* ROW_H_ */
