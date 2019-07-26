#include "BoxData.h"

BoxData::BoxData(std::vector<BulletSprite*>& bullet)
	:EnemyData(bullet)
{

	this->botName = "Box";
	this->isHittable = true;
	this->isDesTroyed = false;
	this->isThrougable = false;
	this->bulletsVector = bullet;
}

BoxData::BoxData()
{
	this->botName = "Box";
	this->isHittable = true;
	this->isDesTroyed = false;
	this->isThrougable = false;
	this->bulletsVector = vector<BulletSprite*>();
}

BoxData::~BoxData()
{
}
