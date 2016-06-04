/*
 * Projectile.cpp
 *
 *  Created on: 4-apr.-2016
 *      Author: msn-w
 */

#include <Projectile.h>
#include "Player.h"
#include <iostream>
using namespace frogger;

Projectile::Projectile()
{
}

Projectile::~Projectile()
{
}

bool frogger::Projectile::itemListEmpty()
{
	return false;
}

void Projectile::collision(Player* player)
{
}
