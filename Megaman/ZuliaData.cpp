#include "ZuliaData.h"



ZuliaData::ZuliaData(std::vector<BulletSprite*>& bullet)
	:EnemyData(bullet)
{
	this->botName = "Zulia";
	this->isHittable = true;
	this->isDesTroyed = false;
	this->isThrougable = false;
	this->bulletsVector = bullet;
}

ZuliaData::ZuliaData()
{
	this->botName = "Zulia";
	this->isHittable = true;
	this->isDesTroyed = false;
	this->isThrougable = false;
	this->bulletsVector = vector<BulletSprite*>();
}


ZuliaData::~ZuliaData()
{
}
