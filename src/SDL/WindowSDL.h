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
#include "SDL_ttf.h"
#include "SDL.h"
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
	 void saveCurrentWindowImage();
private:
	 SDLdata* sdldata;
	 SDL_Renderer* ren;
	 TTF_Font* Sans=nullptr;
	 SDL_Color White;
	 SDL_Color Black;
	 SDL_Surface* surfaceMessage=nullptr;
	 SDL_Texture* Message=nullptr;
	 SDL_Window* win;
	 bool temp=false;
	 SDL_Surface* rowsBackgroundGenerated=nullptr;
	 SDL_Texture* backgourndTexture=nullptr;
};

#endif /* WINDOWSDL_H_ */
