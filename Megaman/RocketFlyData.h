#pragma once
#include "EnemyData.h"


class RocketFlyData :
	public EnemyData
{
public:
	enum RocketFlyArrindex
	{
		FIRE, 
		DIE,
		COUNT
	};
public:
	RocketFlyData(std::vector<BulletSprite*>& bullet);
	RocketFlyData();


	~RocketFlyData();
};

