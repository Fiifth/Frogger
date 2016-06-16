/*
 * Entity.cpp
 *
 * This object represents the underlying object of all game entities that have a location.
 *  Created on: 12-mrt.-2016
 *      Author: Kwinten
 */

#include "Abstract/Entity.h"
#include "Abstract/Entities/Projectile.h"
using namespace frogger;
Entity::Entity()
{
	x=0;
	yR=0;
	w=0;
	h=0;
	speedR=0;
	dividerR=0;
	dividerCounter=0;
	directionR = 'U';

	direction = &directionR;
	y = &yR;
	speed = &speedR;
	divider = &dividerR;

	F=nullptr;
	screenWidth=nullptr;
	screenHeight=nullptr;
	ani=nullptr;
}

Entity::~Entity()
{
	delete(ani);
}

void Entity::move(int deltaX, int deltaY, bool leaveScreen)
{ //leaveScreen determines if the object is allowed to go offscreen (the player will not be allowed/obstacles have to leave screen)
	int leftLimit, rightLimit, upperLimit, lowerlimit;
	leftLimit = leaveScreen ? -*screenWidth * 4 : 0;
	rightLimit = leaveScreen ? *screenWidth + getScrWidth() * 4 : *screenWidth;
	upperLimit = leaveScreen ? -*screenWidth * 4 : 0;
	lowerlimit =
			leaveScreen ?
					(*screenHeight) + (*screenWidth) * 4 : (*screenHeight);
	if (((x + deltaX + w) <= rightLimit) && (x + deltaX) >= leftLimit)
	{
		x = x + deltaX;
	}
	if (((*y + deltaY + h) <= lowerlimit) && (*y + deltaY) >= upperLimit)
	{
		*y = *y + deltaY;
	}
}

void Entity::setLocation(int xNew, int yNew)
{
	x = xNew;
	*y = yNew;
}
bool Entity::inframe()
{
	return ((x < (*screenWidth + (3 * w)) && x > (0 - (3 * w)))
			&& ((*y <= *screenHeight + h * 4) && (*y >= (0 - h * 4))));
}

int Entity::getH() const
{
	return h;
}

int Entity::getW() const
{
	return w;
}

int Entity::getX() const
{
	return x;
}

int Entity::getY() const
{
	return *y;
}

int Entity::getScrHeight() const
{
	return *screenHeight;
}

int Entity::getScrWidth() const
{
	return *screenWidth;
}

int Entity::getSpeed() const
{
	return *speed;
}

char Entity::getDirection() const
{
	return *direction;
}

void Entity::setF(Factory* f)
{
	F = f;
}


bool Entity::colli(Entity* entity)
{
	return (colli2(this, entity) || colli2(entity, this));
}


bool Entity::colli2(Entity* entity1, Entity* entity2)
{
	int ay1 = entity1->getY();
	int ay2 = entity1->getY() + entity1->getH();
	int by1 = entity2->getY();
	int by2 = entity2->getY() + entity2->getH();
	int ax1 = entity1->getX();
	int ax2 = entity1->getX() + entity1->getW();
	int bx1 = entity2->getX();
	int bx2 = entity2->getX() + entity2->getW();

	return (((ay1 >= by1 && ay1 < by2) || (ay2 > by1 && ay2 <= by2))
			&& ((ax1 >= bx1 && ax1 <= bx2) || (ax2 >= bx1 && ax2 <= bx2)));
}

bool frogger::Entity::ProjCol2::operator ()(Entity* projectile) const
{
	if (projectile->colli(project))
	{
		delete (projectile);
		return true;
	}
	else
		return false;
}

void frogger::Entity::setSpeed(int speed)
{
	speedR=speed;
	this->speed = &speedR;
	this->divider = &dividerR;
}

void frogger::Entity::setAni(frogger::Animator* ani)
{
	this->ani = ani;
}

bool frogger::Entity::ProjCol::operator ()(Entity* projectile) const
{
	int prevSize = projectList->size();
	projectList->remove_if(ProjCol2(projectile));
	int newSize = projectList->size();
	if (newSize < prevSize)
		delete (projectile);
	return newSize < prevSize;
}
