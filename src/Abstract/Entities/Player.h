/*
 * Frog.h
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */

#ifndef FROG_H_
#define FROG_H_
#include "Window.h"
#include "Entity.h"
#include "Row.h"
#include <ratio>
#include <chrono>
#include <string>
#include <iostream>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include "Projectile.h"
#include <list>


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
	void hit();
	void resetPosition();
	void setStartPosition(int startX,int startY);
	bool takeAction(std::string key);
	int getRemainingTime();
	void setRemainingTime(int remainingTime);
	void resetRemainingTime();
	void decreaseTime();
	void addHighScore(int score);
	const vector<int>& getHighScore() const;
	bool myfunction (int i,int j) { return (i>j); }

	bool isDead() const;
	void setDead(bool dead);
	bool timeToMove();
	void setDifferentControls();
	std::list<Projectile*>& getProjectileList();

private:
	int vSpeed;
	int hSpeed;
	int counter=0;
	int score=0,life=3,projectiles=3;
	int startX,startY;
	int totalTime;
	int remainingTime;
	bool dead=false;
	int divider=0;
	int dividerCounter=0;
	std::chrono::high_resolution_clock::time_point previousTime=std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::time_point currentTime=std::chrono::high_resolution_clock::now();
	float correctTime=float(totalTime);
	vector <int>highScore={0,0,0,0};
	string keyUp="Up",keyDown="Down",keyLeft="Left",keyRight="Right",fire="Right Ctrl";
	void collision(Player* player);
protected:
	std::list<Projectile*>projectileList;
};


#endif /* FROG_H_ */
