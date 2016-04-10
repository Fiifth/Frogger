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
#ifndef GAME_H_
#define GAME_H_


class Game {
public:
	Game(Factory* F);
	virtual ~Game();
	void rowGenerator(int rowHeight,int screenHight,int difficultyRows,Factory* F,vector<Row*>* rows,vector<list<Props*>>* propsOnRow);
	void propsGenerator(Factory* F,int difficulty,int screenWidth,vector<Row*>* rows,vector<list<Props*>>* propsOnRow);
	int collisionDetection(vector<list<Props*>>* propsOnRow,list<Projectile*>*projectiles,list<Player*>* players);
	void fillEnemyList(Factory* F,std::vector<Row*>* rows,std::vector<std::list<Props*>>* propsOnRow,int difficulty,int screenWidth);
	void drawGameElements(std::vector<std::list<Props*>>* propsOnRow,list<Projectile*>*projectiles,list<Player*>* players,vector<Row*>* rows);
	bool obsOrLane(list<Props*>* PreProp,bool frontOrBack,bool laneRow, int difficulty);
	struct Pred
		{
		   bool operator()(Props* item) const
		   {
		      return !item->inframe();
		   }
		};

};


#endif /* GAME_H_ */
