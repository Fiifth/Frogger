/*
 * Game.cpp
 * Manages the game.
 * Consist mainly of a state machine that updates its state by executing a level or executing the menu. Also keeps track of the highscore.
 *  Created on: 22 Feb 2016
 *      
 */

/*
 * States:
 * B: start menu
 * H: highscore display menu
 * S: settings menu
 * V: victory screen
 * G: game over screen
 *
 * E: Endless game mode
 * C: classic game mode
 * Q: quit state
 *
 */

/* Row types:
* A: First row (players starts here)
* B: Obstacle row (row where obstacles are visible and lanes invisible)
* C: Lane row (row where obstacles are invisible and lanes visible)
* D: middle row (no movement, can contain some bushes)
* E: last row (row where player wants to go)
 */


#include "Game.h"
using namespace frogger;

Game::Game(Factory* F)
{
	char state = 'B';
	char PrevState = 'B';
	int amountOfPlayers = 1;
	char gameMode = 'E';
	char difficulty = 'E';
	int WindowHeight = 530;
	int WindowWidth = 700;
	int rowHeight = 45;
	int dataWindowHeightDesired = 30;
	int dataWindowHeight =
			((WindowHeight - dataWindowHeightDesired) % rowHeight)
					+ dataWindowHeightDesired;
	int gameWindowHeight = WindowHeight - dataWindowHeight;
	int gameWindowWidth = WindowWidth;
	int plStartW = rowHeight, plStartH = rowHeight, plStartSpeed = rowHeight;
	int plStartX = (gameWindowWidth / 2), plStartY = (gameWindowHeight- plStartW);
	std::string keyStroke;

	std::list<Player*> playersR;
	std::list<Player*>* players = &playersR;
	Events* event = F->createEvents();
	Window* win = F->createWindow();
	LevelProperties* lvlprop=nullptr;
	Level* level=nullptr;
	bool newHighscore;

	win->makeWindow(WindowWidth, WindowHeight, dataWindowHeight, "frogger");

	Menu* men = new Menu(win, &gameMode, &amountOfPlayers, &difficulty);

	int prevScore = 0;
	while (true)
	{
		int x, y;

		keyStroke = event->getEvent();
		event->getMousePos(&x, &y);
		if (keyStroke =="Escape")
			state='B';

		switch (state)
		{
			case 'B':
			case 'H':
			case 'G':
			case 'S':
			case 'V':
				//menu case modes
				if (state == 'G' && PrevState != state)
				{
					addHighScore(players, gameMode);
					for(Player* player:*players)
						delete(player);
					players->clear();
					delete(level);
					level=nullptr;
					delete(lvlprop);
					lvlprop=nullptr;
					prevScore = 0;
				}

				newHighscore=PrevState!='H';

				PrevState = state;
				state = men->menuExecution(keyStroke, state, x, y);
				if (state == 'H')
				{
					if (gameMode == 'E')
						win->displayHighScore(highScoreEndless,(newHighscore));
					else
						win->displayHighScore(highScoreClassic,(newHighscore));
				}
				win->updateScreen();

				break;
			case 'E':
			case 'C':
				//level execution modes
				if (PrevState == state)
				{
					level->levelExecution(keyStroke);

					state = playersAlive(players) ? state : 'G';
					state = level->isObjectiveDone() ? 'V' : state;
					if (gameMode == 'E'	&& ((players->back()->getScore()-prevScore) >= 100)	&& (players->back()->getScore() > prevScore))
					{
						lvlprop->levelUp();
						prevScore = players->back()->getScore()-(players->back()->getScore()%100);
					}
					win->dislayData(players);
					win->updateScreen();
				}

				else if (PrevState == 'B' || PrevState == 'G')
				{
					lvlprop = new LevelProperties(gameMode, difficulty);
					addPlayers(F, players, amountOfPlayers, plStartX, plStartY,
							plStartW, plStartH, plStartSpeed,
							gameMode, difficulty,lvlprop,win);

					level = new Level(F, win, players, rowHeight, lvlprop);

					state = gameMode;
					PrevState = state;
				}
				else if (PrevState == 'V')
				{
					if(level!=nullptr)
										delete(level);
					lvlprop->levelUp();
					level = new Level(F, win, players, rowHeight, lvlprop);
					state = 'C';
					PrevState = state;
				}
				break;

			case 'Q':
				delete(event);
				delete(win);
				if(lvlprop!=nullptr)
					delete(lvlprop);
				if(level!=nullptr)
					delete(level);
				for(Player* player:*players)
					delete(player);
				return;
				break;
		}
	}
}

