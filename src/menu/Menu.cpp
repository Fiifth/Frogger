/*
 * Menu.cpp
 *
 *  Created on: 24-apr.-2016
 *      Author: msn-w
 */

#include <Menu.h>
#include "MenuButton.h"
using namespace frogger;

Menu::Menu(Window* win, char* gameMode, int* amountOfPlayers, char* difficulty) :
		win(win), gameMode(gameMode), amountOfPlayers(amountOfPlayers), difficulty(
				difficulty)
{

	BST = new MenuButton(0.29054, 0.41458, 0.43074, 0.07289, win);
	BH = new MenuButton(0.30574, 0.57631, 0.39358, 0.06378, win);
	BQ = new MenuButton(0.41216, 0.72665, 0.17399, 0.082, win);
	BHE = new MenuButton(0.0152, 0.89294, 0.16892, 0.082, win);
	BS = new MenuButton(0.65034, 0.89522, 0.33784, 0.08656, win);
	HB = new MenuButton(0.38514, 0.83144, 0.20608, 0.09112, win);
	S1 = new MenuButton(0.45101, 0.55809, 0.0777, 0.05011, win);
	S2 = new MenuButton(0.58615, 0.55809, 0.06419, 0.05011, win);
	S3 = new MenuButton(0.72973, 0.55125, 0.06926, 0.05011, win);
	SB = new MenuButton(0.38514, 0.8656, 0.19932, 0.08428, win);
	SEN = new MenuButton(0.72635, 0.40091, 0.18919, 0.05011, win);
	SC = new MenuButton(0.47804, 0.40091, 0.16892, 0.05011, win);
	SE = new MenuButton(0.47635, 0.70843, 0.1098, 0.05011, win);
	SM = new MenuButton(0.62331, 0.70843, 0.17736, 0.05011, win);
	SH = new MenuButton(0.85642, 0.70843, 0.125, 0.05011, win);
	GR = new MenuButton(0.35304, 0.49886, 0.31757, 0.09112, win);
	GM = new MenuButton(0.41554, 0.78132, 0.21453, 0.09112, win);
	VN = new MenuButton(0.29899, 0.46014, 0.40878, 0.09112, win);
	VM = new MenuButton(0.39865, 0.68337, 0.21115, 0.08428, win);

	DrawLineUnderMode = SEN;
	DrawLineUnderNumPlayers = S1;
	DrawLineUnderDifficulty = SE;

}

Menu::~Menu()
{
	delete(BST);
	delete(BH);
	delete(BQ);
	delete(BHE);
	delete(BS);
	delete(HB);
	delete(S1);
	delete(S2);
	delete(S3);
	delete(SB);
	delete(SEN);
	delete(SC);
	delete(SE);
	delete(SM);
	delete(SH);
	delete(GR);
	delete(GM);
	delete(VN);
	delete(VM);

	delete(DrawLineUnderMode);
	delete(DrawLineUnderNumPlayers);
	delete(DrawLineUnderDifficulty);
}

