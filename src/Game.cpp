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
using namespace frogger;

Game::Game(Factory* F)
{
	char state = 'S';
	char PrevState = 'S';
	int WindowHeight = 520;
	int WindowWidth = 700;
	int rowHeight = 50;
	int dataWindowHeightDesired = 20;
	int dataWindowHeight =((WindowHeight - dataWindowHeightDesired) % rowHeight)+ dataWindowHeightDesired;
	int gameWindowHeight = WindowHeight - dataWindowHeight;
	int gameWindowWidth = WindowWidth;
	int plStartW = rowHeight, plStartH = rowHeight, plStartSpeed = rowHeight;
	int plStartX = (gameWindowWidth / 2), plStartY = (gameWindowHeight	- plStartW);
	string keyStroke;


	list<Player*> playersR;
	list<Player*>* players = &playersR;
	Events* event = F->createEvents();
	Window* win = F->createWindow();

	win->makeWindow(WindowWidth, WindowHeight, dataWindowHeight, "frogger");



	LevelProperties* lvlprop;

	Level* level;
	Menu* men=new Menu(win);


	while (true)
	{
		int x,y;
		keyStroke = event->getEvent();
		event->getMousePos(&x,&y);

		switch (state)
		{
		case 'S':case'H':case'G':case'V':case'M':case'N':
			//menu case modes
			PrevState=state;
			state =men->menuExecution(keyStroke,state,x,y,x,y);

			win->updateScreen();
			break;
		case 'C':case'E':case 'I':case'O':
			//level execution modes
			if(PrevState==state)
			{
				level->levelExecution(keyStroke);
				state = playersAlive(players, state) ? state : 'G';
				state=level->isObjectiveDone()?'V':state;
				win->dislayData(players);
				win->updateScreen();
			}

			else if (PrevState=='M')
			{
				//classic

				int amount=(state=='I')?1:0;
				amount=(state=='O')?2:amount;
				addPlayers(F,players,amount,plStartX,plStartY,plStartW,plStartH,plStartSpeed,rowHeight);

				lvlprop=new LevelProperties('C');
				level = new Level(F, win, players, rowHeight,lvlprop);
				state='C';
				PrevState=state;
			}
			else if (PrevState=='N')
			{
				//endeless
				int amount=(state=='I')?1:0;
				amount=(state=='O')?2:amount;
				addPlayers(F,players,amount,plStartX,plStartY,plStartW,plStartH,plStartSpeed,rowHeight);
				lvlprop=new LevelProperties('E');
				level = new Level(F, win, players, rowHeight,lvlprop);
				state='E';
				PrevState=state;
			}

			break;
		case 'Q':
				//remove everything
			return;

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

void frogger::Game::addPlayers(Factory* F,list<Player*>* players, int amount,int X,int Y,int W,int H,int speed, int rowHeight)
{
	players->clear();
	if (amount >=1)
	{
	Player* player = F->createPlayer(X, Y, W, H,	speed, rowHeight, 0);
	players->push_back(player);
	}
	if (amount>1)
	{
		Player* player2 = F->createPlayer(X, Y, W, H,	speed, rowHeight, 1);
		player2->setDifferentControls();
		players->push_back(player2);
	}
}
//start_time=chrono::steady_clock::now();
//			end_time=chrono::steady_clock::now();
