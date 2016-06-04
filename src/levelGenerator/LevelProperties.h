/*
 * LevelProperties.h
 *
 *  Created on: 23-apr.-2016
 *      Author: msn-w
 */

#ifndef LEVELGENERATOR_LEVELPROPERTIES_H_
#define LEVELGENERATOR_LEVELPROPERTIES_H_
#include "RowProp.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
namespace frogger
{
	class LevelProperties
	{
		public:
			LevelProperties(char mode, char difficulty);
			virtual ~LevelProperties();
			void easyLevel();
			void mediumLevel();
			void hardLevel();
			RowProp* getFirstRow();
			RowProp* getLastRow();
			RowProp* getMiddleRow();
			RowProp* getSeg1();
			RowProp* getSeg2();
			RowProp* getSeg3();
			RowProp* getSeg4();
			std::vector<int> getVec(int a, int b);
			char getMode() const;
			void setMode(char mode);
			RowProp* getRandomRow();
			void levelUp();
			char getDifficulty();

		private:
			RowProp* firstRow;
			RowProp* lastRow;
			RowProp* middleRow;
			RowProp* seg1;
			RowProp* seg2;
			RowProp* seg3;
			RowProp* seg4;
			char mode;
			int level;
			char difficulty;
	};
}

#endif /* LEVELGENERATOR_LEVELPROPERTIES_H_ */
