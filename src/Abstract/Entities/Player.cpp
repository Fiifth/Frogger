/*
 * Frog.cpp
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */

#include "Player.h"
#include <iostream>

using namespace std;


Player::Player():vSpeed(0),hSpeed(0),direction(1)
{}

Player::~Player() {
}
//int direction=0;//1=up,2=right,3=down,4=left;
void Player::moveUp()
{
	move(0,(-vSpeed),false);
	direction=1;
	counter=10;
}

void Player::moveDown()
{
	move(0,vSpeed,false);
	direction=3;
	counter=10;
}

void Player::moveRight()
{
	move(hSpeed/2,0,false);
	direction=2;
	counter=10;
}

void Player::moveLeft()
{
	move(-(hSpeed/2),0,false);
	direction=4;
	counter=10;
}

void Player::followRow(Row* row) {
	if(!row->isDirLeft())
			move(row->getSpeed(),0,false);
		else
			move(-row->getSpeed(),0,false);
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

int Player::getLife() const {
	return life;
}

void Player::setLife(int life) {
	this->life = life;
}

int Player::getProjectiles() const {
	return projectiles;
}

void Player::setProjectiles(int projectiles) {
	this->projectiles = projectiles;
}

int Player::getScore() const {
	return score;
}

void Player::setScore(int score) {
	this->score = score;
}

void Player::addLife(int life) {
	this->life=this->life+life;
}

void Player::addProjectiles(int projectiles) {
	this->projectiles=this->projectiles+projectiles;
}

void Player::addScore(int score)
{
	this ->score=this->score+score;
}
