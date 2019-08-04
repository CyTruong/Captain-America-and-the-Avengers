#include "BlueSoldierData.h"




BlueSoldierData::BlueSoldierData(std::vector<BulletSprite*>& bullet)
	:EnemyData(bullet)
{

	this->botName = "BlueSoldier";
	this->isHittable = true;
	this->isDesTroyed = false;
	this->isThrougable = false;
	this->bulletsVector = bullet;

}

BlueSoldierData::BlueSoldierData()
{
	this->botName = "BlueSoldier";
	this->isHittable = true;
	this->isDesTroyed = false;
	this->isThrougable = false;
	this->bulletsVector = vector<BulletSprite*>();

}

BlueSoldierData::~BlueSoldierData()
{
}
