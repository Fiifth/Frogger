/*
 * EventsSDL.h
 *
 *  Created on: 6-mrt.-2016
 *      Author: Kwinten
 */

#ifndef CONCRETE_EVENTSSDL_H_
#define CONCRETE_EVENTSSDL_H_

#include <abstract/Events.h>
#include <string>
namespace frogger_sdl
{
	class EventsSDL: public frogger::Events
	{
		public:
			EventsSDL();
			virtual ~EventsSDL();
			std::string getEvent();
			void getMousePos(int* x, int* y);
	};
}

#endif /* EVENTSSDL_H_ */
