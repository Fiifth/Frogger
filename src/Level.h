/*
 * Level.h
 *
 *  Created on: 8-apr.-2016
 *      Author: msn-w
 */

#ifndef LEVEL_H_
#define LEVEL_H_
#include <vector>
#include <Row.h>
#include <list>
#include "Projectile.h"
#include "Props.h"

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
#include "Projectile.h"
#include <Obstacle.h>
#include <Player.h>

class Level {
public:
	Level();
	virtual ~Level();
	void rowGenerator(int rowHeight,int screenHight,int difficultyRows,Factory* F,vector<Row*>* rows,vector<list<Props*>>* propsOnRow);
	void propsGenerator(Factory* F,int difficulty,vector<Row*>* rows,vector<list<Props*>>* propsOnRow);
	int collisionDetection(vector<list<Props*>>* propsOnRow,list<Projectile*>*projectiles,list<Player*>* players);
	void fillEnemyList(Factory* F,std::vector<Row*>* rows,std::vector<std::list<Props*>>* propsOnRow,int difficulty,int screenWidth);
	void drawGameElements(std::vector<std::list<Props*>>* propsOnRow,list<Projectile*>*projectiles,list<Player*>* players,vector<Row*>* rows);
	bool obsOrLane(list<Props*>* PreProp,bool frontOrBack,bool laneRow, int difficulty);
	Props* getRandomObst(list<Props*>* PreProp);
	struct drawMoveRemove
	{
	   bool operator()(Props* prop) const
	   {
		   bool temp=false;
		   if(!prop->inframe())
		   {
			   temp=true;
			   delete(prop);
		   }
		   else
		   {
			  if (prop->isVisible())
				   prop->draw();
			   prop->moveForward();
		   }
		   return temp;
	   }
	};
private:
		int rowHeight=50;
		int difficultyRows=1;
		int WindowHeight=520;
		int WindowWidth=700;
		int difficulty=90;
		int dataWindowHeightDesired=20;
		int dataWindowHeight=((WindowHeight-dataWindowHeightDesired)%rowHeight)+dataWindowHeightDesired;
		int gameWindowHeight=WindowHeight-dataWindowHeight;
		int gameWindowWidth=WindowWidth;
		int plStartW=rowHeight,plStartH=rowHeight,plStartSpeed=rowHeight;
		int plStartX=(gameWindowWidth/2),plStartY=(gameWindowHeight-plStartW);
		string keyStroke;
		vector<Row*> rowsR;
		vector<list<Props*>> propsOnRowR;
		list<Projectile*>projectilesR;
		list<Projectile*>*projectiles=&projectilesR;
		vector<Row*>* rows=&rowsR;
		vector<list<Props*>>* propsOnRow=&propsOnRowR;
		list<Player*> playersR;
		list<Player*>* players=&playersR;
};

#endif /* LEVEL_H_ */
