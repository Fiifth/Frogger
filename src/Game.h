/*
 * Game.h
 * Manages the game.
 * Consist mainly of a state machine that updates its state by executing a level or executing the menu. Also keeps track of the highscore.
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
#include <algorithm>
#include <LevelProperties.h>
using namespace std;
namespace frogger
{
	class Game
	{
		public:
			explicit Game(Factory* F);
			virtual ~Game();
			bool playersAlive(list<Player*>* players);
			void addPlayers(Factory* F, list<Player*>* players, int amount,	int X, int Y,
					int W, int H, int speed,char gameMode, char difficulty,
					LevelProperties* lvlProp,Window* win);
			void addHighScore(list<Player*>* players, char gameMode);
		protected:
			std::vector<int> highScoreClassic = { 0, 0, 0, 0 };
			std::vector<int> highScoreEndless = { 0, 0, 0, 0 };
	};
}

#endif /* GAME_H_ */
