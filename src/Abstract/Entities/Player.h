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
			void setParameters(int life, int totalTime, bool counterEnabled,
					int scorePerStep, int projectiles);
			void setProjAniList(std::vector<frogger::Animator>* projAni);

		private:
			int vSpeed;
			int hSpeed;
			int counter = 0;
			int score = 0, life = 3, projectiles = 3;
			int startX, startY;
			int totalTime;
			int remainingTime;
			bool counterEnabled = true;
			bool dead = false;
			int scorePerStep = 10;

			std::chrono::high_resolution_clock::time_point previousTime =
					std::chrono::high_resolution_clock::now();
			std::chrono::high_resolution_clock::time_point currentTime =
					std::chrono::high_resolution_clock::now();
			float correctTime = float(totalTime);
			std::string keyUp = "Up", keyDown = "Down", keyLeft = "Left",
					keyRight = "Right", fire = "Right Ctrl";

		protected:
			std::list<Projectile*> projectileList;
			std::vector<frogger::Animator>* projAni=nullptr;
			bool moved = false;
	};
}
#endif /* FROG_H_ */
