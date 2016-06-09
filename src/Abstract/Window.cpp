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
	screenWidthR=640;
	screenHeightR=480;
	screenWidth = &screenWidthR;
	screenHeight = &screenHeightR;
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
	screenWidthR = width;
	screenHeightR = height;
	dataWindowHeightR = dataWindowHeight;
	gameWindowHeightR = height - dataWindowHeight;
	TITLE = title;
}

int* Window::getHeight() const
{
	return screenHeight;
}

int* Window::getWidth() const
{
	return screenWidth;
}

int* Window::getGameWindowHeight() const
{
	return gameWindowHeight;
}
