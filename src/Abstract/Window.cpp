/*
 * window.cpp
 *
 *  Created on: Feb 29, 2016
 *      Author: fifth
 */

#include "Window.h"
#include <string>
using namespace std;

Window::Window()
{
	WIDTH  = 640;
	HEIGHT = 480;
	TITLE="frogger";
}
Window::~Window() {
}

void Window::setProp(int width,int height,char const* title)
{
	WIDTH  = width;
	HEIGHT = height;
	TITLE=title;
}

int Window::getHeight() const {
	return HEIGHT;
}

int Window::getWidth() const {
	return WIDTH;
}
