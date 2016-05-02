/*
 * Row.h
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#ifndef ROW_H_
#define ROW_H_
#include "levelGenerator/RowProp.h"
namespace frogger
{
class Row
{
public:

	Row(bool direction, int locY, int height,int number,const RowProp* rowProperties);
	virtual ~Row();
	bool isDirLeft() const;
	int getLocY() const;
	int getNumber() const;
	int getSpeed() const;
	int getHeight() const;
	int getDivider() const;
	int getItemRate() const;
	int getObsticleRate() const;
	int getShootRate() const;
	char getType() const;
	void setLocY(int locY);
	Row* clone();
	bool isLaneVis() const;
	bool isObstacleVis() const;
	const RowProp* getRowProperties() const;
	void setRowProperties(const RowProp* rowProp);
	int getRandomObsInd();
	int getRandomLaneInd();

private:
	bool direction;
	int locY;
	int height;
	int number;
	const RowProp* rowProperties;

};
}
#endif /* ROW_H_ */
