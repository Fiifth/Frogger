/*
 * Level.cpp
 *
 *  Created on: 8-apr.-2016
 *      Author: msn-w
 */

#include <Level.h>

Level::Level(Factory* F,Window* win,list<Player*>* players,int rowHeight,int difficulty) :F(F),win(win),players(players),difficulty(difficulty)
{
	rowGenerator(rowHeight,win->getGameWindowHeight(),difficultyRows,F,rows,propsOnRow);
	fillEnemyList(F,rows,propsOnRow, difficulty,win->getWidth());
}

Level::~Level() {
}
char Level::levelExecution(string keyStroke)
{
	for (Player* player:*players)
	{
		if (player->takeAction(keyStroke))
			projectiles->push_back(F->createProjectile(players->back(),5,0));
	}

	win->generateBackground(rows);
	propsGenerator(F,difficulty,rows,propsOnRow);
	collisionDetection(propsOnRow,projectiles,players);
	if(playersAlive(players,'A'))
	{
		drawGameElements(propsOnRow,projectiles, players,rows);
			return 'A';
	}
	else
		return 'B';
}

void Level::rowGenerator(int rowHeight,int screenHight,int difficultyRows,Factory* F,vector<Row*>* rows,vector<list<Props*>>* propsOnRow)
{
	int maxSpeed=3;
	int divider=0;
	int numberOfRows=(screenHight)/rowHeight;
	int mode=3;
	list<Props*> enemies;
	bool dir=true;//(rand() %2)>0)
	if (mode==1)
	{
		for (int n=0; n<numberOfRows; n++)
		{
			int speed=((rand()%(numberOfRows-n))+1)*difficultyRows;
			speed=speed>maxSpeed?maxSpeed:speed;
			speed=(n==0||n==numberOfRows-1)?0:speed;
			rows->push_back(F->createRow(((rand() %10)>5),speed,divider,(n*rowHeight),rowHeight,n));
			propsOnRow->push_back(enemies);
		}
	}
	else if (mode==2)
	{
		for (int n=0; n<numberOfRows; n++)
		{
			int speed=((rand()%(numberOfRows-n))+1)*difficultyRows;
			speed=speed>maxSpeed?maxSpeed:speed;
			speed=(n==0||n==numberOfRows-1)?0:speed;
			rows->push_back(F->createRow(((rand() %10)>5),speed,divider,(n*rowHeight),rowHeight,n));
			rows->back()->setLaneRow(true);
			propsOnRow->push_back(enemies);
		}
	}
	else if (mode==3)
		{
			for (int n=0; n<numberOfRows; n++)
			{
				list<Props*> enemiies;
				int speed=1;
				speed=(n==0||n==numberOfRows-1)?0:speed;
				rows->push_back(F->createRow(dir,speed,divider,(n*rowHeight),rowHeight,n));
				rows->back()->setLaneRow(n<(numberOfRows/2));
				propsOnRow->push_back(enemies);
				dir=not(dir);
			}
		}
}

void Level::propsGenerator(Factory* F,int difficulty,vector<Row*>* rows,vector<list<Props*>>* propsOnRow)
{
	for(Row* row:*rows)
	{
		if((row->getNumber()!=0)&&((unsigned)row->getNumber()!=((rows->size())-1)))
		{
			list<Props*>* PreProp=&propsOnRow->at(row->getNumber());
			if((PreProp->empty())||((PreProp->front())->isRoom()))
			{
				Props* prop;
				if(obsOrLane(PreProp,true,row->isLaneRow(),difficulty))
				{
					prop=F->createObstacle(row);
					prop->setVisible(!row->isLaneRow());
				}
				else
				{
					prop=F->createLane(row);
					prop->setVisible(row->isLaneRow());

				}
				propsOnRow->at(row->getNumber()).push_front(prop);
			}
			bool roomOnLane=PreProp->front()->roomForItem();
			bool noItemYet=PreProp->back()->itemAbsent();
			if (roomOnLane&&noItemYet&&(rand()%1000>995))
			{
				Props* propBonus=F->createItem(row,0);
				propsOnRow->at(row->getNumber()).push_back(propBonus);
			}
			if(rand()%1000>998)
			{
				Props* randomObstable=getRandomObst(PreProp);
				if (randomObstable!=nullptr)
				{
					Props* projec=F->createProjectile(randomObstable,5,0);
					propsOnRow->at(row->getNumber()).push_back(projec);
				}
			}
		}
	}
}


