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
class EventsSDL: public Events
{
public:
	EventsSDL();
	virtual ~EventsSDL();
	std::string getEvent();
};

#endif /* EVENTSSDL_H_ */
