#include "WizardData.h"




WizardData::WizardData(std::vector<BulletSprite*>& bullet)
	:EnemyData(bullet)
{

	this->botName = "Wizard";
	this->isHittable = true;
	this->isDesTroyed = false;
	this->isThrougable = false;
	this->bulletsVector = bullet;

}

WizardData::WizardData()
{
	this->botName = "Wizard";
	this->isHittable = true;
	this->isDesTroyed = false;
	this->isThrougable = false;
	this->bulletsVector = vector<BulletSprite*>();

}

WizardData::~WizardData()
{
}
