/*
 * windowSDL.h
 *
 *  Created on: Feb 29, 2016
 *      Author: fifth
 */

#ifndef WINDOWSDL_H_
#define WINDOWSDL_H_
#include "Window.h"
#include "SDL.h"
#include "SDLdata.h"
#include "Row.h"
#include "SDL_ttf.h"
#include "SDL.h"
#include <vector>
#include <algorithm>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <ctime>
#include <ratio>
#include <chrono>
#include <list>
#include "Player.h"
#include "menu/MenuButton.h"
namespace frogger_sdl
{
class WindowSDL: public frogger::Window
{
public:
	WindowSDL(SDLdata* sdldata);
	virtual ~WindowSDL();
	void makeWindow(int ScreenWidth, int ScreenHeight, int dataWindowHeight,
			char const* title);
	void dislayData(std::list<frogger::Player*>* players);
	void displayHighScore(int score1, int score2, int score3, int score4);
	void setBackground(int index);
	void updateScreen();
	void generateBackground(std::vector<frogger::Row*>* rows);
	void saveCurrentWindowImage();
	void drawLineUnder(frogger::MenuButton* mode,frogger::MenuButton* numPlay,frogger::MenuButton* diff);
private:
	SDLdata* sdldata;
	SDL_Renderer* ren;
	TTF_Font* Sans = nullptr;
	SDL_Color White;
	SDL_Color Black;
	SDL_Surface* surfaceMessage = nullptr;
	SDL_Texture* Message = nullptr;
	SDL_Window* win;
	bool temp = false;
	SDL_Surface* rowsBackgroundGenerated = nullptr;
	SDL_Texture* backgourndTexture = nullptr;
	std::chrono::high_resolution_clock::time_point startP =
			std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::time_point endP =
			std::chrono::high_resolution_clock::now();
	std::vector<frogger::Row*> rowsOld;
	std::vector<frogger::Row*>* rowsOldP;
	std::string oldString="";
	std::vector<SDL_Texture*>* MenuTextures;

};
}

#endif /* WINDOWSDL_H_ */
