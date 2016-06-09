/*
 * Level.cpp
 *
 * This object will execute the playing part of the game.
 * It creates and manages the entities by moving them and checking for collision.
 *
 *  Created on: 8-apr.-2016
 *      Author: msn-w
 */

#include <Level.h>
#include <levelGenerator/levelProperties.h>
#include "levelGenerator/RowProp.h"
using namespace frogger;

Level::Level(Factory* F, Window* win, std::list<Player*>* players, int rowHeight,
		LevelProperties* lvlprop) :
		F(F), win(win), players(players), rowHeight(rowHeight), lvlprop(lvlprop)
{
	initLevel();
}

Level::~Level()
{
	for(std::list<Props*> props:*propsOnRow)
	{
		for(Props* prop:props)
			delete(prop);
		props.clear();
	}
	propsOnRow->clear();

	for(Row* row:*rows)
		delete(row);
	rows->clear();
}
void Level::levelExecution(std::string keyStroke)
{
	int factor = 3;
	int freeRows = 4;
	freeRows = (lvlprop->getDifficulty() == 'M') ? 3 : freeRows;
	freeRows = (lvlprop->getDifficulty() == 'H') ? 2 : freeRows;
	for (Player* player : *players)
	{
		int tempFactor = 0;
		if (player->getRemainingTime() == 0)
			player->hit();
		else
		{
			player->takeAction(keyStroke);
		}
		if (lvlprop->getMode() == 'E'	&& player->getY()	< *win->getGameWindowHeight() - rowHeight * freeRows)
		{
			tempFactor = 1;
			tempFactor =player->getY()< *win->getGameWindowHeight()- rowHeight * (freeRows + 1) ?	2 : tempFactor;
			tempFactor =player->getY()< *win->getGameWindowHeight()- rowHeight * (freeRows + 2) ? 3 : tempFactor;
			tempFactor =player->getY()< *win->getGameWindowHeight()- rowHeight * (freeRows + 3) ?	4 : tempFactor;
		}
		if (!player->isDead())
			factor = (factor > tempFactor) ? tempFactor : factor;
	}
	if (lvlprop->getMode() == 'E')
		followFrog(rows, players, factor);

	if (lvlprop->getMode() == 'E')
		extraRowNeeded(*win->getGameWindowHeight(), *win->getWidth(),
				F, rows, propsOnRow, lvlprop);

	win->generateBackground(rows);

	propsGenerator(F, rows, propsOnRow);

	drawGameElements(propsOnRow, players);
	collisionDetection(propsOnRow, players);
	objectiveDone =	lvlprop->getMode() == 'E' ?	false : objectiveCompleteCheck(propsOnRow);
}

void Level::rowGenerator(int rowHeight, int screenHight, Factory* F,
		std::vector<Row*>* rows, std::vector<std::list<Props*>>* propsOnRow,
		LevelProperties* lvlprop)
{
	int numberOfRows = (screenHight) / rowHeight;
	std::list<Props*> enemies;
	char dir = 'L';
	RowProp* rowProp;
	if (lvlprop->getMode() == 'E')
	{
		for (int n = 0; n < numberOfRows + 2; n++)
		{
			int yloc;
			yloc = (screenHight - rowHeight) - (n * rowHeight);
			if (n == (0))
				rowProp = lvlprop->getFirstRow();
			else
				rowProp = lvlprop->getRandomRow();

			rows->push_back(F->createRow(dir, yloc, rowHeight, n, rowProp));
			propsOnRow->push_back(enemies);
			dir = dir == 'R' ? 'L' : 'R';
		}
	}
	else
	{
		for (int n = 0; n < numberOfRows; n++)
		{

			if (n == 0)
				rowProp = lvlprop->getLastRow();
			else if (n == (numberOfRows - 1))
				rowProp = lvlprop->getFirstRow();
			else if (n == numberOfRows / 2)
				rowProp = lvlprop->getMiddleRow();

			else if (n <= (numberOfRows / 4))
				rowProp = lvlprop->getSeg4();
			else if (n <= (numberOfRows / 2))
				rowProp = lvlprop->getSeg3();

			else if (n < (3 * numberOfRows / 4))
				rowProp = lvlprop->getSeg2();
			else if (n <= (numberOfRows))
				rowProp = lvlprop->getSeg1();

			rows->push_back(F->createRow(dir, n * rowHeight, rowHeight, n, rowProp));
			propsOnRow->push_back(enemies);
			dir = dir == 'R' ? 'L' : 'R';
		}
	}
}

