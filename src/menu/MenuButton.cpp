/*
 * MenuButton.cpp
 *
 *  Created on: 24-apr.-2016
 *      Author: msn-w
 */

#include <MenuButton.h>
using namespace frogger;

MenuButton::MenuButton(int x,int y, int w,int h):x(x),y(y),w(w),h(h)
{
	// TODO Auto-generated constructor stub

}

MenuButton::~MenuButton()
{}

bool MenuButton::col(int xCo,int yCo)
{
	return ((yCo>=y)&&(yCo<=(y+h)))&&((xCo>=x)&&(xCo<=(x+w)));
}

