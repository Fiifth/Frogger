/*
 * windowSDL.h
 *
 *  Created on: Feb 29, 2016
 *      Author: fifth
 */

#ifndef CONCRETE_WINDOWSDL_H_
#define CONCRETE_WINDOWSDL_H_
#include <abstract/entities/Player.h>
#include <abstract/Row.h>
#include <abstract/Window.h>
#include <concrete/SDLdata.h>
#include "SDL.h"
#include "SDL_ttf.h"
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <ratio>
#include <chrono>
#include <list>
#include <string>
#include "menu/MenuButton.h"
#include <math.h>

namespace frogger_sdl
{
	class WindowSDL: public frogger::Window
	{
		public:
			explicit WindowSDL(SDLdata* sdldata);
			virtual ~WindowSDL();
			void makeWindow(int ScreenWidth, int ScreenHeight,int dataWindowHeight, char const* title);
			void dislayData(std::list<frogger::Player*>* players);
			void displayHighScore(std::vector<int> highScore,bool newScore);
			void makeHighScoreTexture(std::vector<int> highScore);
			void setBackground(int index);
			void updateScreen();
			void generateBackground(std::vector<frogger::Row*>* rows);
			void drawLineUnder(frogger::MenuButton* mode,	frogger::MenuButton* numPlay, frogger::MenuButton* diff);
		private:
			SDLdata* sdldata;
			SDL_Renderer* ren;
			TTF_Font* sans1 = nullptr;
			TTF_Font* sans2 = nullptr;
			SDL_Color white;
			SDL_Color black;
			SDL_Color blue;

			SDL_Texture* playerDataTex = nullptr;
			SDL_Rect PlayerMessageRect;
			std::vector<SDL_Texture*> highScoreTexV;
			std::vector<SDL_Rect> highScoreRectV;
			SDL_Window* win;

			std::chrono::high_resolution_clock::time_point startP =
					std::chrono::high_resolution_clock::now();
			std::chrono::high_resolution_clock::time_point endP =
					std::chrono::high_resolution_clock::now();

			std::chrono::high_resolution_clock::time_point startT =
					std::chrono::high_resolution_clock::now();
			std::chrono::high_resolution_clock::time_point endT =
					std::chrono::high_resolution_clock::now();

			std::string oldString = "";
			std::vector<SDL_Texture*>* MenuTextures;

	};
}

#endif /* WINDOWSDL_H_ */
