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
#include <chrono>
#include <string>
#include "Projectile.h"
#include <list>

namespace frogger
{

	class Player: public frogger::Entity
	{
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
			void setStartPosition(int startX, int startY);
			bool takeAction(std::string key);
			int getRemainingTime();
			void setRemainingTime(int remainingTime);
			void resetRemainingTime();
			void decreaseTime();
			void disableCounter();
			bool isDead() const;
			void setDead(bool dead);
			bool timeToMove();
			void setDifferentControls(char set);
			std::list<Projectile*>* getProjectileList();
			void collision(Player* player);
			void followScreen(int offset);
			void initPlayer(int hSpeed,int vSpeed,int w, int h, int x,int y, int Xs, int Ys,int* screenW,int* screenH);
			void setParameters(int life, int totalTime, bool counterEnabled, int scorePerStep, int projectiles);
			void setProjAniList(std::vector<frogger::Animator>* projAni);

		private:
			int vSpeed=0;
			int hSpeed=0;
			int counter = 0;
			int score = 0;
			int life = 0;
			int projectiles = 0;
			int startX=0;
			int startY=0;
			int totalTime=50;
			int remainingTime=50;
			bool counterEnabled = true;
			bool dead = false;
			int scorePerStep = 10;
			float correctTime = float(totalTime);

			std::chrono::high_resolution_clock::time_point previousTime =	std::chrono::high_resolution_clock::now();
			std::chrono::high_resolution_clock::time_point currentTime =	std::chrono::high_resolution_clock::now();
			std::string keyUp = "Up";
			std::string keyDown = "Down";
			std::string keyLeft = "Left";
			std::string keyRight = "Right";
			std::string fire = "Right Ctrl";

		protected:
			std::list<Projectile*> projectileList;
			std::vector<frogger::Animator>* projAni=nullptr;
			bool moved = false;
	};
}
#endif /* FROG_H_ */
