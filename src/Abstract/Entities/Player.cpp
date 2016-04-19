/*
 * Frog.cpp
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */

#include "Player.h"
#include "Factory.h"
using namespace std;


Player::Player():vSpeed(0),hSpeed(0),startX(0),startY(0),totalTime(50),remainingTime(totalTime)
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

void Player::followRow(Row* row)
{
	if(divider!=row->getDivider())
	{
		divider=row->getDivider();
		dividerCounter=0;
	}

	if(timeToMove())
	{
		if(!row->isDirLeft())
			move(row->getSpeed(),0,false);
		else
			move(-row->getSpeed(),0,false);
	}

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

void Player::hit()
{
	resetPosition();
	if (life==0)
	{
		addHighScore(score);
		setDead(true);
	}
	else
	{
		addLife(-1);
		addScore(-10);

	}
}

void Player::resetPosition() {
	x=startX;
	y=startY;
	direction=1;
	resetRemainingTime();
}

void Player::setStartPosition(int startX, int startY) {
	this->startX=startX;
	this->startY=startY;
}

bool Player::takeAction(std::string key)
{
	if (key=="")
	{
		return false;
	}
	if (key==keyDown)
	{
		moveDown();
		addScore(-10);
	}
	else if (key==keyUp)
	{
		moveUp();
		addScore(10);
	}
	else if (key==keyLeft)
		moveLeft();
	else if (key==keyRight)
		moveRight();
	else if (key==fire&&getProjectiles()>0)
	{
		addProjectiles(-1);
		projectileList.push_back(F->createProjectile(this,5,0));

		//return true;
	}
return false;
}

int Player::getRemainingTime()
{
	decreaseTime();
	return remainingTime;
}

void Player::setRemainingTime(int remainingTime) {
	this->remainingTime = remainingTime;
}

void Player::resetRemainingTime() {

	previousTime=std::chrono::high_resolution_clock::now();
}

void Player::decreaseTime() {
		currentTime=std::chrono::high_resolution_clock::now();
		remainingTime=totalTime-(std::chrono::duration_cast<std::chrono::seconds>(currentTime-previousTime).count());
}

void Player::addHighScore(int score)
{
	highScore.pop_back();
	highScore.push_back(score);
	std::sort(highScore.begin(),highScore.end());
	std::reverse(highScore.begin(),highScore.end());
	highScore.pop_back();
	highScore.push_back(score);
}

const vector<int>& Player::getHighScore() const {
	return highScore;
}

bool Player::isDead() const {
	return dead;
}

void Player::setDead(bool dead)
{
	if (!dead)
	{
		setScore(0);
		setLife(3);
		projectiles=3;
		resetPosition();
	}
	this->dead = dead;
}
bool Player::timeToMove()
{
	if(dividerCounter==0)
	{

		dividerCounter=divider;
		return true;
	}
	else
	{
		dividerCounter=dividerCounter-1;
		return false;
	}
}

void Player::setDifferentControls()
{
	keyUp="Z";
	keyDown="S";
	keyLeft="Q";
	keyRight="D";
	fire="Space";
}
