/*
 * window.cpp
 * This object represents the area where the game takes place. It mainly keeps track of the dimensions.
 *
 *  Created on: Feb 29, 2016
 *      Author: fifth
 */

#include "Window.h"

using namespace frogger;

Window::Window()
{
	WIDTHR=640;
	HEIGHTR=480;
	WIDTH = &WIDTHR;
	HEIGHT = &HEIGHTR;
	dataWindowHeightR=20;
	gameWindowHeightR=460;
	dataWindowHeight = &dataWindowHeightR;
	gameWindowHeight = &gameWindowHeightR;
	TITLE="Frogger";
}
Window::~Window()
{
}

void Window::setProp(int width, int height, int dataWindowHeight,
		char const* title)
{
	WIDTHR = width;
	HEIGHTR = height;
	dataWindowHeightR = dataWindowHeight;
	gameWindowHeightR = height - dataWindowHeight;
	TITLE = title;
}

int* Window::getHeight() const
{
	return HEIGHT;
}

int* Window::getWidth() const
{
	return WIDTH;
}

int* Window::getGameWindowHeight() const
{
	return gameWindowHeight;
}
