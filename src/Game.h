/*
 * Game.h
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */

#ifndef GAME_H_
#define GAME_H_
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

class Game {
public:
	Game(Factory* F);
	virtual ~Game();
	bool playersAlive(list<Player*>* players,char mode);


};


#endif /* GAME_H_ */
