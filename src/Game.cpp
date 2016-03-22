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

using namespace std;

int numberOfRows;

Game::Game(Factory* F)
{
	srand (time(NULL));
	int propsStartW=100,propsStartH=50;
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
	vector<list<Props*>> itemsOnRowR;
	vector<list<Props*>>* itemsOnRow=&itemsOnRowR;


	Window* win=F->createWindow();
	win->makeWindow(windowHeight,windowWidth,"frogger");

	Player* player=F->createPlayer(plStartX,plStartY,plStartW,plStartH,plStartSpeed,rowHeight);
	Events* event=F->createEvents();

	rowGenerator(rowHeight,windowHeight,difficultyRows,F,rows,propsOnRow,itemsOnRow);

	for (int n=0; (n<windowWidth); n++)
	{
		propsGenerator(F,difficulty,win->getWidth(),rows,propsOnRow,itemsOnRow,propsStartW,propsStartH);
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
		propsGenerator(F,difficulty,win->getWidth(),rows,propsOnRow,itemsOnRow,propsStartW,propsStartH);
		int row=player->getY()/50;

		bool col=drawProps(propsOnRow,player->getX(),player->getW(),row);

		if (col)
			player->setLocation(plStartX,plStartY);
		else if(rows->at(row)->isLaneRow())
			player->followRow(rows->at(row));
		drawProps(itemsOnRow,player->getX(),player->getW(),row);
		player->draw();

		win->updateScreen();
	}
}

Game::~Game() {}

void Game::rowGenerator(int rowHeight,int screenHight,int difficultyRows,Factory* F,vector<Row*>* rows,vector<list<Props*>>* propsOnRow,vector<list<Props*>>* itemsOnRow)
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
			itemsOnRow->push_back(enemies);
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
			itemsOnRow->push_back(enemies);
		}
	}
	else if (mode==3)
		{
			for (int n=0; n<(numberOfRows/2); n++)
			{
				list<Props*> enemies;
						int speed=((rand()%(numberOfRows-n))+1)*difficultyRows;
						speed=speed>maxSpeed?maxSpeed:speed;
						speed=(n==0||n==numberOfRows-1)?0:speed;
						rows->push_back(F->createRow(((rand() %10)>5),speed,(n*rowHeight),rowHeight,n));
						rows->back()->setLaneRow(true);
						propsOnRow->push_back(enemies);
						itemsOnRow->push_back(enemies);
			}
			for (int n=numberOfRows/2; n<(numberOfRows); n++)
			{
				list<Props*> enemies;
				int speed=((rand()%(numberOfRows-(n-numberOfRows/2)))+1)*difficultyRows;
				speed=speed>maxSpeed?maxSpeed:speed;
				speed=(n==0||n==numberOfRows-1)?0:speed;
				rows->push_back(F->createRow(((rand() %10)>5),speed,(n*rowHeight),rowHeight,n));

				propsOnRow->push_back(enemies);
				itemsOnRow->push_back(enemies);
			}
		}

}
void Game::propsGenerator(Factory* F,int difficulty,int screenWidth,vector<Row*>* rows,vector<list<Props*>>* propsOnRow,vector<list<Props*>>* itemsOnRow,int propW,int propH)
{
	for(Row* row:*rows)
	{

		if((row->getNumber()!=0)&&(row->getNumber()!=(numberOfRows-1)))
		{
			list<Props*> PreProp=propsOnRow->at(row->getNumber());
			if((PreProp.empty())||((PreProp.back())->isRoom()))
			{

				Props* prop;
				int number=rand()%100;
				bool previousVisible=PreProp.empty()?false:PreProp.back()->isVisible();
				bool giveObsticle=row->isLaneRow()&&previousVisible;
				if (giveObsticle||((number>difficulty)&&!previousVisible))
				{
					prop=F->createObstacle(row,0,row->getLocY(),propW,propH);
					prop->setVisible(!row->isLaneRow());
				}
				else
				{
					prop=F->createLane(row,0,0,propW,propH);
					prop->setVisible(row->isLaneRow());

				}
				propsOnRow->at(row->getNumber()).push_back(prop);

			}
			Lane* temp=dynamic_cast<Lane*>(propsOnRow->at(row->getNumber()).back());
			if ((rand()%1000>995)&&temp!=nullptr)
			{
				Props* propBonus=F->createItem(row,0,0,propW,propH);
				if ((propBonus->getX()>temp->getX())&&((propBonus->getX()+propBonus->getW())<(temp->getX()+temp->getW())))
				itemsOnRow->at(row->getNumber()).push_back(propBonus);

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
				if (dynamic_cast<Obstacle*>(temp2)!=nullptr)
				{
					Obstacle* temp3=dynamic_cast<Obstacle*>(temp2);
					temp3->moveHor();

					if (temp3->isVisible())
					temp3->draw();
					dete=temp3->coll(x,w,row)?true:dete;
				}
				else if (dynamic_cast<Lane*>(temp2)!=nullptr)
				{
					Lane* temp3=dynamic_cast<Lane*>(temp2);
					if (temp3->isVisible())
					temp3->draw();
					temp3->moveHor();
				}
				else if (dynamic_cast<Item*>(temp2)!=nullptr)
				{

					Item* temp3=dynamic_cast<Item*>(temp2);
					if(temp3->coll(x,w,row))
					{

						propsOnRow->at(counter).remove(temp2);
						//TODO item effect
					}
					else
					{
						temp3->moveHor();
					temp3->draw();
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
