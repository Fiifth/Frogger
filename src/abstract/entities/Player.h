/*
 * Player.h
 *
 *  Created on: 22 Feb 2016
 *      Author: Kwinten
 */

#ifndef ABSTRACT_ENTITIES_PLAYER_H_
#define ABSTRACT_ENTITIES_PLAYER_H_
#include <abstract/entities/Player.h>
#include <abstract/entities/Projectile.h>
#include <abstract/Entity.h>
#include <abstract/Row.h>
#include <abstract/Window.h>
#include <abstract/entities/Props.h>
#include <chrono>
#include <string>
#include <list>
#include <vector>

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
			int getLife() const;
			void addLife(int life);
			int getProjectiles() const;
			void addProjectiles(int projectiles);
			int getScore() const;
			void addScore(int score);
			void hit();
			void resetPosition();
			bool takeAction(std::string key);
			int getRemainingTime();
			void resetRemainingTime();
			void decreaseTime();
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
			struct drawMoveRemove
			{
					bool operator()(Props* prop);
			};

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
