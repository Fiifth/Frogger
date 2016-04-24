/*
 * LevelProperties.h
 *
 *  Created on: 23-apr.-2016
 *      Author: msn-w
 */

#ifndef LVLPROP_H_
#define LVLPROP_H_
#include <vector>

class RowProp
{
public:
	RowProp(int speed,int divider,char type,int obstRate,int itemRate,
			int shootRate, bool obstacleVis,bool laneVis,std::vector<int> obstIndexes,
			std::vector<int> laneIndexes,std::vector<int> itemTypeChance);
	virtual ~RowProp();
	int getDivider() const;
	int getItemRate() const;
	int getObsticleRate() const;
	int getShootRate() const;
	int getSpeed() const;
	char getType() const;
	bool getLaneVis() const;
	bool getObstacleVis() const;
	const std::vector<int>& getItemTypeChance() const;
	const std::vector<int>& getLaneIndexes() const;
	const std::vector<int>& getObstIndexes() const;

	int speed;
	int divider;
	char type;
	int obstRate;
	int itemRate;
	int shootRate;
	bool obstacleVis;
	bool laneVis;
	std::vector<int> obstIndexes;
	std::vector<int> laneIndexes;
	std::vector<int> itemTypeChance;
};

#endif /* LVLPROP_H_ */
