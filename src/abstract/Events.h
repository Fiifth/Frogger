/*
 * Events.h
 *
 *  Created on: 6-mrt.-2016
 *      Author: Kwinten
 */

#ifndef ABSTRACT_EVENTS_H_
#define ABSTRACT_EVENTS_H_
#include <string>
namespace frogger
{
	class Events
	{
		public:
			Events();
			virtual ~Events();
			virtual std::string getEvent()=0;
			virtual void getMousePos(int* x, int* y)=0;
	};
}

#endif /* EVENTS_H_ */
