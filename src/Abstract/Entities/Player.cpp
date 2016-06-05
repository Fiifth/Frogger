/*
 * Frog.cpp
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */

#include "Player.h"
#include "Factory.h"
using namespace std;
using namespace frogger;

Player::Player() :
		vSpeed(0), hSpeed(0), startX(0), startY(0), totalTime(50), remainingTime(
				totalTime)
{
}

Player::~Player()
{
}

void Player::moveUp()
{
	move(0, (-vSpeed), false);
	*direction = 'U';
	counter = 10;
	moved = true;
}

void Player::moveDown()
{
	move(0, vSpeed, false);
	*direction = 'D';
	counter = 10;
	moved = true;
}

void Player::moveRight()
{
	move(hSpeed / 2, 0, false);
	*direction = 'R';
	counter = 10;
	moved = true;
}

void Player::moveLeft()
{
	move(-(hSpeed / 2), 0, false);
	*direction = 'L';
	counter = 10;
	moved = true;
}

void Player::followRow(Row* row)
{
	if (*divider != *(row->getRowProperties()->getDivider()))
	{
		*divider = *(row->getRowProperties()->getDivider());
		dividerCounter = 0;
	}

	if (timeToMove())
	{
		if (!row->isDirLeft())
			move(*row->getRowProperties()->getSpeed(), 0, false);
		else
			move(-*row->getRowProperties()->getSpeed(), 0, false);
	}

}

int Player::gethSpeed() const
{
	return hSpeed;
}

void Player::sethSpeed(int speed)
{
	hSpeed = speed;
}

int Player::getvSpeed() const
{
	return vSpeed;
}

void Player::setvSpeed(int speed)
{
	vSpeed = speed;
}

int Player::getCounter() const
{
	return counter;
}

void Player::setCounter(int counter)
{
	this->counter = counter;
}

int Player::getLife() const
{
	return life;
}

void Player::setLife(int life)
{
	this->life = life;
}

int Player::getProjectiles() const
{
	return projectiles;
}

void Player::setProjectiles(int projectiles)
{
	this->projectiles = projectiles;
}

int Player::getScore() const
{
	return score;
}

void Player::setScore(int score)
{
	this->score = score;
}

void Player::addLife(int life)
{
	this->life = this->life + life;
}

void Player::addProjectiles(int projectiles)
{
	this->projectiles = this->projectiles + projectiles;
}

void Player::addScore(int score)
{
	this->score = this->score + score;
}

void Player::hit()
{
	resetPosition();
	if (life == 0)
	{
		setDead(true);
	}
	else
	{
		addLife(-1);
	}
}

void Player::resetPosition()
{
	x = startX;
	*y = startY;
	*direction = 'U';
	resetRemainingTime();
}

void Player::setStartPosition(int startX, int startY)
{
	this->startX = startX;
	this->startY = startY;
}

bool Player::takeAction(std::string key)
{
	if (!isDead())
	{
		if (key == keyDown)
		{
			moveDown();
			if (*y > startY)
				addScore(-scorePerStep);
		}
		else if (key == keyUp)
		{
			moveUp();
			addScore(scorePerStep);
			return true;
		}
		else if (key == keyLeft)
			moveLeft();
		else if (key == keyRight)
			moveRight();
		else if (key == fire && getProjectiles() > 0)
		{
			addProjectiles(-1);
			projectileList.push_back(F->createProjectile(this, nullptr, 5, 0));
		}
	}
	return false;
}

int Player::getRemainingTime()
{
	if (!dead)
		decreaseTime();
	return remainingTime;
}

void Player::setRemainingTime(int remainingTime)
{
	this->remainingTime = remainingTime;
}

void Player::resetRemainingTime()
{

	previousTime = std::chrono::high_resolution_clock::now();
}

void Player::decreaseTime()
{
	if (counterEnabled)
	{
		currentTime = std::chrono::high_resolution_clock::now();
		remainingTime = totalTime
				- (std::chrono::duration_cast<std::chrono::seconds>(
						currentTime - previousTime).count());
	}
}

bool Player::isDead() const
{
	return dead;
}

void Player::setDead(bool dead)
{
	this->dead = dead;
}
bool Player::timeToMove()
{
	if (dividerCounter == 0)
	{
		dividerCounter = *divider;
		return true;
	}
	else
	{
		dividerCounter = dividerCounter - 1;
		return false;
	}
}

void Player::setDifferentControls(char set)
{
	if (set == 'A')
	{
		keyUp = "Z";
		keyDown = "S";
		keyLeft = "Q";
		keyRight = "D";
		fire = "E";
	}
	else if (set == 'B')
	{
		keyUp = "Y";
		keyDown = "H";
		keyLeft = "G";
		keyRight = "J";
		fire = "U";
	}
	else if (set == 'C')
	{
		keyUp = "Up";
		keyDown = "Down";
		keyLeft = "Left";
		keyRight = "Right";
	}
}

std::list<Projectile*>* Player::getProjectileList()
{
	return &projectileList;
}

void Player::collision(Player* player)
{
	if (player != this)
	{
		projectileList.remove_if(ProjCol(player->getProjectileList()));
		int oldSize = projectileList.size();
		projectileList.remove_if(ProjCol2(player));
		int newSize = projectileList.size();
		if (newSize < oldSize)
			player->hit();
	}
}

void Player::disableCounter()
{
	counterEnabled = false;
}

void frogger::Player::followScreen(int offset)
{
	move(0, offset, false);

	for (Projectile* proj : projectileList)
	{
		proj->move(0, offset, true);
	}
}

void frogger::Player::setParameters(int life, int totalTime,
		bool counterEnabled, int scorePerStep, int projectiles)
{
	this->totalTime = totalTime;
	this->remainingTime = totalTime;
	this->counterEnabled = counterEnabled;
	this->life = life;
	this->scorePerStep = scorePerStep;
	this->projectiles = projectiles;
}

void frogger::Player::initPlayer(int hSpeed, int vSpeed, int w, int h, int x,
		int y, int xS, int yS, int* screenW, int* screenH)
{
	this->vSpeed=vSpeed;
	this->hSpeed=hSpeed;
	this->startX=xS;
	this->startY=yS;
	this->w=w;
	this->h=h;
	this->x=x;
	*this->y=y;
	this->screenWidth=screenW;
	this->screenHeight=screenH;
}
