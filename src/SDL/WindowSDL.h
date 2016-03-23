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
	void makeWindow(int ScreenWidth, int ScreenHeight,char const* title);
	 void setBackground();
	 void updateScreen();
	 void generateBackground(std::vector<Row*>* rows);
private:
	 SDLdata* sdldata;
	 SDL_Renderer* ren;
};

#endif /* WINDOWSDL_H_ */
