#include "DoubleRocketData.h"

DoubleRocketData::DoubleRocketData(std::vector<BulletSprite*>& bullet)
	:EnemyData(bullet)
{

	this->botName = "DoubleRocket";
	this->isHittable = true;
	this->isDesTroyed = false;
	this->isThrougable = false;
	this->bulletsVector = bullet;
}

DoubleRocketData::DoubleRocketData()
{
	this->botName = "SingleGun";
	this->isHittable = true;
	this->isDesTroyed = false;
	this->isThrougable = false;
	this->bulletsVector = vector<BulletSprite*>();
}

DoubleRocketData::~DoubleRocketData()
{
}
