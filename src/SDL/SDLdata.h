/*
 * SDLstuff.h
 *
 *  Created on: 7-mrt.-2016
 *      Author: msn-w
 */

#ifndef SDLSTUFF_H_
#define SDLSTUFF_H_
#include "SDL.h"
#include <vector>
#include "Animator.h"
#include <string>
namespace frogger_sdl
{
class SDLdata
{
public:
	SDLdata();
	virtual ~SDLdata();
	void setBackground(SDL_Texture* texB);
	void updateScreen();
	SDL_Renderer* getRen();
	void setRen(SDL_Renderer* rende);
	void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y,
			int* w, int h, int angle);
	int getDW(SDL_Texture* tex, int h);
	void createTextures();
	SDL_Texture* getBackgroundTexture();
	std::vector<SDL_Texture*> getPlayerTextures();
	std::vector<SDL_Texture*> getObstTextures();
	std::vector<SDL_Texture*> getLaneTextures();
	std::vector<SDL_Texture*> getItemTextures();
	std::vector<SDL_Texture*> getBackTextures();
	void setScreenDimension(int* gameWidth, int* gameHeight);
	Animator getAnimator(std::vector<std::string> paths,
			std::vector<int> ratio);
	Animator getItemAni(int ind);
	Animator getLaneAni(int ind);
	Animator getObstiAni(int ind);
	Animator getPlayerAni(int ind);
	Animator getProjAni(int ind);
	int* getScrH() const;
	void setScreenHeight(int* screenHeight);
	int* getScrW() const;
	void setScreenWidth(int* screenWidth);
	SDL_Texture* getBackgroundTex();
	SDL_Texture* getHighSelTex();
	SDL_Texture* getQuitSelTex();
	SDL_Texture* getStartSelTex();
	SDL_Texture* getHighScoreTex();
	SDL_Texture* getHighScoreBackSel();
protected:
	int* screenWidth;
	int* screenHeight;
	SDL_Renderer* re;
	SDL_Texture* backgroundTex;
	SDL_Texture* quitSelTex ;
	SDL_Texture* startSelTex ;
	SDL_Texture* highSelTex ;
	SDL_Texture* HighScoreTex;
	SDL_Texture* HighScoreBackSelTex;
	std::vector<SDL_Texture*> playerTex;
	std::vector<SDL_Texture*> ObstTex;
	std::vector<SDL_Texture*> laneTex;
	std::vector<SDL_Texture*> itemTex;
	std::vector<SDL_Texture*> backTex;
	std::vector<Animator> obstiAni;
	std::vector<Animator> laneAni;
	std::vector<Animator> playerAni;
	std::vector<Animator> itemAni;
	std::vector<Animator> projAni;
};
}

#endif /* SDLSTUFF_H_ */
