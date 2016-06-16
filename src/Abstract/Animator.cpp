/*
 * Animator.cpp
 *
 * The Animator gives the right indexes to entities. These indexes refer to the position of the textures in a texture vector.
 * The animator mainly consist of a vector of indexes and a vector of ratios. The ratios determin how long a specific index
 * should remain before moving on to the next index.
 *
 *  Created on: 25-mrt.-2016
 *      Author: Kwinten
 */

#include <Abstract/Animator.h>
#include <stdlib.h>
using namespace frogger;

Animator::Animator(std::vector<int> index, std::vector<int> ratio) :
		index(index), ratio(ratio), counter(abs(ratio.at(0))), currentTexture(0),turned(false)
{
	size = index.size();
}

Animator::~Animator()
{
}

int Animator::getIndex()
{
	if (size > 1)
	{
		if (counter >= 1000)
		{
		}
		else if (counter > 0)
		{
			counter--;
		}
		else
		{
			if (size > (currentTexture + 1)
					&& abs(ratio.at(currentTexture + 1)) > 0)
			{
				currentTexture = currentTexture + 1;
				counter = abs(ratio.at(currentTexture));
				turned = (ratio.at(currentTexture) < 0);
			}
			else
			{
				currentTexture = 0;
				counter = abs(ratio.at(currentTexture));
				turned = (ratio.at(currentTexture) < 0);
			}
		}

		return index.at(currentTexture);
	}
	else
	{
		return index.back();
	}
}

int Animator::getCounter() const
{
	return counter;
}

void Animator::setCounter(int counter)
{
	this->counter = counter;
}

int Animator::getCurrentTexture() const
{
	return currentTexture;
}

void Animator::setCurrentTexture(int currentTexture)
{
	this->currentTexture = currentTexture;
}

void Animator::triggerNext(int counter)
{
	if (ratio.size() < (unsigned) currentTexture + 1)
	{
		currentTexture = currentTexture + 1;
		this->counter = counter;
	}
}

Animator* Animator::clone()
{
	return new Animator(*this);
}

bool Animator::isTurned() const
{
	return turned;
}

void Animator::setTurned(bool turned)
{
	this->turned = turned;
}

void Animator::setCurrentTextureFor(int texture, int counter)
{
	currentTexture = texture;
	this->counter = counter;
}
