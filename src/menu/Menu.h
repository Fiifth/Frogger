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
			Menu(Window* win, char* gameMode, int* amountOfPlayers,char* difficulty);
			virtual ~Menu();
			char menuExecution(std::string keyDown, char state, int mXH,
					int mYH, int mXP, int mYP);

		private:
			Window* win;
			char* gameMode;
			int* amountOfPlayers;
			char* difficulty;
			MenuButton* BST;
			MenuButton* BH;
			MenuButton* BQ;
			MenuButton* BHE;
			MenuButton* BS;
			MenuButton* S1;
			MenuButton* S2;
			MenuButton* S3;
			MenuButton* SEN;
			MenuButton* SC;
			MenuButton* SE;
			MenuButton* SM;
			MenuButton* SH;

			MenuButton* DrawLineUnderMode;
			MenuButton* DrawLineUnderNumPlayers;
			MenuButton* DrawLineUnderDifficulty;

			MenuButton* back;
	};
}
#endif /* MENU_H_ */
