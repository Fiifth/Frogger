/*
 * Entity.h
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#ifndef ABSTRACT_ENTITY_H_
#define ABSTRACT_ENTITY_H_

class Entity {
public:
	Entity();
	virtual ~Entity();
	void move(int deltaX,int deltaY,bool leaveScreen);
	void setSize(int wNew , int hNew);
	void setLocation(int xNew, int yNew);
	void setScreenSize(int width,int height);
	bool inframe();
	int getH() const;
	int getW() const;
	int getX() const;
	int getY() const;
	int getHeight() const;
	int getWidth() const;
	int getSpeed() const;
	void setSpeed(int speed);
protected:
	int x,y,w,h,speed;
	int screenWidth,screenHeight;


};

#endif /* ABSTRACT_ENTITY_H_ */