void Level::propsGenerator(Factory* F, std::vector<Row*>* rows,
		std::vector<std::list<Props*>>* propsOnRow)
{
	for (Row* row : *rows)
	{
		if ((row->getRowProperties()->getType() == 'B')
				|| (row->getRowProperties()->getType() == 'C'))
		{
			std::list<Props*>* PreProp = &propsOnRow->at(row->getNumber());
			if ((PreProp->empty()) || ((PreProp->front())->isRoom()))
			{
				Props* prop = obsOrLane(PreProp, row);
				propsOnRow->at(row->getNumber()).push_front(prop);
			}
		}
	}
}

int Level::collisionDetection(std::vector<std::list<Props*>>* propsOnRow, std::list<Player*>* players)
{
	for (std::list<Props*> temp : *propsOnRow)
	{
		for (Props* temp2 : temp)
		{
			for (Player* player : *players)
			{
				temp2->collision(player);
			}
		}
	}
	for (Player* playerx : *players)
		for (Player* playery : *players)
			playerx->collision(playery);
	return false;
}

void Level::fillEnemyList(Factory* F, std::vector<Row*>* rows,
		std::vector<std::list<Props*>>* propsOnRow, int screenWidth)
{
	for (Row* row : *rows)
	{
		fillOneRow(F, row, propsOnRow, screenWidth);
	}
}

void Level::drawGameElements(std::vector<std::list<Props*>>* propsOnRow, std::list<Player*>* players)
{
	int i = 0;

	for (std::list<Props*> temp : *propsOnRow)
	{
		propsOnRow->at(i).remove_if(drawMoveRemove());
		i++;
	}

	for (Player* player : *players)
	{
		player->draw();
	}
}

Props* Level::obsOrLane(std::list<Props*>* PreProp, Row* row, bool frontOrBack, int x)
{
	Props* prop;
	int number = rand() % 100;
	int laneRow = row->getRowProperties()->getType() == 'C';

	if (frontOrBack)
	{
		bool prevVisible =
				PreProp->empty() ? true : PreProp->front()->isVisible();
		if ((laneRow && prevVisible)
				|| ((number < row->getRowProperties()->getObsticleRate())	&& !prevVisible))
		{
			Obstacle* obs=F->createObstacle1();
			obs->setF(F);
			obs->setProjAniList(lvlprop->getProjAni());
			obs->setAni(lvlprop->getObstiAni(row->getRandomObsInd()).clone());
			obs->queryW(row->getHeight());
			obs->setProperties(row, win->getWidth(), win->getGameWindowHeight(),x, obs->getW(), row->isObstacleVis());
			prop=obs;
		}
		else
		{
			Lane* lane=F->createLane1();
			lane->setF(F);
			lane->setItemAniList(lvlprop->getItemAni());
			lane->setAni(lvlprop->getLaneAni((row->getRandomLaneInd())).clone());
			lane->queryW(row->getHeight());
			lane->setProperties(row,  win->getWidth(), win->getGameWindowHeight(), x,lane->getW(), row->isLaneVis());
			lane->spawnItem();
			prop=lane;
		}

	}
	else
	{
		bool prevVisible = PreProp->empty() ? true : PreProp->back()->isVisible();
		if ((laneRow && prevVisible)|| ((number < row->getRowProperties()->getObsticleRate())	&& !prevVisible))
		{
			Obstacle* obs=F->createObstacle1();
			obs->setF(F);
			obs->setProjAniList(lvlprop->getProjAni());
			obs->setAni(lvlprop->getObstiAni(row->getRandomObsInd()).clone());
			obs->queryW(row->getHeight());
			obs->setProperties(row, win->getWidth(), win->getGameWindowHeight(),x, obs->getW(), row->isObstacleVis());
			prop=obs;
		}
		else
		{
			Lane* lane=F->createLane1();
			lane->setF(F);
			lane->setItemAniList(lvlprop->getItemAni());
			lane->setAni(lvlprop->getLaneAni((row->getRandomLaneInd())).clone());
			lane->queryW(row->getHeight());
			lane->setProperties(row,  win->getWidth(), win->getGameWindowHeight(), x,lane->getW(), row->isLaneVis());
			lane->spawnItem();
			prop=lane;
		}
	}
	return prop;
}

bool Level::followFrog(std::vector<Row*>* rows, std::list<Player*>* players, int factor)
{
	for (Row* row : *rows)
	{
		row->setLocY(*row->getLocY() + factor);
	}
	for (Player* player : *players)
	{
		player->followScreen(factor);
	}
	return true;
}

