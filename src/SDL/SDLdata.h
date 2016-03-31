/*
 * SDLstuff.h
 *
 *  Created on: 7-mrt.-2016
 *      Author: msn-w
 */

#include "SDL.h"
#include <vector>
#include "Animator.h"
#ifndef SDLSTUFF_H_
#define SDLSTUFF_H_

class SDLdata {
public:
	SDLdata();
	virtual ~SDLdata();
	void setBackground(SDL_Texture* texB);
	void updateScreen();
	SDL_Renderer* getRen();
	void setRen(SDL_Renderer* rende);
	void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int* w, int* h,int angle);
	void getDependWAndH(SDL_Texture* tex,int* w, int* h);
	void createTextures();
	SDL_Texture* getBackgroundTexture();
	std::vector<SDL_Texture*> getPlayerTextures();
	std::vector<SDL_Texture*> getObstTextures();
	std::vector<SDL_Texture*> getLaneTextures();
	std::vector<SDL_Texture*> getItemTextures();
	std::vector<SDL_Texture*> getBackTextures();
	void setScreenDimension(int width,int height,int dataWindowHeight);

	int getScreenHeight() const {
		return screenHeight;
	}

	int getScreenWidth() const {
		return screenWidth;
	}

private:
	int screenWidth;
	int screenHeight;
	SDL_Renderer* re;
	SDL_Texture* backgroundTex;
	std::vector<SDL_Texture*> playerTex;
	std::vector<SDL_Texture*> ObstTex;
	std::vector<SDL_Texture*> laneTex;
	std::vector<SDL_Texture*> itemTex;
	std::vector<SDL_Texture*> backTex;
	std::vector<Animator*> obstiAni;
	std::vector<Animator*> laneAni;
	std::vector<Animator*> playerAni;
	std::vector<Animator*> itemAni;
};

#endif /* SDLSTUFF_H_ */
