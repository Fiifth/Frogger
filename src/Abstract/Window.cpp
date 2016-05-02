/*
 * window.cpp
 *
 *  Created on: Feb 29, 2016
 *      Author: fifth
 */

#include "Window.h"
#include <string>
using namespace std;
using namespace frogger;

Window::Window()
{
	WIDTH = 640;
	HEIGHT = 480;
	dataWindowHeight = 20;
	gameWindowHeight = HEIGHT - dataWindowHeight;
	TITLE = "frogger";
}
Window::~Window()
{
}

void Window::setProp(int width, int height, int dataWindowHeight,
		char const* title)
{
	WIDTH = width;
	HEIGHT = height;
	this->dataWindowHeight = dataWindowHeight;
	gameWindowHeight = height - dataWindowHeight;
	TITLE = title;
}

int Window::getHeight() const
{
	return HEIGHT;
}

int Window::getWidth() const
{
	return WIDTH;
}

void Window::setOldParameters(int score, int life, int projectiles, int time)
{
	oldScore = score;
	oldLife = life;
	oldProjectiles = projectiles;
	oldTime = time;
}

bool Window::valueChanged(int score, int life, int projectiles, int time,int score2, int life2, int projectiles2, int time2)
{
	return !(oldScore == score && oldLife == life
			&& oldProjectiles == projectiles && oldTime == time&&oldScore2 == score2 && oldLife2 == life2
			&& oldProjectiles2 == projectiles2 && oldTime2 == time2);
}

int Window::getGameWindowHeight() const
{
	return gameWindowHeight;
}
