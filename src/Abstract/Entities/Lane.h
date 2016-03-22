/*
 * Lane.h
 *
 *  Created on: 18-mrt.-2016
 *      Author: msn-w
 */

#ifndef ABSTRACT_ENTITIES_LANE_H_
#define ABSTRACT_ENTITIES_LANE_H_
#include "Props.h"
class Lane :public Props{
public:
	Lane();
	virtual ~Lane();
	virtual void draw()=0;
};

#endif /* ABSTRACT_ENTITIES_LANE_H_ */
