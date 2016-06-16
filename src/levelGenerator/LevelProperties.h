/*
 * LevelProperties.h
 *
 *  Created on: 23-apr.-2016
 *      Author: Kwinten
 */

#ifndef LEVELGENERATOR_LEVELPROPERTIES_H_
#define LEVELGENERATOR_LEVELPROPERTIES_H_
#include "levelGenerator/RowProp.h"
#include <vector>
#include <stdlib.h>
#include <Abstract/Animator.h>
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

			frogger::Animator getLaneAni(int ind);
			frogger::Animator getObstiAni(int ind);
			frogger::Animator getPlayerAni(int ind);

			std::vector<frogger::Animator>* getItemAni();
			std::vector<frogger::Animator>* getProjAni();


			std::vector<int> getVec(int a, int b);
			char getMode() const;
			void setMode(char mode);
			RowProp* getRandomRow();
			void levelUp();
			char getDifficulty();
			frogger::Animator getAnimator(std::vector<int> indexes,	std::vector<int> ratio);

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
			std::vector<frogger::Animator> obstiAni;
			std::vector<frogger::Animator> laneAni;
			std::vector<frogger::Animator> playerAni;
			std::vector<frogger::Animator> itemAni;
			std::vector<frogger::Animator> projAni;
	};
}

#endif /* LEVELGENERATOR_LEVELPROPERTIES_H_ */