bool Level::isObjectiveDone() const
{
	return objectiveDone;
}

bool Level::objectiveCompleteCheck(std::vector<std::list<Props*> >* propsOnRow)
{
	bool ready = true;
	for (Props* prop : propsOnRow->at(0))
	{
		if(prop->getX()<=(*win->getWidth()-prop->getW()))
		ready = prop->itemListEmpty() && ready ? true : false;
	}
	return ready;
}

void Level::resetLevel()
{
	rows->clear();
	propsOnRow->clear();
	initLevel();
}

void Level::initLevel()
{
	rowGenerator(rowHeight, *win->getGameWindowHeight(), F, rows, propsOnRow,	lvlprop);
	fillEnemyList(F, rows, propsOnRow, *win->getWidth());
}

void Level::extraRowNeeded(int screenHeight, int screenWidth,
		Factory* F, std::vector<Row*>* rows, std::vector<std::list<Props*>>* propsOnRow,
		LevelProperties* lvlprop)
{
	Row* lowestRow = rows->back();
	Row* highestRow = rows->back();
	for (Row* row : *rows)
	{
		if (*row->getLocY() < *lowestRow->getLocY())
		{
			lowestRow = row;
		}
		else if (*row->getLocY() > *highestRow->getLocY())
		{
			highestRow = row;
		}
	}
	if (*highestRow->getLocY() > screenHeight+highestRow->getHeight())
	{
		highestRow->setLocY(*lowestRow->getLocY() - lowestRow->getHeight());
		highestRow->setRowProperties(lvlprop->getRandomRow());
		propsOnRow->at(highestRow->getNumber()).clear();
		fillOneRow(F, highestRow, propsOnRow, screenWidth);
	}
}

Props* Level::obsOrLane(std::list<Props*>* PreProp, Row* row)
{
	Props* prop;
	int number = rand() % 100;
	int laneRow = row->getRowProperties()->getType() == 'C';

	bool prevVisible = PreProp->empty() ? true : PreProp->front()->isVisible();
	if ((laneRow && prevVisible) || ((number < row->getRowProperties()->getObsticleRate()) && !prevVisible))
	{
		Obstacle* obs=F->createObstacle1();
		obs->setF(F);
		obs->setProjAniList(lvlprop->getProjAni());
		obs->setAni(lvlprop->getObstiAni(row->getRandomObsInd()).clone());
		obs->queryW(row->getHeight());
		obs->setProperties(row, win->getWidth(), win->getGameWindowHeight(),row->isDirLeft() ? *win->getWidth() : -obs->getW(), obs->getW(), row->isObstacleVis());
		prop=obs;
	}
	else
	{
		Lane* lane=F->createLane1();
		lane->setF(F);
		lane->setItemAniList(lvlprop->getItemAni());
		lane->setAni(lvlprop->getLaneAni((row->getRandomLaneInd())).clone());
		lane->queryW(row->getHeight());
		lane->setProperties(row, win->getWidth(), win->getGameWindowHeight(), row->isDirLeft() ? *win->getWidth() : -lane->getW(), lane->getW(), row->isLaneVis());
		lane->spawnItem();
		prop=lane;
	}

	return prop;
}

void Level::fillOneRow(Factory* F, Row* row,
		std::vector<std::list<Props*> >* propsOnRow, int screenWidth)
{
	std::list<Props*> listOfProps;
	int x = 0;
	while (x < screenWidth)
	{
		if ((row->getRowProperties()->getType() == 'B')
				|| (row->getRowProperties()->getType() == 'C')
				|| row->getRowProperties()->getType() == 'D'
				|| row->getRowProperties()->getType() == 'E')
		{
			std::list<Props*>* PreProp = &propsOnRow->at(row->getNumber());

			Props* prop = obsOrLane(PreProp, row, row->isDirLeft(), x);
			if (row->isDirLeft())
				propsOnRow->at(row->getNumber()).push_front(prop);
			else
				propsOnRow->at(row->getNumber()).push_back(prop);

			x = prop->getW() + x;
		}
		else
		{
			x = screenWidth;
		}
	}
}

bool frogger::Level::drawMoveRemove::operator ()(Props* prop) const
{
	bool temp = false;
	if (!prop->inframe())
	{
		temp = true;
		delete (prop);
	}
	else
	{
		prop->moveForward();
		prop->draw();
	}
	return temp;
}
