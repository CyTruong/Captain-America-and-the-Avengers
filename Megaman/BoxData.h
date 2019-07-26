#pragma once
#include "EnemyData.h"


class BoxData :
	public EnemyData
{
public:
	enum RocketFlyArrindex
	{
		PRESENT,
		DIE,
		COUNT
	};
public:
	BoxData(std::vector<BulletSprite*>& bullet);
	BoxData();


	~BoxData();
};

