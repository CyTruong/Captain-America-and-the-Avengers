#include "RocketFlyData.h"

RocketFlyData::RocketFlyData(std::vector<BulletSprite*>& bullet)
	:EnemyData(bullet)
{

	this->botName = "RocKetFly";
	this->isHittable = true;
	this->isDesTroyed = false;
	this->isThrougable = false;
	this->bulletsVector = bullet;
}

RocketFlyData::RocketFlyData()
{
	this->botName = "SingleGun";
	this->isHittable = true;
	this->isDesTroyed = false;
	this->isThrougable = false;
	this->bulletsVector = vector<BulletSprite*>();
}

RocketFlyData::~RocketFlyData()
{
}
