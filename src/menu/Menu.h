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
namespace frogger
{
class Menu
{
public:
	Menu(Window* win);
	virtual ~Menu();
	char menuExecution(std::string keyDown,char state, int mXH,int mYH,int mXP,int mYP);
	void startMenu();
	bool isStartGame() const;

private:
	Window* win;
	char state='A';
	bool startGame=false;
	MenuButton* classic;
	MenuButton* endless;
	MenuButton* high;
	MenuButton* quit;
	MenuButton* p1;
	MenuButton* p2;
	MenuButton* menu;
	MenuButton* restart;
	MenuButton* back;
};
}
#endif /* MENU_H_ */
