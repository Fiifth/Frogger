/*
 * window.h
 *
 *  Created on: Feb 29, 2016
 *      Author: fifth
 */

#ifndef WINDOW_H_
#define WINDOW_H_
#include <string>
#include <vector>
#include "Row.h"
#include "Player.h"
#include <list>

namespace frogger
{
	class Player;
	class MenuButton;
	class Window
	{
		public:
			Window();
			virtual ~Window();
			virtual void makeWindow(int ScreenWidth, int ScreenHeight,
					int dataWindowHeight, char const* title)=0;
			void setProp(int width, int height, int dataWindowHeight,
					char const* title);
			virtual void setBackground(int index)=0;
			virtual void updateScreen()=0;
			int* getHeight() const;
			int* getWidth() const;
			virtual void displayHighScore(std::vector<int> highScore,bool newScore)=0;
			virtual void generateBackground(std::vector<Row*>* rows)=0;
			int* getGameWindowHeight() const;
			virtual void dislayData(std::list<Player*>* players)=0;
			virtual void drawLineUnder(frogger::MenuButton* mode,
					frogger::MenuButton* numPlay, frogger::MenuButton* diff)=0;

		protected:
			int WIDTHR;
			int HEIGHTR;
			int* WIDTH = &WIDTHR;
			int* HEIGHT = &HEIGHTR;
			int dataWindowHeightR;
			int gameWindowHeightR;
			int* dataWindowHeight = &dataWindowHeightR;
			int* gameWindowHeight = &dataWindowHeightR;
			char const * TITLE;
	};
}

#endif /* WINDOW_H_ */
