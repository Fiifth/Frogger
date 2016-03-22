/*
 * Frog.cpp
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */

#include "Player.h"

using namespace std;


Player::Player():vSpeed(0),hSpeed(0),direction(1)
{}

Player::~Player() {
}

void Player::moveUp()
{
	move(0,(-vSpeed),false);
	direction=0;
	counter=10;
}

void Player::moveDown()
{
	move(0,vSpeed,false);
	direction=180;
	counter=10;
}

void Player::moveRight()
{
	move(hSpeed/2,0,false);
	direction=90;
	counter=10;
}

void Player::moveLeft()
{
	move(-(hSpeed/2),0,false);
	direction=270;
	counter=10;
}

void Player::followRow(Row* row) {
	if(!row->isDirection())
		//move(1+(((row->getSpeed())*2)/10),0,true);
			move(row->getSpeed(),0,false);
		else
			move(-row->getSpeed(),0,false);
		//move(-(1+(((row->getSpeed())*3)/10)),0,true);
}

int Player::gethSpeed() const {
	return hSpeed;
}

void Player::sethSpeed(int speed) {
	hSpeed = speed;
}

int Player::getvSpeed() const {
	return vSpeed;
}

void Player::setvSpeed(int speed) {
	vSpeed = speed;
}

int Player::getDirection() const {
	return direction;
}

void Player::setDirection(int direction) {
	this->direction = direction;
}

int Player::getCounter() const {
	return counter;
}

void Player::setCounter(int counter) {
	this->counter = counter;
}
