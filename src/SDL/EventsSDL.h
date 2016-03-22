/*
 * EventsSDL.h
 *
 *  Created on: 6-mrt.-2016
 *      Author: msn-w
 */
#include "Events.h"
#include <string>
#ifndef EVENTSSDL_H_
#define EVENTSSDL_H_

class EventsSDL :public Events{
public:
	EventsSDL();
	virtual ~EventsSDL();
	std::string getEvent();
};

#endif /* EVENTSSDL_H_ */
