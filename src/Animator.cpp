/*
 * Animator.cpp
 *
 *  Created on: 25-mrt.-2016
 *      Author: msn-w
 */

#include <Animator.h>
#include <iostream>

Animator::Animator(std::vector<SDL_Texture*> textures,std::vector<int> ratio):textures(textures),ratio(ratio),
																				counter(ratio.at(0)),currentTexture(0)
{
}

Animator::~Animator()
{}

SDL_Texture* Animator::getTexture()
{
	SDL_Texture* texture;
	if (counter>0)
	{
		counter--;
	}
	else
	{
		if(textures.size()>((unsigned)currentTexture+1))
		{
		currentTexture=currentTexture+1;
		counter=ratio.at(currentTexture);
		}
		else
		{
			currentTexture=0;
			counter=ratio.at(currentTexture);
		}
	}
	texture=textures.at(currentTexture);
	return texture;
}

int Animator::getCounter() const {
	return counter;
}

void Animator::setCounter(int counter) {
	this->counter = counter;
}

int Animator::getCurrentTexture() const {
	return currentTexture;
}

void Animator::setCurrentTexture(int currentTexture) {
	this->currentTexture = currentTexture;
}
