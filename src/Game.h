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
#ifndef GAME_H_
#define GAME_H_


class Game {
public:
	Game(Factory* F);
	virtual ~Game();
	void rowGenerator(int rowHeight,int screenHight,int difficultyRows,Factory* F,vector<Row*>* rows,vector<list<Props*>>* propsOnRow);
	void propsGenerator(Factory* F,int difficulty,int screenWidth,vector<Row*>* rows,vector<list<Props*>>* propsOnRow);
	int drawProps(vector<list<Props*>>* propsOnRow,int x,int y,int h, int w,int row);
	list<Props*> fillEnemyList(Factory* F,Row* row,int difficulty,int screenWidth);


};


#endif /* GAME_H_ */
