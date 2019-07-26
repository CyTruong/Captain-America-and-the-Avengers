#pragma once
#include "EnemyData.h"

#define SINGLEGUN_TURN_RANGE 20
#define SINGLEGUN_FIRE_RANGE 80

class SingleGunData :
	public EnemyData
{
public:
	enum SingleGunArrindex
	{
		STAND,
		JUMP,
		FIRE,
		DIE,
		COUNT
	};
public:
	SingleGunData(std::vector<BulletSprite*>& bullet );
	SingleGunData();


	~SingleGunData();
};

