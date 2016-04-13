/*
 * Level.cpp
 *
 *  Created on: 8-apr.-2016
 *      Author: msn-w
 */

#include <Level.h>

Level::Level()
{
	// TODO Auto-generated constructor stub

}

Level::~Level() {
	// TODO Auto-generated destructor stub
}

void Level::propsGenerator(Factory* F,int difficulty,vector<Row*>* rows,vector<list<Props*>>* propsOnRow)
{
	for(Row* row:*rows)
	{
		if((row->getNumber()!=0)&&(row->getNumber()!=((rows->size())-1)))
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
				Props* propBonus=F->createItem(row);
				propsOnRow->at(row->getNumber()).push_back(propBonus);
			}
			if(rand()%1000>998)
			{
				Props* randomObstable=getRandomObst(PreProp);
				if (randomObstable!=nullptr)
				{
					Props* projec=F->createProjectile(randomObstable,5);
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

			int effect=temp2->coll(players->back(),true);
			if(effect>1)
			{
				propsOnRow->at(temp2->getRow()->getNumber()).remove(temp2);
				delete(temp2);
				dete=effect;
				players->back()->addScore(1);
				players->back()->addProjectiles(1);
			}
			else if (effect==1||players->back()->getRemainingTime()==0)
			{
				return players->back()->hit();
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
			if((row->getNumber()!=0)&&(row->getNumber()!=(rows->size()-1)))
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
