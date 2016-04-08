/*
 * Level.h
 *
 *  Created on: 8-apr.-2016
 *      Author: msn-w
 */

#ifndef LEVEL_H_
#define LEVEL_H_
#include <vector>
#include <Row.h>
#include <list>
#include "Projectile.h"
#include "Props.h"

class Level {
public:
	Level();
	virtual ~Level();
private:
	int rowHeight=50;
	int difficultyRows=1;
	int dataWindowHeight=20;
	int WindowHeight=520;
	int WindowWidth=700;
	int difficulty=40;
	std::list<Projectile*>*projectiles;
	std::vector<Row*>* rows;
	std::vector<std::list<Props*>>* propsOnRow;
};

#endif /* LEVEL_H_ */
