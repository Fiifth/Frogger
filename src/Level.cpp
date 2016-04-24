/*
 * Level.cpp
 *
 *  Created on: 8-apr.-2016
 *      Author: msn-w
 */

#include <Level.h>
#include <levelGenerator/levelProperties.h>
#include "levelGenerator/RowProp.h"

Level::Level(Factory* F, Window* win, list<Player*>* players, int rowHeight,
		int difficulty) :
		F(F), win(win), players(players), difficulty(difficulty)
{
	rowGenerator(rowHeight, win->getGameWindowHeight(), difficultyRows, F, rows,
			propsOnRow);
	fillEnemyList(F, rows, propsOnRow, win->getWidth());
}

Level::~Level()
{
}
char Level::levelExecution(string keyStroke)
{
	for (Player* player : *players)
	{
		if(player->getRemainingTime()==0)
			player->hit();
		else
		player->takeAction(keyStroke);
	}
	if (keyStroke=="P")
		increaseSpeed(rows);

	win->generateBackground(rows);
	propsGenerator(F, rows, propsOnRow);
	collisionDetection(propsOnRow, projectiles, players);
	drawGameElements(propsOnRow, projectiles, players, rows);
	objectiveDone=objectiveCompleteCheck(propsOnRow);

	return 'H';
}

void Level::rowGenerator(int rowHeight, int screenHight, int difficultyRows,
		Factory* F, vector<Row*>* rows, vector<list<Props*>>* propsOnRow)
{
	int maxSpeed = 3;
	int divider = 0;
	int numberOfRows = (screenHight) / rowHeight;
	int mode = 3;
	list<Props*> enemies;
	bool dir = true; //(rand() %2)>0)
	LevelProperties* lvlprop=new LevelProperties();
	const RowProp* rowProp;
	if (mode == 3)
	{
		for (int n = 0; n < numberOfRows; n++)
		{
			/*
			 * A: start row
			 * B: obst row
			 * C: lane row
			 * D: forest row
			 * E: end row
			 */
//			int speed = 1;
//			char type='B';
//
//			type=n < (numberOfRows / 2)?'C':type;
//			type=n ==(numberOfRows / 2)?'D':type;
//			type=(n == 0)?'A':type;
//			type=(n == numberOfRows - 1)?'E':type;
//			speed = (type == 'A' || type=='E'||type=='D') ? 0 : speed;
//			rows->push_back(F->createRow(dir, speed, divider, (n * rowHeight),rowHeight, n,type,50,50,50));
//			propsOnRow->push_back(enemies);
//			dir = not (dir);
			if(n==0)
			{
				rowProp=lvlprop->getLastRow();
				cout<<rowProp->getItemRate();

			}
			else if (n==(numberOfRows-1))
			{
				rowProp=lvlprop->getFirstRow();
			}
			else if (n==numberOfRows / 2)
			{
				rowProp=lvlprop->getMiddleRow();

			}
			else if (n < (numberOfRows / 2))
			{
				rowProp=lvlprop->getSeg3();
			}
			else if (n>(numberOfRows / 2))
			{
				rowProp=lvlprop->getSeg1();
			}

			rows->push_back(F->createRow(dir, n * rowHeight, rowHeight, n,rowProp));
			propsOnRow->push_back(enemies);
			dir = not (dir);
		}
	}
}

void Level::propsGenerator(Factory* F, vector<Row*>* rows,
		vector<list<Props*>>* propsOnRow)
{
	for (Row* row : *rows)
	{
		if ((row->getType()=='B') || (row->getType()=='C'))
		{
			list<Props*>* PreProp = &propsOnRow->at(row->getNumber());
			if ((PreProp->empty()) || ((PreProp->front())->isRoom()))
			{
				Props* prop=obsOrLane(PreProp,row, true,-99);
				propsOnRow->at(row->getNumber()).push_front(prop);
			}
		}
	}
}

int Level::collisionDetection(vector<list<Props*>>* propsOnRow,
		list<Projectile*>*projectiles, list<Player*>* players)
{
	for (list<Props*> temp : *propsOnRow)
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

void Level::fillEnemyList(Factory* F, vector<Row*>* rows,
		vector<list<Props*>>* propsOnRow, int screenWidth)
{
	list<Props*> listOfProps;
	for (Row* row : *rows)
	{
		int x = 0;
		while (x < screenWidth)
		{
			if ((row->getType()=='B') || (row->getType()=='C')||row->getType()=='D'||row->getType()=='E')
			{
				list<Props*>* PreProp = &propsOnRow->at(row->getNumber());
				Props* prop=obsOrLane(PreProp,row, row->isDirLeft(),x);
				if (row->isDirLeft())
					propsOnRow->at(row->getNumber()).push_front(prop);
				else
					propsOnRow->at(row->getNumber()).push_back(prop);

				x = prop->getW() + x;
			}
			else
				x = screenWidth;
		}
	}
}

void Level::drawGameElements(std::vector<std::list<Props*>>* propsOnRow,
		list<Projectile*>* projectiles, list<Player*>* players,
		vector<Row*>* rows)
{
	int i = 0;

	for (list<Props*> temp : *propsOnRow)
	{
		propsOnRow->at(i).remove_if(drawMoveRemove());
		i++;
	}

	for (Player* player : *players)
	{
		int row = player->getY() / player->getH();
		if (row == 0)
		{
			player->addScore(100);
			player->resetPosition();
		}
		player->draw();
	}
}

Props* Level::obsOrLane(list<Props*>* PreProp, Row* row, bool frontOrBack,int x)
{
	Props* prop;
	int number = rand() % 100;
	int laneRow=row->getType()=='C';
	if (frontOrBack)
	{

		if ((laneRow && PreProp->front()->isVisible())|| ((number < row->getObsticleRate()) && !PreProp->front()->isVisible()))
		{
			if (x==-99)
				prop = F->createObstacle(row,row->isObstacleVis());
			else
				prop = F->createObstacle(row,row->isObstacleVis(), x, 5, 0, row->getHeight());
		}
		else
		{
			if (x==-99)
				prop = F->createLane(row,row->isLaneVis());
			else
				prop = F->createLane(row,row->isLaneVis(), x, 5, 0, row->getHeight());
		}
	}
	else
	{
		if((laneRow && PreProp->back()->isVisible())|| ((number < row->getObsticleRate()) && !PreProp->back()->isVisible()))
			prop = F->createObstacle(row,row->isObstacleVis(), x, 5, 0, row->getHeight());
		else
			prop = F->createLane(row,row->isLaneVis(), x, 5, 0, row->getHeight());
	}
	return prop;
}

bool Level::increaseSpeed(vector<Row*>* rows)
{
	for (Row* row : *rows)
	{
		row->setLocY(row->getLocY()+1);
	}

	return true;
}

bool Level::isObjectiveDone() const
{
	return objectiveDone;
}

bool Level::objectiveCompleteCheck(std::vector<std::list<Props*> >* propsOnRow)
{
	bool ready=true;
	for(Props* prop:propsOnRow->at(0))
	{
		ready=prop->itemListEmpty()&&ready?true:false;
	}
	return ready;
}
