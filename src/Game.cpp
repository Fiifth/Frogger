/*
 * Game.cpp
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */

#include <Obstacle.h>
#include <Player.h>
#include "Game.h"

#include "SDLdata.h"
#include "Factory.h"
#include "Window.h"
#include "Events.h"
#include <iostream>
#include <string>
#include "Row.h"
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std;
using namespace std::chrono;

int numberOfRows;

Game::Game(Factory* F)
{
	srand (time(NULL));
	//int propsStartW=100,propsStartH=50;
	int rowHeight=50;
	int difficultyRows=1;
	int windowHeight=500;
	int windowWidth=500;
	int difficulty=70;
	int plStartW=40,plStartH=40,plStartSpeed=50;
	int plStartX=(windowWidth/2),plStartY=(windowHeight-plStartW);
	vector<Row*> rowsR;
	vector<list<Props*>> propsOnRowR;
	vector<Row*>* rows=&rowsR;
	vector<list<Props*>>* propsOnRow=&propsOnRowR;


	Window* win=F->createWindow();
	win->makeWindow(windowHeight,windowWidth,"frogger");

	Player* player=F->createPlayer(plStartX,plStartY,plStartW,plStartH,plStartSpeed,rowHeight);
	Events* event=F->createEvents();



	rowGenerator(rowHeight,windowHeight,difficultyRows,F,rows,propsOnRow);




	for (int n=0; (n<windowWidth); n++)
	{
		propsGenerator(F,difficulty,win->getWidth(),rows,propsOnRow);
		int row=player->getY()/50;
		drawProps(propsOnRow,player->getX(),player->getW(),row);
	}


	while(true)
	{
		string temp=event->getEvent();
		if (temp!="")
		{
			if (temp=="Down")
			{
				player->moveDown();
			}
			else if (temp=="Up")
			{
				player->moveUp();
			}
			else if (temp=="Left")
			{
				player->moveLeft();
			}
			else if (temp=="Right")
			{
				player->moveRight();
			}
			else if (temp=="Escape")
			{
				return;
			}
		}

		win->setBackground();

		propsGenerator(F,difficulty,win->getWidth(),rows,propsOnRow);
		int row=player->getY()/50;

		bool col=drawProps(propsOnRow,player->getX(),player->getW(),row);

		if (col)
			player->setLocation(plStartX,plStartY);
		else if(rows->at(row)->isLaneRow())
			player->followRow(rows->at(row));

		player->draw();

		//auto start_time = chrono::high_resolution_clock::now();
		//auto end_time = chrono::high_resolution_clock::now();
		//cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << endl;
		win->updateScreen();
	}
}

Game::~Game() {}

void Game::rowGenerator(int rowHeight,int screenHight,int difficultyRows,Factory* F,vector<Row*>* rows,vector<list<Props*>>* propsOnRow)
{
	int maxSpeed=3;
	numberOfRows=(screenHight)/rowHeight;
	int mode=3;
	if (mode==1)
	{
		for (int n=0; n<numberOfRows; n++)
		{
			list<Props*> enemies;
			int speed=((rand()%(numberOfRows-n))+1)*difficultyRows;
			speed=speed>maxSpeed?maxSpeed:speed;
			speed=(n==0||n==numberOfRows-1)?0:speed;
			rows->push_back(F->createRow(((rand() %10)>5),speed,(n*rowHeight),rowHeight,n));
			propsOnRow->push_back(enemies);
		}
	}
	else if (mode==2)
	{
		for (int n=0; n<numberOfRows; n++)
		{
			list<Props*> enemies;
			int speed=((rand()%(numberOfRows-n))+1)*difficultyRows;
			speed=speed>maxSpeed?maxSpeed:speed;
			speed=(n==0||n==numberOfRows-1)?0:speed;
			rows->push_back(F->createRow(((rand() %10)>5),speed,(n*rowHeight),rowHeight,n));
			rows->back()->setLaneRow(true);
			propsOnRow->push_back(enemies);

		}
	}
	else if (mode==3)
		{
			for (int n=0; n<numberOfRows; n++)
			{
				list<Props*> enemies;
				int speed=2;
				speed=(n==0||n==numberOfRows-1)?0:speed;
				rows->push_back(F->createRow(((rand() %10)>5),speed,(n*rowHeight),rowHeight,n));
				rows->back()->setLaneRow(n<(numberOfRows/2));
				propsOnRow->push_back(enemies);
			}
		}

}
void Game::propsGenerator(Factory* F,int difficulty,int screenWidth,vector<Row*>* rows,vector<list<Props*>>* propsOnRow)
{
	for(Row* row:*rows)
	{

		if((row->getNumber()!=0)&&(row->getNumber()!=(numberOfRows-1)))
		{
			list<Props*> PreProp=propsOnRow->at(row->getNumber());
			if((PreProp.empty())||((PreProp.front())->isRoom()))
			{

				Props* prop;
				int number=rand()%100;
				bool previousVisible=PreProp.empty()?false:PreProp.front()->isVisible();
				bool giveObsticle=row->isLaneRow()&&previousVisible;
				if (giveObsticle||((number>difficulty)&&!previousVisible))
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
			Lane* temp=dynamic_cast<Lane*>(propsOnRow->at(row->getNumber()).front());
			if ((rand()%1000>995)&&temp!=nullptr)
			{
				Props* propBonus=F->createItem(row);
				if ((propBonus->getX()>temp->getX())&&((propBonus->getX()+propBonus->getW())<(temp->getX()+temp->getW())))
					propsOnRow->at(row->getNumber()).push_back(propBonus);

			}
		}
	}
}


bool Game::drawProps(vector<list<Props*>>* propsOnRow,int x, int w,int row)
{
	int counter=0;
	bool dete=false;
	for (list<Props*> temp:*propsOnRow)
	{
		for(Props* temp2:temp)
		{
			if (!temp2->inframe())
			{

				propsOnRow->at(counter).remove(temp2);


			}
			else
			{
				if (temp2->isVisible())
				temp2->draw();
				temp2->moveHor();

				Item* temp3=dynamic_cast<Item*>(temp2);
				if (temp3!=nullptr)
				{

					if(temp3->coll(x,w,row))
					{
						propsOnRow->at(counter).remove(temp2);
					}
				}
			}
		}
		counter++;
	}
	return dete;
}

list<Props*> Game::fillEnemyList(Factory* F,Row* row,int difficulty,int screenWidth)
{
	list<Props*> temp;
	return temp;
}
