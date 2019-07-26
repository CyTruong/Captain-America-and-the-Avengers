#include "SingleGunData.h"




SingleGunData::SingleGunData(std::vector<BulletSprite*>& bullet)
	:EnemyData(bullet)
{

	this->botName = "SingleGun";
	this->isHittable = true;
	this->isDesTroyed = false;
	this->isThrougable = false;
	this->bulletsVector = bullet;

}

SingleGunData::SingleGunData()
{
	this->botName = "SingleGun";
	this->isHittable = true;
	this->isDesTroyed = false;
	this->isThrougable = false;
	this->bulletsVector = vector<BulletSprite*>();

}

SingleGunData::~SingleGunData()
{
}
