/*
 * Menu.h
 *
 *  Created on: 24-apr.-2016
 *      Author: msn-w
 */

#ifndef MENU_H_
#define MENU_H_
#include "Window.h"
#include "MenuButton.h"

class Menu
{
public:
	Menu(Window* win);
	virtual ~Menu();
	char menuExecution(std::string keyDown,int mXH,int mYH,int mXP,int mYP);
	void startMenu();
	bool isStartGame() const;

private:
	Window* win;
	char state='A';
	bool startGame=false;
	MenuButton* start;
	MenuButton* high;
	MenuButton* quit;
	MenuButton* back;
};

#endif /* MENU_H_ */
