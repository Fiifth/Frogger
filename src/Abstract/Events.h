/*
 * Events.h
 *
 *  Created on: 6-mrt.-2016
 *      Author: msn-w
 */
#include <string>

#ifndef EVENTS_H_
#define EVENTS_H_

class Events {
public:
	Events();
	virtual ~Events();
	virtual std::string getEvent()=0;
};

#endif /* EVENTS_H_ */
