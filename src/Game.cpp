/*
 * Game.cpp
 *
 *  Created on: 22 Feb 2016
 *      
 */

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
#include <ctime>
#include <ratio>
#include <chrono>
#include "Projectile.h"
#include <Obstacle.h>
#include <Player.h>
#include "Level.h"
#include "LevelProperties.h"
#include "Menu.H"

using namespace std;
using namespace std::chrono;

Game::Game(Factory* F)
{
	int WindowHeight = 520;
	int WindowWidth = 700;
	int rowHeight = 50;
	int dataWindowHeightDesired = 20;
	int dataWindowHeight =
			((WindowHeight - dataWindowHeightDesired) % rowHeight)
					+ dataWindowHeightDesired;
	int gameWindowHeight = WindowHeight - dataWindowHeight;
	int gameWindowWidth = WindowWidth;
	int plStartW = rowHeight, plStartH = rowHeight, plStartSpeed = rowHeight;
	int plStartX = (gameWindowWidth / 2), plStartY = (gameWindowHeight
			- plStartW);
	string keyStroke;

	list<Player*> playersR;
	list<Player*>* players = &playersR;
	Events* event = F->createEvents();
	Window* win = F->createWindow();
	win->makeWindow(WindowWidth, WindowHeight, dataWindowHeight, "frogger");
	Player* player = F->createPlayer(plStartX, plStartY, plStartW, plStartH,
			plStartSpeed, rowHeight, 0);
	Player* player2 = F->createPlayer(plStartX, plStartY, plStartW, plStartH,
			plStartSpeed, rowHeight, 1);
	player2->setDifferentControls();
	players->push_back(player);
	players->push_back(player2);
	LevelProperties* lvlprop=new LevelProperties(); //TODO place in factory
	Level* level = new Level(F, win, players, rowHeight,lvlprop);
	Menu* men=new Menu(win);
	char state = 'B';
	while (true)
	{
		int x,y;
		keyStroke = event->getEvent();
		event->getMousePos(&x,&y);
		switch (state)
		{
		//----------------------------------------------------------------------------------------------------
		case 'A':

			if (keyStroke == "Escape")
				return;
			level->levelExecution(keyStroke);

			state = playersAlive(players, 'A') ? 'A' : 'B';
			state=level->isObjectiveDone()?'B':state;

			win->dislayData(players);
			win->updateScreen();
			break;

			//----------------------------------------------------------------------------------------------------
		case 'B':
			char temp=men->menuExecution(keyStroke,x,y,x,y);
			if (temp=='A')
			{
				for (Player* play : *players)
				{
					play->resetRemainingTime();
					play->setDead(false);
				}
				level->resetLevel();
				state = 'A';
			}
			else if (temp=='Q')
				return;
			win->updateScreen();
			break;
		}
	}
}

Game::~Game()
{
}

bool Game::playersAlive(list<Player*>* players, char mode)
{
	bool temp = false;
	for (Player* player : *players)
	{
		temp = temp || !player->isDead();
	}
	return temp;
}
//start_time=chrono::steady_clock::now();
//			end_time=chrono::steady_clock::now();
