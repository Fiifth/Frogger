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
	size=textures.size();
}

Animator::~Animator()
{}

SDL_Texture* Animator::getTexture()
{
	std::cout<<"yey1"<<std::endl;
	std::cout<<ratio.at(0)<<std::endl;
	std::cout<<ratio.size()<<std::endl;
	SDL_Texture* texture;
	if(size>1)
	{
		if (counter>0)
		{
			counter--;
		}
		else
		{
			if(size>(currentTexture+1)&&ratio.at(currentTexture+1)>0)
			{
			currentTexture=currentTexture+1;
			counter=ratio.at(currentTexture);
			}
			else
			{
				currentTexture=0;
				counter=ratio.at(0);
			}
		}
		texture=textures.at(currentTexture);
		return texture;
	}
	else
	{
		std::cout<<"yey"<<std::endl;
		return textures.back();
	}
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

void Animator::triggerNext(int counter)
{
	if (ratio.size()<currentTexture+1)
	{
	currentTexture=currentTexture+1;
	this->counter=counter;
	}

}

Animator* Animator::clone() {
	return new Animator(*this);
}
