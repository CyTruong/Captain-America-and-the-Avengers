#pragma once
#include "EnemyData.h"


class WizardData :
	public EnemyData
{
public:
	enum SingleGunArrindex
	{
		STAND,
		RUNNING,
		FLY,
		STANDSHOOT,
		FLYSHOOT,
		DIE,
		COUNT
	};
public:
	WizardData(std::vector<BulletSprite*>& bullet);
	WizardData();


	~WizardData();
};

