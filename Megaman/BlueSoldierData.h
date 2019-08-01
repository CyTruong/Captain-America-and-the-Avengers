#pragma once
#include "EnemyData.h"

#define BlueSoldier_TURN_RANGE 20
#define BlueSoldier_FIRE_RANGE 80

class BlueSoldierData :
	public EnemyData
{
public:
	enum BlueSoldierArrindex
	{
		SIT,// sit and sitshoot 
		SHOOT,// shoot and Stand 
		RUN,
		DIE,
		COUNT
	};
public:
	BlueSoldierData(std::vector<BulletSprite*>& bullet);
	BlueSoldierData();


	~BlueSoldierData();
};

