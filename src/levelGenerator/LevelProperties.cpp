/*
 * LevelProperties.cpp
 * Keeps a list of all the animators for every kind of entity.
 * Keeps 7 kinds of rowprop objects. They will be given to the correct row objects by using this levelproperties object.
 *
 *  Created on: 23-apr.-2016
 *      Author: msn-w
 */

#include <levelGenerator/LevelProperties.h>
#include <iostream>
using namespace frogger;

LevelProperties::LevelProperties(char mode, char difficulty) :
		mode(mode), difficulty(difficulty)
{
	obstiAni=	{getAnimator({0},{0}),getAnimator({1},{0}),getAnimator({2},{0}),
				getAnimator({3},{0}),getAnimator({4},{0}),getAnimator({5},{0}),
				getAnimator({6},{0}),getAnimator({7},{0}),getAnimator({8},{0}),
				getAnimator({9},{0}),getAnimator({10},{0}),getAnimator({11},{0})};

		laneAni={getAnimator({0,1,2},{40,5,10}),getAnimator({3},{0}),getAnimator({4,5},{20,20}),
				getAnimator({4,5,4,5,6,7,8,9,7,6},{40,40,40,40,30,20,20,-70,10,20})};

		playerAni={getAnimator({0,1},{1,0}),getAnimator({2,3},{1,0}),getAnimator({4,5},{1,0})};

		itemAni={getAnimator({0},{0}),getAnimator({1},{0}),getAnimator({2},{0})};

		projAni={getAnimator({0},{0})};

	level=1;

	firstRow = new RowProp(0, 0, 'A', mode, 0, 0, 0, true, false, { 1 }, { 0 }, { 10, 20, 70 });
	lastRow = new RowProp(0, 0, 'E', mode, 100, 100, 0, true, false, getVec(9, 10), { 2 }, { 10, 20, 70 });
	middleRow = new RowProp(0, 0, 'D', mode, 50, 50, 0, true, false, getVec(9, 10), { 0 }, { 10, 20, 70 });

	if (difficulty == 'E')
		easyLevel();
	else if (difficulty == 'M')
		mediumLevel();
	else if (difficulty == 'H')
		hardLevel();
}

LevelProperties::~LevelProperties()
{
	delete(firstRow);
	delete(lastRow);
	delete(middleRow);
	delete(seg1);
	delete(seg2);
	delete(seg3);
	delete(seg4);
}

void LevelProperties::easyLevel()
{
	seg1 = new RowProp(1, 1, 'B', mode, 40, 20, 0, true, false, getVec(0, 4), {0, 1, 2}, { 10, 30, 70 });
	seg2 = new RowProp(1, 0, 'B', mode, 50, 5, 20, true, false, getVec(0, 4), {0, 1, 2}, { 10, 20, 70 });
	seg3 = new RowProp(1, 1, 'C', mode, 40, 20, 70, false, true, getVec(0, 4), {0, 1, 2}, { 10, 20, 70 });
	seg4 = new RowProp(1, 0, 'C', mode, 50, 5, 70, false, true, getVec(0, 4), {0, 1, 2}, { 10, 20, 70 });
}
void frogger::LevelProperties::mediumLevel()
{
	seg1 = new RowProp(1, 1, 'B', mode, 40, 30, 0, true, false, getVec(0, 6), {0, 1, 2, 3 }, { 10, 30, 70 });
	seg2 = new RowProp(1, 0, 'B', mode, 50, 10, 20, true, false, getVec(0, 6), {0, 1, 2, 3 }, { 10, 20, 70 });
	seg3 = new RowProp(1, 1, 'C', mode, 40, 30, 70, false, true, getVec(0, 6), {0, 1, 2, 3 }, { 10, 20, 70 });
	seg4 = new RowProp(1, 0, 'C', mode, 50, 10, 70, false, true, getVec(0, 6), {0, 1, 2, 3 }, { 10, 20, 70 });
}

void frogger::LevelProperties::hardLevel()
{
	seg1 = new RowProp(1, 1, 'B', mode, 40, 40, 0, true, false, getVec(0, 8), {0, 1, 2, 3 }, { 10, 30, 70 });
	seg2 = new RowProp(1, 0, 'B', mode, 50, 15, 20, true, false, getVec(0, 8), {0, 1, 2, 3 }, { 10, 20, 70 });
	seg3 = new RowProp(1, 1, 'C', mode, 40, 40, 70, false, true, getVec(0, 8), {0, 1, 2, 3 }, { 10, 20, 70 });
	seg4 = new RowProp(1, 0, 'C', mode, 50, 15, 70, false, true, getVec(0, 8), {0, 1, 2, 3 }, { 10, 20, 70 });
}

RowProp* LevelProperties::getFirstRow()
{
	return firstRow;
}

RowProp* LevelProperties::getLastRow()
{
	return lastRow;
}

RowProp* LevelProperties::getMiddleRow()
{
	return middleRow;
}

RowProp* LevelProperties::getSeg1()
{
	return seg1;
}

RowProp* LevelProperties::getSeg2()
{
	return seg2;
}

RowProp* LevelProperties::getSeg3()
{
	return seg3;
}

RowProp* LevelProperties::getSeg4()
{
	return seg4;
}

std::vector<int> LevelProperties::getVec(int a, int b)
{
	std::vector<int> temp;
	for (int i = a; i <= b; i++)
	{
		temp.push_back(i);
	}
	return temp;

}

char LevelProperties::getMode() const
{
	return mode;
}

void LevelProperties::setMode(char mode)
{
	this->mode = mode;
}

