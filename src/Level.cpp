/*
 * Level.cpp
 *
 *  Created on: 8-apr.-2016
 *      Author: msn-w
 */

#include <Level.h>
#include <levelGenerator/levelProperties.h>
#include "levelGenerator/RowProp.h"

Level::Level(Factory* F, Window* win, list<Player*>* players, int rowHeight,LevelProperties* lvlprop) :
F(F), win(win), players(players), rowHeight(rowHeight),lvlprop(lvlprop)
{
	initLevel();

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
		{
			player->takeAction(keyStroke);
		}
		if (lvlprop->getMode()=='A'&&player->getY()<300)
						followFrog(rows,players); //endless
	}

	if(lvlprop->getMode()=='A')
	extraRowNeeded(rowHeight,win->getGameWindowHeight(),win->getWidth(), F, rows,propsOnRow,lvlprop);

	win->generateBackground(rows);
	propsGenerator(F, rows, propsOnRow);

	drawGameElements(propsOnRow, projectiles, players, rows);
	collisionDetection(propsOnRow, projectiles, players);
	objectiveDone=lvlprop->getMode()=='A'?false:objectiveCompleteCheck(propsOnRow);

	return 'H';
}

void Level::rowGenerator(int rowHeight, int screenHight,
		Factory* F, vector<Row*>* rows, vector<list<Props*>>* propsOnRow,LevelProperties* lvlprop)
{
	int numberOfRows = (screenHight) / rowHeight;
	list<Props*> enemies;
	bool dir = true; //(rand() %2)>0)
	const RowProp* rowProp;
	if (lvlprop->getMode()=='A')
	{
		for (int n = 0; n < numberOfRows+1; n++)
		{
			/*
			 * A: start row
			 * B: obst row
			 * C: lane row
			 * D: forest row
			 * E: end row
			 */
			int yloc;
			yloc=(screenHight-rowHeight)-(n*rowHeight);
			if (n==(0))
				rowProp=lvlprop->getFirstRow();
			else
				rowProp=lvlprop->getSeg1();

			rows->push_back(F->createRow(dir, yloc, rowHeight, n,rowProp));
			propsOnRow->push_back(enemies);
			dir = not (dir);
		}

	}
	else
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
			if(n==0)
				rowProp=lvlprop->getLastRow();
			else if (n==(numberOfRows-1))
				rowProp=lvlprop->getFirstRow();
			else if (n==numberOfRows / 2)
				rowProp=lvlprop->getMiddleRow();
			else if (n < (numberOfRows / 2))
				rowProp=lvlprop->getSeg3();
			else if (n>(numberOfRows / 2))
				rowProp=lvlprop->getSeg1();

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
				Props* prop=obsOrLane(PreProp,row);
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
	for (Row* row : *rows)
	{
		fillOneRow(F, row,	propsOnRow,screenWidth);
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
		bool prevVisible=PreProp->empty()?true:PreProp->front()->isVisible();
		if ((laneRow && prevVisible)|| ((number < row->getObsticleRate()) && !prevVisible))
			prop = F->createObstacle(row,row->isObstacleVis(), x, 5, 0, row->getHeight());
		else
			prop = F->createLane(row,row->isLaneVis(), x, 5, 0, row->getHeight());
	}
	else
	{
		bool prevVisible=PreProp->empty()?true:PreProp->back()->isVisible();
		if((laneRow && prevVisible)|| ((number < row->getObsticleRate()) && !prevVisible))
			prop = F->createObstacle(row,row->isObstacleVis(), x, 5, 0, row->getHeight());
		else
			prop = F->createLane(row,row->isLaneVis(), x, 5, 0, row->getHeight());
	}
	return prop;
}

bool Level::followFrog(vector<Row*>* rows,list<Player*>* players)
{
	for (Row* row : *rows)
	{
		row->setLocY(row->getLocY()+2);
	}
	for (Player* player : *players)
	{
		player->move(0,2,true);
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

void Level::resetLevel()
{
	rows->clear();
	propsOnRow->clear();
	initLevel();
}

void Level::initLevel()
{
	rowGenerator(rowHeight, win->getGameWindowHeight(), F, rows,propsOnRow,lvlprop);
	fillEnemyList(F, rows, propsOnRow, win->getWidth());
}

void Level::extraRowNeeded(int rowHeight,int screenHeight,int screenWidth,
		Factory* F, vector<Row*>* rows, vector<list<Props*>>* propsOnRow,LevelProperties* lvlprop)
{
	if(rows->back()->getLocY()>-10)
	{
		list<Props*> enemies;
		const RowProp* rowProp;
		rowProp=lvlprop->getSeg1();
		rows->push_back(F->createRow(!rows->back()->isDirLeft(), rows->back()->getLocY()-rowHeight, rowHeight, rows->back()->getNumber()+1,rowProp));
		propsOnRow->push_back(enemies);

		fillOneRow(F,rows->back(),propsOnRow,1000);
		if(rows->front()->getLocY()>screenHeight*2)
		rows->erase(rows->begin());
	}
}

Props* Level::obsOrLane(list<Props*>* PreProp, Row* row)
{
	Props* prop;
	int number = rand() % 100;
	int laneRow=row->getType()=='C';

	bool prevVisible=PreProp->empty()?true:PreProp->front()->isVisible();
	if ((laneRow && prevVisible)|| ((number < row->getObsticleRate()) && !prevVisible))
		prop = F->createObstacle(row,row->isObstacleVis());
	else
		prop = F->createLane(row,row->isLaneVis());

return prop;
}

void Level::fillOneRow(Factory* F, Row* row,
		std::vector<std::list<Props*> >* propsOnRow, int screenWidth)
{
	list<Props*> listOfProps;
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
		{
			x = screenWidth;
		}

	}
}
