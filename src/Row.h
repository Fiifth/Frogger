/*
 * Row.h
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#ifndef ROW_H_
#define ROW_H_

class Row {
public:
	Row(bool direction,	int speed,	int locY,	int height, int number);
	virtual ~Row();
	bool isDirLeft() const;
	int getLocY() const;
	int getNumber() const;
	int getSpeed() const;
	int getHeight() const;
	bool isLaneRow() const;
	void setLaneRow(bool laneRow);

private:
	bool direction;
	bool laneRow;
	int speed;
	int locY;
	int height;
	int number;
};

#endif /* ROW_H_ */
