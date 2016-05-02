/*
 * EventsSDL.h
 *
 *  Created on: 6-mrt.-2016
 *      Author: msn-w
 */

#ifndef EVENTSSDL_H_
#define EVENTSSDL_H_

#include "Events.h"
#include <string>
namespace frogger
{
class EventsSDL: public frogger::Events
{
public:
	EventsSDL();
	virtual ~EventsSDL();
	std::string getEvent();
	void getMousePos(int* x,int* y);
};
}

#endif /* EVENTSSDL_H_ */
