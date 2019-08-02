#include "RocketSoldierData.h"




RocketSoldierData::RocketSoldierData(std::vector<BulletSprite*>& bullet)
	:EnemyData(bullet)
{

	this->botName = "RocketSoldier";
	this->isHittable = true;
	this->isDesTroyed = false;
	this->isThrougable = false;
	this->bulletsVector = bullet;
	this->HP = 1;

}

RocketSoldierData::RocketSoldierData()
{
	this->botName = "RocketSoldier";
	this->isHittable = true;
	this->isDesTroyed = false;
	this->isThrougable = false;
	this->bulletsVector = vector<BulletSprite*>();
	this->HP = 1;

}

RocketSoldierData::~RocketSoldierData()
{
}