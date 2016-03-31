/*
 * Animator.h
 *
 *  Created on: 25-mrt.-2016
 *      Author: msn-w
 */

#include "SDL.h"
#include <vector>

#ifndef ANIMATOR_H_
#define ANIMATOR_H_

class Animator {
public:
	Animator(std::vector<SDL_Texture*> textures,std::vector<int> ratio);
	virtual ~Animator();
	SDL_Texture* getTexture();
	int getCounter() const;
	void setCounter(int counter);
	int getCurrentTexture() const;
	void setCurrentTexture(int currentTexture);
	void triggerNext(int counter);

	std::vector<SDL_Texture*> textures;
	std::vector<int> ratio;
	int counter;
	int currentTexture;
};

#endif /* ANIMATOR_H_ */