Game::~Game()
{

}

bool Game::playersAlive(std::list<Player*>* players)
{
	bool temp = false;
	for (Player* player : *players)
	{
		temp = temp || !player->isDead();
	}
	return temp;
}

void frogger::Game::addPlayers(Factory* F, std::list<Player*>* players, int amount,
		int X, int Y, int W, int H, int speed, char gameMode,
		char difficulty,LevelProperties* lvlProp,Window* win)
{
	for(Player* player:*players)
							delete(player);
	players->clear();
	int life = 4, totalTime = 50, scorePerStep = 10, projectiles = 3; //classic easy mode
	bool counterEnabled;

	counterEnabled = (gameMode == 'E') ? false : true;

	life = (difficulty == 'M') ? 3 : life;
	life = (difficulty == 'H') ? 2 : life;
	life = (gameMode == 'E') ? 0 : life;

	totalTime = (difficulty == 'M') ? 40 : totalTime;
	totalTime = (difficulty == 'H') ? 30 : totalTime;
	totalTime = (gameMode == 'E') ? -1 : totalTime;

	scorePerStep = (difficulty == 'M') ? 20 : scorePerStep;
	scorePerStep = (difficulty == 'H') ? 30 : scorePerStep;

	projectiles = (difficulty == 'M') ? 2 : projectiles;
	projectiles = (difficulty == 'H') ? 1 : projectiles;

	players->clear();
	if (amount >= 1)
	{
		Player* player = F->createPlayer1();
		player->setAni(lvlProp->getPlayerAni(0).clone());
		player->setF(F);
		player->setProjAniList(lvlProp->getProjAni());
		player->initPlayer(speed,speed,W,H,X,Y,X,Y,win->getWidth(),win->getGameWindowHeight());

		player->setParameters(life, totalTime, counterEnabled, scorePerStep, projectiles);
		players->push_back(player);
	}
	if (amount >= 2)
	{
		Player* player2 = F->createPlayer1();
		player2->setAni(lvlProp->getPlayerAni(1).clone());
		player2->setF(F);
		player2->setProjAniList(lvlProp->getProjAni());
		player2->initPlayer(speed,speed,W,H,X-W,Y,X-W,Y,win->getWidth(),win->getGameWindowHeight());
		player2->setDifferentControls('A');
		player2->setParameters(life, totalTime, counterEnabled, scorePerStep, projectiles);
		players->push_back(player2);
	}
	if (amount >= 3)
	{
		Player* player3 = F->createPlayer1();
		player3->setAni(lvlProp->getPlayerAni(2).clone());
		player3->setF(F);
		player3->setProjAniList(lvlProp->getProjAni());
		player3->initPlayer(speed,speed,W,H,X+W,Y,X+W,Y,win->getWidth(),win->getGameWindowHeight());
		player3->setDifferentControls('B');
		player3->setParameters(life, totalTime, counterEnabled, scorePerStep, projectiles);
		players->push_back(player3);
	}
}

void frogger::Game::addHighScore(std::list<Player*>* players, char gameMode)
{
	for (Player* play : *players)
	{
		int score = play->getScore();
		if (gameMode == 'C')
		{
			highScoreClassic.push_back(score);
			std::sort(highScoreClassic.begin(), highScoreClassic.end());
			std::reverse(highScoreClassic.begin(), highScoreClassic.end());
			highScoreClassic.pop_back();
		}
		else
		{
			highScoreEndless.push_back(score);
			std::sort(highScoreEndless.begin(), highScoreEndless.end());
			std::reverse(highScoreEndless.begin(), highScoreEndless.end());
			highScoreEndless.pop_back();
		}
	}
}
