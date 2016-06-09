/*
 * Game.h
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */

#ifndef GAME_H_
#define GAME_H_
#include "Factory.h"
#include "Window.h"
#include "Events.h"
#include <string>
#include "Row.h"
#include <vector>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <ratio>
#include <Obstacle.h>
#include <Player.h>
#include "Level.h"
#include "LevelProperties.h"
#include "Menu.H"
#include <Obstacle.h>
#include "Row.h"
#include "Props.h"
#include "Projectile.h"
#include "Player.h"
namespace frogger
{
	class Game
	{
		public:
			explicit Game(Factory* F);
			virtual ~Game();
			bool playersAlive(std::list<Player*>* players);
			void addPlayers(Factory* F, std::list<Player*>* players, int amount,	int X, int Y,
					int W, int H, int speed,char gameMode, char difficulty,
					LevelProperties* lvlProp,Window* win);
			void addHighScore(std::list<Player*>* players, char gameMode);
		protected:
			std::vector<int> highScoreClassic = { 0, 0, 0, 0 };
			std::vector<int> highScoreEndless = { 0, 0, 0, 0 };
	};
}

#endif /* GAME_H_ */
