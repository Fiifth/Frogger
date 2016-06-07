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
			Row(char direction, int locY, int height, int number,	RowProp* rowProperties);
			virtual ~Row();
			bool isDirLeft() const;
			int getNumber() const;
			int* getSpeed() const;
			int getHeight() const;
			int* getLocY();
			void setLocY(int NewlocY);
			char getType();
			Row* clone();
			bool isLaneVis() const;
			bool isObstacleVis() const;
			RowProp* getRowProperties();
			void setRowProperties(RowProp* rowProp);
			int getRandomObsInd();
			int getRandomLaneInd();
			char* getDirection();
			void setDirection(char direction);
			int* getYP();

		private:
			char direction;
			int locY;
			int height;
			int number;
			RowProp* rowProperties;
	};
}
#endif /* ROW_H_ */
