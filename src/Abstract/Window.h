/*
 * window.h
 *
 *  Created on: Feb 29, 2016
 *      Author: fifth
 */

#ifndef WINDOW_H_
#define WINDOW_H_
#include <string>
#include <vector>
#include "Row.h"
#include "Player.h"
#include <list>
class Player;
class Window
{
public:
	Window();
	virtual ~Window();
	virtual void makeWindow(int ScreenWidth, int ScreenHeight,
			int dataWindowHeight, char const* title)=0;
	void setProp(int width, int height, int dataWindowHeight,
			char const* title);
	virtual void setBackground()=0;
	virtual void updateScreen()=0;
	int getHeight() const;
	int getWidth() const;
	//virtual void dislayData(std::list<Player*>* players)=0;
	virtual void displayHighScore(int score1, int score2, int score3,
			int score4)=0;
	virtual void generateBackground(std::vector<Row*>* rows)=0;
	void setOldParameters(int score, int life, int projectiles, int time);
	bool valueChanged(int score, int life, int projectiles, int time,int score2, int life2, int projectiles2, int time2);
	int getGameWindowHeight() const;
	virtual void dislayData(std::list<Player*>* players)=0;

protected:
	int WIDTH;
	int HEIGHT;
	int dataWindowHeight;
	int gameWindowHeight;
	char const * TITLE;
	int oldScore = 0, oldLife = 0, oldProjectiles = 0, oldTime = 0;
	int oldScore2 = 0, oldLife2 = 0, oldProjectiles2 = 0, oldTime2 = 0;
};

#endif /* WINDOW_H_ */
