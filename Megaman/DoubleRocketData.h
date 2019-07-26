#pragma once
#include "EnemyData.h"


class DoubleRocketData :
	public EnemyData
{
public:
	enum DoubleGunArrindex
	{
		FIRE_TOP,
		FIRE_BOT,
		DIE,
		COUNT
	};
public:
	DoubleRocketData(std::vector<BulletSprite*>& bullet);
	DoubleRocketData();


	~DoubleRocketData();
};

