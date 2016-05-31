/*
 * MenuButton.cpp
 *
 *  Created on: 24-apr.-2016
 *      Author: msn-w
 */

#include <MenuButton.h>
using namespace frogger;

MenuButton::MenuButton(float x,float y,float w,float h,frogger::Window* win)
{
	this->x=x*(*win->getWidth());
	this->y=y*(*win->getHeight());
	this->w=w*(*win->getWidth());
	this->h=h*(*win->getHeight());

}

MenuButton::~MenuButton()
{}

bool MenuButton::col(int xCo,int yCo)
{
	return ((yCo>=y)&&(yCo<=(y+h)))&&((xCo>=x)&&(xCo<=(x+w)));
}

int frogger::MenuButton::getH() const {
	return h;
}

int frogger::MenuButton::getX() const {
	return x;
}

int frogger::MenuButton::getY() const {
	return y;
}

int frogger::MenuButton::getW() const {
	return w;
}
