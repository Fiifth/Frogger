/*
 * Player.cpp
 * This is the object in the game where every prop interacts with.
 * It can create projectile objects.
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */

#include "Player.h"
#include "Factory.h"
using namespace frogger;

Player::Player()
{
}

Player::~Player()
{
	for(Projectile* proj:projectileList)
		delete(proj);
	projectileList.clear();
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

	if (timeToMove()) //takes the divider into account when following the lane object
	{
		if (!row->isDirLeft())
			move(*row->getRowProperties()->getSpeed(), 0, false);
		else
			move(-*row->getRowProperties()->getSpeed(), 0, false);
	}
}

int Player::getLife() const
{
	return life;
}

int Player::getProjectiles() const
{
	return projectiles;
}

int Player::getScore() const
{
	return score;
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
		setDead(true);
	else
		addLife(-1);
}

void Player::resetPosition()
{
	x = startX;
	*y = startY;
	*direction = 'U';
	resetRemainingTime();
}

bool Player::takeAction(std::string key)
{
	if (!isDead())
	{
		if (key == keyDown)
		{
			int yTemp=yR;
			moveDown();
			if (yTemp!=yR)
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
			Projectile* proj=F->createProjectile1();
			proj->setAni(projAni->at(0).clone());
			proj->queryW(h);
			proj->setProperties(nullptr,screenWidth,screenHeight,x,proj->getW(),true);
			proj->initProjectile(5,0,*direction,h,*y,x);
			projectileList.push_back(proj);
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

void Player::resetRemainingTime()
{

	previousTime = std::chrono::high_resolution_clock::now();
}

void Player::decreaseTime()
{
	if (counterEnabled)
	{
		currentTime = std::chrono::high_resolution_clock::now();
		remainingTime = totalTime- ((int)std::chrono::duration_cast<std::chrono::seconds>(currentTime - previousTime).count());
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
	if (player != this) //player cannot be hit by its own projectiles
	{
		projectileList.remove_if(ProjCol(player->getProjectileList()));
		int oldSize = projectileList.size();
		projectileList.remove_if(ProjCol2(player));
		int newSize = projectileList.size();
		if (newSize < oldSize) //if size of projectile list decreases there will have been a collision
			player->hit();
	}
}

void frogger::Player::followScreen(int offset)
{
	move(0, offset, false);
	for (Projectile* proj : projectileList)
		proj->move(0, offset, true);
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

void frogger::Player::setProjAniList(std::vector<frogger::Animator>* projAni)
{
	this->projAni=projAni;
}

bool Player::drawMoveRemove::operator ()(Props* prop)
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