char Menu::menuExecution(std::string keyDown, char state, int mXH, int mYH,
		int mXP, int mYP)
{
	//menuTextures={B,BH,BHE,BQ,BS,BST,G,GM,GR,H,HB,S,SB,V,VM,VN};
	switch (state)
	{
		case 'B':
			if (BST->col(mXH, mYH))
			{
				win->setBackground(5);
				if (keyDown == "MOUSEBUTTONDOWN")
					return 'E';
			}
			else if (BH->col(mXH, mYH))
			{
				win->setBackground(1);
				if (keyDown == "MOUSEBUTTONDOWN")
					return 'H';
			}
			else if (BQ->col(mXH, mYH))
			{
				win->setBackground(3);
				if (keyDown == "MOUSEBUTTONDOWN")
					return 'Q';
			}
			else if (BHE->col(mXH, mYH))
			{
				win->setBackground(2);
				if (keyDown == "MOUSEBUTTONDOWN")
					return 'B';
			}
			else if (BS->col(mXH, mYH))
			{
				win->setBackground(4);
				if (keyDown == "MOUSEBUTTONDOWN")
					return 'S';
			}
			else
			{
				win->setBackground(0);
				if (keyDown == "Escape")
					return 'Q';
				else
					return state;
			}
			break;
		case 'H':
			if (HB->col(mXH, mYH))
			{
				win->setBackground(10);
				if (keyDown == "MOUSEBUTTONDOWN")
					state = 'B';
			}
			else
			{
				win->setBackground(9);
				if (keyDown == "Escape")
					return 'Q';
				else
					return state;
			}
			break;
		case 'S':
			if (S1->col(mXH, mYH) && keyDown == "MOUSEBUTTONDOWN")
			{
				*amountOfPlayers = 1;
				DrawLineUnderNumPlayers = S1;
				win->setBackground(11);
				win->drawLineUnder(DrawLineUnderMode, DrawLineUnderNumPlayers,
						DrawLineUnderDifficulty);
				return state;
			}
			else if (S2->col(mXH, mYH) && keyDown == "MOUSEBUTTONDOWN")
			{
				*amountOfPlayers = 2;
				DrawLineUnderNumPlayers = S2;
				win->setBackground(11);
				win->drawLineUnder(DrawLineUnderMode, DrawLineUnderNumPlayers,
						DrawLineUnderDifficulty);
				return state;
			}
			else if (S3->col(mXH, mYH) && keyDown == "MOUSEBUTTONDOWN")
			{
				*amountOfPlayers = 3;
				DrawLineUnderNumPlayers = S3;
				win->setBackground(11);
				win->drawLineUnder(DrawLineUnderMode, DrawLineUnderNumPlayers,
						DrawLineUnderDifficulty);
				return state;
			}
			else if (SB->col(mXH, mYH))
			{
				win->setBackground(12);
				win->drawLineUnder(DrawLineUnderMode, DrawLineUnderNumPlayers,
						DrawLineUnderDifficulty);
				if (keyDown == "MOUSEBUTTONDOWN")
					return 'B';
			}
			else if (SEN->col(mXH, mYH) && keyDown == "MOUSEBUTTONDOWN")
			{
				*gameMode = 'E';
				DrawLineUnderMode = SEN;
				win->setBackground(11);
				win->drawLineUnder(DrawLineUnderMode, DrawLineUnderNumPlayers,
						DrawLineUnderDifficulty);
				return state;
			}
			else if (SC->col(mXH, mYH) && keyDown == "MOUSEBUTTONDOWN")
			{
				*gameMode = 'C';
				DrawLineUnderMode = SC;
				win->setBackground(11);
				win->drawLineUnder(DrawLineUnderMode, DrawLineUnderNumPlayers,
						DrawLineUnderDifficulty);
				return state;
			}
			else if (SE->col(mXH, mYH) && keyDown == "MOUSEBUTTONDOWN")
			{
				*difficulty = 'E';
				DrawLineUnderDifficulty = SE;
				win->setBackground(11);
				win->drawLineUnder(DrawLineUnderMode, DrawLineUnderNumPlayers,
						DrawLineUnderDifficulty);
				return state;
			}
			else if (SM->col(mXH, mYH) && keyDown == "MOUSEBUTTONDOWN")
			{
				*difficulty = 'M';
				DrawLineUnderDifficulty = SM;
				win->setBackground(11);
				win->drawLineUnder(DrawLineUnderMode, DrawLineUnderNumPlayers,
						DrawLineUnderDifficulty);
				return state;
			}
			else if (SH->col(mXH, mYH) && keyDown == "MOUSEBUTTONDOWN")
			{
				*difficulty = 'H';
				DrawLineUnderDifficulty = SH;
				win->setBackground(11);
				win->drawLineUnder(DrawLineUnderMode, DrawLineUnderNumPlayers,
						DrawLineUnderDifficulty);
				return state;
			}
			else
			{
				win->setBackground(11);
				win->drawLineUnder(DrawLineUnderMode, DrawLineUnderNumPlayers,
						DrawLineUnderDifficulty);
				return state;
			}
			break;
		case 'G':
			if (GM->col(mXH, mYH))
			{
				win->setBackground(7);
				if (keyDown == "MOUSEBUTTONDOWN")
					return 'B';
			}
			else if (GR->col(mXH, mYH))
			{
				win->setBackground(8);
				if (keyDown == "MOUSEBUTTONDOWN")
					return 'E';
			}
			else
			{
				win->setBackground(6);
				return state;
			}
			break;
		case 'V':
			if (VN->col(mXH, mYH))
			{
				win->setBackground(15);
				if (keyDown == "MOUSEBUTTONDOWN")
					return 'C';
			}
			else if (VM->col(mXH, mYH))
			{
				win->setBackground(14);
				if (keyDown == "MOUSEBUTTONDOWN")
					return 'B';
			}
			else
			{
				win->setBackground(13);
				return state;
			}
			break;

	}
	return state;
}

