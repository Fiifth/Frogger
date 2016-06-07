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
#include <algorithm>
#include <LevelProperties.h>
namespace frogger
{
	class Game
	{
		public:
			Game(Factory* F);
			virtual ~Game();
			bool playersAlive(list<Player*>* players, char mode);
			void addPlayers(Factory* F, list<Player*>* players, int amount,	int X, int Y,
					int W, int H, int speed, int rowHeight,char gameMode, char difficulty,
					LevelProperties* lvlProp,Window* win);
			void addHighScore(list<Player*>* players, char gameMode);
		protected:
			std::vector<int> highScoreClassic = { 0, 0, 0, 0 };
			std::vector<int> highScoreEndless = { 0, 0, 0, 0 };

	};
}

#endif /* GAME_H_ */
