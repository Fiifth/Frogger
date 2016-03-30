/*
 * Frog.h
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */
#include "Window.h"
#include "Entity.h"
#include "Row.h"
#ifndef FROG_H_
#define FROG_H_

using namespace std;

class Player :public Entity{
public:
	Player();
	virtual ~Player();
	virtual void draw()=0;
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void followRow(Row* row);
	int gethSpeed() const;
	void sethSpeed(int speed);
	int getvSpeed() const;
	void setvSpeed(int speed);
	int getDirection() const;
	void setDirection(int direction);
	int getCounter() const;
	void setCounter(int counter);
	int getLife() const;
	void setLife(int life);
	void addLife(int life);
	int getProjectiles() const;
	void setProjectiles(int projectiles);
	void addProjectiles(int projectiles);
	int getScore() const;
	void setScore(int score);
	void addScore(int score);

private:
	int vSpeed;
	int hSpeed;
	int direction;//1=up,2=right,3=down,4=left;
	int counter=0;
	int score=0,life=3,projectiles=0;
};


#endif /* FROG_H_ */
