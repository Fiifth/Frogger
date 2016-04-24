/*
 * Menu.h
 *
 *  Created on: 24-apr.-2016
 *      Author: msn-w
 */

#ifndef MENU_H_
#define MENU_H_
#include "SDLdata.h"
#include "MenuButton.h"

class Menu
{
public:
	Menu(SDLdata* sdldata);
	virtual ~Menu();
	void menuExecution(std::string keyDown,int mXH,int mYH,int mXP,int mYP);
	void startMenu();
	bool isStartGame() const;

private:
	SDLdata* sdldata;
	char state='A';
	bool startGame=false;
};

#endif /* MENU_H_ */
