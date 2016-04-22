/*
 * Entity.cpp
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#include "Entity.h"
#include "Props.h"
#include "Projectile.h"

Entity::Entity() :
		F(nullptr)
{
	x = 30;
	y = 30;
	w = 10;
	h = 10;
	screenWidth = 640;
	screenHeight = 480;
	speed = 50;
}

Entity::~Entity()
{
}

void Entity::move(int deltaX, int deltaY, bool leaveScreen)
{
	int leftLimit, rightLimit, upperLimit, lowerlimit;
	leftLimit = leaveScreen ? -getWidth() * 4 : 0;
	rightLimit = leaveScreen ? screenWidth + getWidth() * 4 : screenWidth;
	upperLimit = leaveScreen ? -getWidth() * 4 : 0;
	lowerlimit = leaveScreen ? screenHeight + getWidth() * 4 : screenHeight;
	if (((x + deltaX + w) <= rightLimit) && (x + deltaX) >= leftLimit)
	{
		x = x + deltaX;
	}
	if (((y + deltaY + h) <= lowerlimit) && (y + deltaY) >= upperLimit)
	{
		y = y + deltaY;
	}
}

void Entity::setSize(int wNew, int hNew)
{
	w = wNew;
	h = hNew;
}
void Entity::setLocation(int xNew, int yNew)
{
	x = xNew;
	y = yNew;
}
void Entity::setScreenSize(int width, int height)
{
	screenWidth = width;
	screenHeight = height;
}
bool Entity::inframe()
{
	return ((x < (screenWidth + (3 * w)) && x > (0 - (3 * w)))
			&& ((y <= screenHeight + h) && (y >= (0 - h))));
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
	return y;
}

int Entity::getHeight() const
{
	return screenHeight;
}

int Entity::getWidth() const
{
	return screenWidth;
}

int Entity::getSpeed() const
{
	return speed;
}

void Entity::setSpeed(int speed)
{
	this->speed = speed;
}
int Entity::getDirection() const
{
	return direction;
}

void Entity::setDirection(int direction)
{
	this->direction = direction;
}

void Entity::setF(Factory* f)
{
	F = f;
}

bool Entity::drawMoveRemove::operator ()(Props* prop)
{
	bool temp = false;
	if (!prop->inframe())
	{
		temp = true;
		delete (prop);
	}
	else
	{
		prop->moveForward();
		if (prop->isVisible())
			prop->draw();

	}
	return temp;
}

bool Entity::colli(Entity* entity)
{
	return (((entity->getY() >= (y) && entity->getY() < (y + h))
			|| (entity->getY() + entity->getH() > (y)
					&& entity->getY() + entity->getH() <= (y + h)))
			&& ((entity->getX() >= (x) && entity->getX() <= (x + w))
					|| (entity->getX() + entity->getW() >= (x)
							&& entity->getX() + entity->getW() <= (x + w))));
}