int Level::collisionDetection(vector<list<Props*>>* propsOnRow,list<Projectile*>*projectiles,list<Player*>* players)
{
	int dete=false;
	for (list<Props*> temp:*propsOnRow)
	{
		for(Props* temp2:temp)
		{
			for (Projectile* proj:*projectiles)
			{
				//TODO use remove if
				if(temp2->isVisible()&&temp2->coll(proj,true))
				{
					temp2->setVisible(false);
					temp2->setTurned(true);
					delete (proj);
					projectiles->remove(proj);
				}
			}
			for(Player* player:*players)
			{
				int effect=temp2->coll(player,true);
				if(effect>1)
				{
					propsOnRow->at(temp2->getRow()->getNumber()).remove(temp2);
					delete(temp2);
					dete=effect;
					player->addScore(1);
					player->addProjectiles(1);
				}
				else if (effect==1||player->getRemainingTime()==0)
				{
					player->hit();
				}
			}
		}
	}
	return dete;
}

void Level::fillEnemyList(Factory* F,vector<Row*>* rows, vector<list<Props*>>* propsOnRow, int difficulty,int screenWidth)
{
	list<Props*> listOfProps;
	for(Row* row:*rows)
	{
		int x=0;
		while(x<screenWidth)
		{
			if((row->getNumber()!=0)&&((unsigned)row->getNumber()!=(rows->size()-1)))
			{
				list<Props*>* PreProp=&propsOnRow->at(row->getNumber());
				Props* prop;
				if(obsOrLane(PreProp,row->isDirLeft(),row->isLaneRow(),difficulty))
				{
					prop=F->createObstacle(row,x,5,0,row->getHeight());
					prop->setVisible(!row->isLaneRow());
				}
				else
				{
					prop=F->createLane(row,x,5,0,row->getHeight());
					prop->setVisible(row->isLaneRow());

				}
				if(row->isDirLeft())
					propsOnRow->at(row->getNumber()).push_front(prop);
				else
					propsOnRow->at(row->getNumber()).push_back(prop);

				x=prop->getW()+x;
			}
			else
				x=screenWidth;
		}
	}
}

void Level::drawGameElements(std::vector<std::list<Props*>>* propsOnRow,
		list<Projectile*>* projectiles, list<Player*>* players,vector<Row*>* rows) {
int i=0;

	for (list<Props*> temp:*propsOnRow)
	{
		propsOnRow->at(i).remove_if(drawMoveRemove());
		i++;
	}

	projectiles->remove_if(drawMoveRemove());

	for(Player* player:*players)
	{
		int row=player->getY()/player->getH(); //TODO instread of getH search for row height
		if(rows->at(row)->isLaneRow())
			player->followRow(rows->at(row));
		if(row==0)
		{
			player->addScore(100);
			player->resetPosition();
		}
		player->draw();
	}
}

bool Level::obsOrLane(list<Props*>* PreProp,bool frontOrBack,bool laneRow, int difficulty)
{
	int number=rand()%100;
	if (frontOrBack)
		return ((laneRow&&PreProp->front()->isVisible())||((number>difficulty)&&!PreProp->front()->isVisible()));
	else
		return ((laneRow&&PreProp->back()->isVisible())||((number>difficulty)&&!PreProp->back()->isVisible()));
}



Props* Level::getRandomObst(list<Props*>* PreProp)
{
	Props* prop;
	vector<Props*> temp;
	for(Props* pro:*PreProp)
	{
		Row* row=pro->getRow();
		if(row!=nullptr&&pro->isVisible()&&!row->isLaneRow())
		{
			temp.push_back(pro);
		}

	}
	if (temp.size()>0)
	{
	prop=temp.at(rand()%temp.size());
	}
	else
		prop=nullptr;
	return prop;

}

bool Level::playersAlive(list<Player*>* players, char mode)
{
	bool temp=false;
	for (Player* player:*players)
	{
		temp=temp||!player->isDead();
	}
	return temp;
}