RowProp* LevelProperties::getRandomRow()
{
	int temp = rand() % 110;
	if (temp < 25)
		return seg1;
	else if (temp < 50)
		return seg2;
	else if (temp < 75)
		return seg3;
	else if (temp < 100)
		return seg4;
	else
		return middleRow;
}

void frogger::LevelProperties::levelUp()
{
	//int deltaSpe, int deltaDiv,	int deltaObsRate, int deltaItemRate, int deltaShootRate
	level = level + 1;

	if (level == 2)
	{
		seg1->increaseProp(0, 0, 10, -1, 2);
		seg2->increaseProp(0, 0, 10, -1, 2);
		seg3->increaseProp(0, 0, 10, -1, 2);
		seg4->increaseProp(0, 0, 10, -1, 2);
	}
	else if (level == 3)
	{
		seg1->increaseProp(0, -1, 0, -1, 0);
		seg2->increaseProp(2, 1, 0, -1, 0);
		seg3->increaseProp(0, -1, 0, -1, 0);
		seg4->increaseProp(2, 1, 0, -1, 0);
	}
	else if (level == 4)
	{
		seg1->increaseProp(0, 0, 5, -2, 3);
		seg2->increaseProp(0, 0, 5, -2, 3);
		seg3->increaseProp(0, 0, 5, -2, 3);
		seg4->increaseProp(0, 0, 5, -2, 3);
	}
	else if (level == 5)
	{
		seg1->increaseProp(2, 1, 0, 0, 0);
		seg2->increaseProp(-1, -1, 0, 0, 0);
		seg3->increaseProp(2, 1, 0, 0, 0);
		seg4->increaseProp(-1, -1, 0, 0, 0);
	}
	else if (level == 6)
	{
		seg1->increaseProp(0, 0, 4, -2, 4);
		seg2->increaseProp(0, 0, 4, -2, 4);
		seg3->increaseProp(0, 0, 4, -2, 4);
		seg4->increaseProp(0, 0, 4, -2, 4);
	}
	else if (level == 7)
	{
		seg1->increaseProp(-1, -1, 0, 0, 0);
		seg2->increaseProp(3, 1, 0, 0, 0);
		seg3->increaseProp(-1, -1, 0, 0, 0);
		seg4->increaseProp(3, 1, 0, 0, 0);
	}
	else if (level == 8)
	{
		seg1->increaseProp(0, 0, 3, -2, 5);
		seg2->increaseProp(0, 0, 3, -2, 5);
		seg3->increaseProp(0, 0, 3, -2, 5);
		seg4->increaseProp(0, 0, 3, -2, 5);
	}
	else if (level == 9)
	{
		seg1->increaseProp(3, 1, 0, 0, 0);
		seg2->increaseProp(-2, -1, 0, 0, 0);
		seg3->increaseProp(3, 1, 0, 0, 0);
		seg4->increaseProp(-2, -1, 0, 0, 0);
	}
	else if (level == 10)
	{
		seg1->increaseProp(0, 0, 2, -2, 6);
		seg2->increaseProp(0, 0, 2, -2, 6);
		seg3->increaseProp(0, 0, 2, -2, 6);
		seg4->increaseProp(0, 0, 2, -2, 6);
	}
	else if (level == 11)
	{
		seg1->increaseProp(-2, -1, 0, 0, 0);
		seg2->increaseProp(0, 0, 0, 0, 0);
		seg3->increaseProp(-2, -1, 0, 0, 0);
		seg4->increaseProp(0, 0, 0, 0, 0);
	}
	else if (level == 12)
	{
		seg1->increaseProp(0, 0, 0, 0, 0);
		seg2->increaseProp(0, 0, 0, 0, 0);
		seg3->increaseProp(0, 0, 0, 0, 0);
		seg4->increaseProp(0, 0, 0, 0, 0);
	}
	else if (level == 13)
	{
		seg1->increaseProp(0, 0, 0, 0, 0);
		seg2->increaseProp(0, 0, 0, 0, 0);
		seg3->increaseProp(0, 0, 0, 0, 0);
		seg4->increaseProp(0, 0, 0, 0, 0);
	}
	else if (level == 14)
	{
		seg1->increaseProp(0, 0, 0, 0, 0);
		seg2->increaseProp(0, 0, 0, 0, 0);
		seg3->increaseProp(0, 0, 0, 0, 0);
		seg4->increaseProp(0, 0, 0, 0, 0);
	}
	else if (level == 15)
	{
		seg1->increaseProp(0, 0, 0, 0, 10);
		seg2->increaseProp(0, 0, 0, 0, 10);
		seg3->increaseProp(0, 0, 0, 0, 10);
		seg4->increaseProp(0, 0, 0, 0, 10);
	}
}

char frogger::LevelProperties::getDifficulty()
{
	return difficulty;
}

std::vector<frogger::Animator>* frogger::LevelProperties::getItemAni()
{
	return &itemAni;
}

frogger::Animator frogger::LevelProperties::getLaneAni(int ind)
{
	return laneAni.at(ind);
}

frogger::Animator frogger::LevelProperties::getObstiAni(int ind)
{
	return obstiAni.at(ind);
}

frogger::Animator frogger::LevelProperties::getPlayerAni(int ind)
{
	return playerAni.at(ind);
}

std::vector<frogger::Animator>* frogger::LevelProperties::getProjAni()
{
	return &projAni;
}

frogger::Animator frogger::LevelProperties::getAnimator(
		std::vector<int> indexes, std::vector<int> ratio)
{
	frogger::Animator temp(indexes, ratio);
	return temp;
}
