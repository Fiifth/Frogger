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
	int row;
	int score=0,life=3,projectiles=0;
	int rowHeight=50;
	int difficultyRows=1;
	int gameWindowHeight;
	int gameWindowWidth;
	int dataWindowHeight=20;
	int WindowHeight=420;
	int WindowWidth=500;
	int difficulty=70;
	dataWindowHeight=((WindowHeight-dataWindowHeight)%rowHeight)+dataWindowHeight;
	gameWindowHeight=WindowHeight-dataWindowHeight;
	gameWindowWidth=WindowWidth;
	int plStartW=rowHeight,plStartH=rowHeight,plStartSpeed=rowHeight;
	int plStartX=(gameWindowWidth/2),plStartY=(gameWindowHeight-plStartW);
	string keyStroke;
	vector<Row*> rowsR;
	vector<list<Props*>> propsOnRowR;
	vector<Row*>* rows=&rowsR;
	vector<list<Props*>>* propsOnRow=&propsOnRowR;


	Window* win=F->createWindow();
	win->makeWindow(WindowWidth,WindowHeight,dataWindowHeight,"frogger");

	Player* player=F->createPlayer(plStartX,plStartY,plStartW,plStartH,plStartSpeed,rowHeight);
	Events* event=F->createEvents();

	rowGenerator(rowHeight,gameWindowHeight,difficultyRows,F,rows,propsOnRow);


	for (int n=0; (n<gameWindowWidth); n++)
	{
		propsGenerator(F,difficulty,win->getWidth(),rows,propsOnRow);
		int row=player->getY()/gameWindowWidth;
		drawProps(propsOnRow,player->getX(),player->getW(),row);
	}

	char state='B';
	while(true)
	{
		keyStroke=event->getEvent();
		switch(state)
		{
			case 'A'  :

				if (keyStroke!="")
				{
					if (keyStroke=="Down")
					{
						player->moveDown();
						score=score-10;
					}
					else if (keyStroke=="Up")
					{
						player->moveUp();
						score=score+10;
					}
					else if (keyStroke=="Left")
						player->moveLeft();
					else if (keyStroke=="Right")
						player->moveRight();
					else if (keyStroke=="Escape")
						return;
				}

				win->setBackground();
				win->generateBackground(rows);
				win->dislayData(score,life,projectiles);

				propsGenerator(F,difficulty,win->getWidth(),rows,propsOnRow);
				row=player->getY()/rowHeight;

				if (drawProps(propsOnRow,player->getX(),player->getW(),row))
				{
					player->setLocation(plStartX,plStartY);
					life=life-1;
					if (life==0)
					{
						state='B';
						life=3;
						score=0;
					}
				}
				else if(rows->at(row)->isLaneRow())
					player->followRow(rows->at(row));
				player->draw();
				win->updateScreen();
				if(row==0)
				{
					score=score+100;
					player->setLocation(plStartX,plStartY);
				}


				break;
			case 'B':
			win->setBackground();
			if (keyStroke!="")
			{
				if (keyStroke=="Space")
					state='A';
				else if (keyStroke=="Escape")
					return;
			}
			win->updateScreen();
			break;
			}

	}
}

Game::~Game() {}

void Game::rowGenerator(int rowHeight,int screenHight,int difficultyRows,Factory* F,vector<Row*>* rows,vector<list<Props*>>* propsOnRow)
{
	int maxSpeed=3;
	numberOfRows=(screenHight)/rowHeight;
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
			rows->push_back(F->createRow(((rand() %10)>5),speed,(n*rowHeight),rowHeight,n));
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
			rows->push_back(F->createRow(((rand() %10)>5),speed,(n*rowHeight),rowHeight,n));
			rows->back()->setLaneRow(true);
			propsOnRow->push_back(enemies);
		}
	}
	else if (mode==3)
		{
			for (int n=0; n<numberOfRows; n++)
			{
				int speed=2;
				speed=(n==0||n==numberOfRows-1)?0:speed;
				rows->push_back(F->createRow(dir,speed,(n*rowHeight),rowHeight,n));
				rows->back()->setLaneRow(n<(numberOfRows/2));
				propsOnRow->push_back(enemies);
				dir=not(dir);
			}
		}
}
void Game::propsGenerator(Factory* F,int difficulty,int screenWidth,vector<Row*>* rows,vector<list<Props*>>* propsOnRow)
{
	for(Row* row:*rows)
	{
		if((row->getNumber()!=0)&&(row->getNumber()!=(numberOfRows-1)))
		{
			const list<Props*>* PreProp=&propsOnRow->at(row->getNumber());
			if((PreProp->empty())||((PreProp->front())->isRoom()))
			{
				Props* prop;
				int number=rand()%100;
				if ((row->isLaneRow()&&PreProp->front()->isVisible())||((number>difficulty)&&!PreProp->front()->isVisible()))
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
			//TODO remove dynamic_cast
			Lane* temp=dynamic_cast<Lane*>(propsOnRow->at(row->getNumber()).front());
			if (temp!=nullptr&&(rand()%1000>997))
			{
				Props* propBonus=F->createItem(row);
				if ((propBonus->getX()>temp->getX())&&((propBonus->getX()+propBonus->getW())<(temp->getX()+temp->getW())))
					propsOnRow->at(row->getNumber()).push_back(propBonus);
				else
					delete(propBonus);
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
				delete(temp2);
			}
			else
			{
				if (temp2->isVisible())
				temp2->draw();
				temp2->moveHor();

				Item* temp3=dynamic_cast<Item*>(temp2);
				if(temp3!=nullptr&&temp3->coll(x,w,row))
				{
					propsOnRow->at(counter).remove(temp2);
					delete(temp3);
					delete(temp2);
				}
				else
					dete=temp2->coll(x,w,row)?true:dete;
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


//auto start_time = chrono::high_resolution_clock::now();
		//auto end_time = chrono::high_resolution_clock::now();
		//cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << endl;
