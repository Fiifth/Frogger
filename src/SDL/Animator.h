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
			Animator(std::vector<int> index, std::vector<int> ratio);
			virtual ~Animator();
			int getIndex();
			int getCounter() const;
			void setCounter(int counter);
			int getCurrentTexture() const;
			void setCurrentTexture(int currentTexture);
			void triggerNext(int counter);
			Animator* clone();
			bool isTurned() const;
			void setTurned(bool turned);
			void setCurrentTextureFor(int texture, int counter);
		protected:
			std::vector<int> index;
			std::vector<int> ratio;
			int counter;
			int currentTexture;
			int size;
			bool turned;
	};
}

#endif /* ANIMATOR_H_ */
