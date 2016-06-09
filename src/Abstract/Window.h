/*
 * window.h
 *
 *  Created on: Feb 29, 2016
 *      Author: fifth
 */

#ifndef ABSTRACT_WINDOW_H_
#define ABSTRACT_WINDOW_H_
#include <string>
#include <vector>
#include <list>
#include "Row.h"
#include "Player.h"

namespace frogger
{
	class Player;
	class MenuButton;
	class Window
	{
		public:
			Window();
			virtual ~Window();
			virtual void makeWindow(int ScreenWidth, int ScreenHeight, int dataWindowHeight, char const* title)=0;
			virtual void setBackground(int index)=0;
			virtual void updateScreen()=0;
			virtual void displayHighScore(std::vector<int> highScore,bool newScore)=0;
			virtual void generateBackground(std::vector<Row*>* rows)=0;
			virtual void dislayData(std::list<Player*>* players)=0;
			virtual void drawLineUnder(frogger::MenuButton* mode, frogger::MenuButton* numPlay, frogger::MenuButton* diff)=0;
			void setProp(int width, int height, int dataWindowHeight,	char const* title);
			int* getGameWindowHeight() const;
			int* getHeight() const;
			int* getWidth() const;
		protected:
			int screenWidthR;
			int screenHeightR;
			int* screenWidth = &screenWidthR;
			int* screenHeight = &screenHeightR;
			int dataWindowHeightR;
			int gameWindowHeightR;
			int* dataWindowHeight = &dataWindowHeightR;
			int* gameWindowHeight = &dataWindowHeightR;
			char const * TITLE;
	};
}

#endif /* ABSTRACT_WINDOW_H_ */
