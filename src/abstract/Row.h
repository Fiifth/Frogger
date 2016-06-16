/*
 * Row.h
 *
 *  Created on: 12-mrt.-2016
 *      Author: Kwinten
 */

#ifndef ABSTRACT_ROW_H_
#define ABSTRACT_ROW_H_
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
			int getHeight() const;
			int* getLocY();
			void setLocY(int NewlocY);
			Row* clone();
			bool isLaneVis() const;
			bool isObstacleVis() const;
			RowProp* getRowProperties();
			void setRowProperties(RowProp* rowProp);
			int getRandomObsInd();
			int getRandomLaneInd();
			char* getDirection();

		private:
			char direction;
			int locY;
			int height;
			int number;
			RowProp* rowProperties;
	};
}
#endif /* ABSTRACT_ROW_H_ */
