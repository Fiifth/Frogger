/*
 * MenuButton.cpp
 * Keeps the actual coordinates of the button by multiplying the relative and the dimensions.
 *  Created on: 24-apr.-2016
 *      Author: Kwinten
 */

#include <menu/MenuButton.h>
#include <math.h>
using namespace frogger;

MenuButton::MenuButton(double x, double y, double w, double h, frogger::Window* win)
{
	this->x =(int) round(x * (*win->getWidth()));
	this->y =(int) round(y * (*win->getHeight()));
	this->w =(int) round(w * (*win->getWidth()));
	this->h =(int) round(h * (*win->getHeight()));
}

MenuButton::~MenuButton()
{
}

bool MenuButton::col(int xCo, int yCo)
{
	return ((yCo >= y) && (yCo <= (y + h))) && ((xCo >= x) && (xCo <= (x + w)));
}

int frogger::MenuButton::getH() const
{
	return h;
}

int frogger::MenuButton::getX() const
{
	return x;
}

int frogger::MenuButton::getY() const
{
	return y;
}

int frogger::MenuButton::getW() const
{
	return w;
}
