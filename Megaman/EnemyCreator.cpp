#include "EnemyCreator.h"
#include "SingleGunSprite.h"
#include "ElevatorSprite.h"
#include "ShurikanSprite.h"
#include "ZuliaSprite.h"
#include "DoubleRocketSprite.h"
#include "RocketFlySprite.h"
#include "WizardSprite.h"
#include "DoorSprite.h"

EnemyCreator* EnemyCreator::instance = nullptr;


EnemyCreator::EnemyCreator()
{ 


	addAppearDirection("SingleGun", Direction::createRight());
	addAppearDirection("Elevator", Direction::createRight());
	addAppearDirection("DoubleRocket", Direction::createRight());
	addAppearDirection("Shurikan", Direction::createRight());
	addAppearDirection("Zulia", Direction::createLeft());
	addAppearDirection("Wizard",Direction::createRight());
}

void EnemyCreator::addAppearDirection(std::string name, Direction dir)
{
	appearDirections[name] = dir;
}

EnemyCreator * EnemyCreator::getInstance()
{
	if (instance == nullptr)
	{
		instance = new EnemyCreator();
	}
	return instance;
}

EnemySprite * EnemyCreator::createEnemySprite(std::string enemyName, int respawnX, int respawnY, std::vector<BulletSprite*>& bulletSprites)
{
	if (enemyName == "SingleGun") {
		return new SingleGunSprite(respawnX, respawnY, getAppearDir(enemyName), true, bulletSprites);
	}
	if (enemyName == "DoubleRocket") {
		return new DoubleRocketSprite(respawnX, respawnY, getAppearDir(enemyName), true, bulletSprites);
	}
	if (enemyName == "Shurikan") {
		return new ShurikanSprite(respawnX, respawnY);
	}
	if (enemyName == "Zulia") {
		return new ZuliaSprite(respawnX, respawnY, getAppearDir(enemyName), bulletSprites);
	}
	if (enemyName=="RocketFly")
	{
		return new RocketFlySprite(respawnX, respawnY, getAppearDir(enemyName),true, bulletSprites);
	}
	if (enemyName=="Wizard")
	{
		return new WizardSprite(respawnX, respawnY, getAppearDir(enemyName), true, bulletSprites);
	}
}	

ObjectSprite * EnemyCreator::createObjectSprite(std::string name, int respawnX, int respawnY)
{
	if (name == "Elevator") {
		return new ElevatorSprite(respawnX, respawnY);
	}

	if (name == "Door") {
		return new DoorSprite (respawnX, respawnY);
	}
}

Direction EnemyCreator::getAppearDir(std::string name)
{
	std::map < std::string, Direction >::iterator it = appearDirections.find(name);
	if (it != appearDirections.end())
	{
		return it->second;
	}
	return Direction::createNone();
}


EnemyCreator::~EnemyCreator()
{
}
