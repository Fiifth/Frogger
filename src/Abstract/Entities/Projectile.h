/*
 * Projectile.h
 *
 *  Created on: 4-apr.-2016
 *      Author: msn-w
 */

#ifndef ABSTRACT_ENTITIES_PROJECTILE_H_
#define ABSTRACT_ENTITIES_PROJECTILE_H_
#include "Props.h"
#include "Entity.h"
#include "Player.h"
namespace frogger
{
class Projectile: public frogger::Props
{
public:
	Projectile();
	virtual ~Projectile();
	bool itemListEmpty()
	{
		return false;
	}

	void collision(Player* player);

private:

};
}

#endif /* ABSTRACT_ENTITIES_PROJECTILE_H_ */
