/*
 * Game.h
 *  Created on: 22 Feb 2016
 *      Author: Kwinten
 */

#ifndef GAME_H_
#define GAME_H_
#include "Abstract/Factory.h"
#include "Abstract/Window.h"
#include "Abstract/Events.h"
#include <string>
#include "Abstract/Row.h"
#include <vector>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <ratio>
#include <Abstract/Entities/Obstacle.h>
#include "Abstract/Entities/Player.h"
#include "Level.h"
#include "levelGenerator/LevelProperties.h"
#include "menu/Menu.H"
#include <Abstract/Entities/Obstacle.h>
#include "Abstract/Row.h"
#include "Abstract/Entities/Props.h"
#include "Abstract/Entities/Projectile.h"
#include "Abstract/Entities/Player.h"
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
