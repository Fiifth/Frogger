/*
 * windowSDL.h
 *
 *  Created on: Feb 29, 2016
 *      Author: fifth
 */
#include "Window.h"
#include "SDL.h"
#include "SDLdata.h"
#include "Row.h"
#include <vector>

#ifndef WINDOWSDL_H_
#define WINDOWSDL_H_

class WindowSDL:public  Window{
public:
	WindowSDL(SDLdata* sdldata);
	virtual ~WindowSDL();
	void makeWindow(int ScreenWidth, int ScreenHeight,int dataWindowHeight,char const* title);
	void dislayData(int score,int life,int projectiles,int time);
	void displayHighScore(int score1,int score2,int score3,int score4);
	 void setBackground();
	 void updateScreen();
	 void generateBackground(std::vector<Row*>* rows);
private:
	 SDLdata* sdldata;
	 SDL_Renderer* ren;
};

#endif /* WINDOWSDL_H_ */
