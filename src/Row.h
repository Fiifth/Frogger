/*
 * Row.h
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#ifndef ROW_H_
#define ROW_H_

class Row
{
public:
	Row(bool direction, int speed, int divider, int locY, int height,int number,
			char type, int ObsticleSpawnChance,	int itemSpawnChance,int shootChance);
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

private:
	bool direction;
	bool laneRow;
	int speed;
	int divider;
	int locY;
	int height;
	int number;
	char type;
	int textureRangeS=0;
	int textureRangeE=0;
	int ObsticleSpawnChance;
	int itemSpawnChance;
	int shootChance;
	int itemTypeChance=0;
};

#endif /* ROW_H_ */
