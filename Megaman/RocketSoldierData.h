#pragma once
#include "EnemyData.h"

#define BlueSoldier_TURN_RANGE 20
#define BlueSoldier_FIRE_RANGE 80

class RocketSoldierData :
	public EnemyData
{
public:
	enum RocketSoldierArrindex
	{
		SIT,// sit and sitshoot 
		SHOOT,// shoot and Stand 
		RUN,
		DIE,
		COUNT
	};
public:
	RocketSoldierData(std::vector<BulletSprite*>& bullet);
	RocketSoldierData();


	~RocketSoldierData();
};