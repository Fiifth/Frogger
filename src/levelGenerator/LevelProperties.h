/*
 * LevelProperties.h
 *
 *  Created on: 23-apr.-2016
 *      Author: msn-w
 */

#ifndef LEVELGENERATOR_LEVELPROPERTIES_H_
#define LEVELGENERATOR_LEVELPROPERTIES_H_
#include "RowProp.h"
#include <vector>
namespace frogger
{
class LevelProperties
{
public:
	LevelProperties(char mode);
	virtual ~LevelProperties();
	void level1();
	RowProp* getFirstRow();
	RowProp* getLastRow();
	RowProp* getMiddleRow() ;
	RowProp* getSeg1();
	RowProp* getSeg2();
	RowProp* getSeg3();
	RowProp* getSeg4();
	std::vector<int> getVec(int a,int b);
	char getMode() const;
	void setMode(char mode);
	RowProp* getRandomRow();
	void levelUp();

private:
	RowProp* firstRow=nullptr;
	RowProp* lastRow=nullptr;
	RowProp* middleRow=nullptr;
	RowProp* seg1=nullptr;
	RowProp* seg2=nullptr;
	RowProp* seg3=nullptr;
	RowProp* seg4=nullptr;
	char mode;
	int level=1;
};
}


#endif /* LEVELGENERATOR_LEVELPROPERTIES_H_ */
