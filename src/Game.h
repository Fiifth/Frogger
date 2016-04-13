/*
 * Game.h
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */
#include <Obstacle.h>
#include "Factory.h"
#include <vector>
#include <list>
#include "Row.h"
#include "Props.h"
#include "Projectile.h"
#include "Player.h"
#include <chrono>
#include <iostream>
#ifndef GAME_H_
#define GAME_H_


class Game {
public:
	Game(Factory* F);
	virtual ~Game();
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

};


#endif /* GAME_H_ */
