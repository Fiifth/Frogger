/*
 * Events.h
 *
 *  Created on: 6-mrt.-2016
 *      Author: msn-w
 */

#ifndef EVENTS_H_
#define EVENTS_H_
#include <string>

class Events
{
public:
	Events();
	virtual ~Events();
	virtual std::string getEvent()=0;
	virtual void getMousePos(int* x,int* y)=0;
};

#endif /* EVENTS_H_ */
