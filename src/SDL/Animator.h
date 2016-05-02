/*
 * Animator.h
 *
 *  Created on: 25-mrt.-2016
 *      Author: msn-w
 */

#ifndef ANIMATOR_H_
#define ANIMATOR_H_
#include "SDL.h"
#include <vector>
namespace frogger_sdl
{
class Animator
{
public:
	Animator(std::vector<SDL_Texture*> textures, std::vector<int> ratio);
	virtual ~Animator();
	SDL_Texture* getTexture();
	int getCounter() const;
	void setCounter(int counter);
	int getCurrentTexture() const;
	void setCurrentTexture(int currentTexture);
	void triggerNext(int counter);
	Animator* clone();
	bool isTurned() const;
	void setTurned(bool turned);
	void setCurrentTextureFor(int texture,int counter);

	std::vector<SDL_Texture*> textures;
	std::vector<int> ratio;
	int counter = 0;
	int currentTexture = 0;
	int size;
	bool turned = false;
};
}

#endif /* ANIMATOR_H_ */
