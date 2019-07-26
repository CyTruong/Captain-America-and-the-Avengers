#pragma once
#include "EnemySprite.h"
#include "ObjectSprite.h"

class EnemyCreator
{
private:
	static EnemyCreator* instance;
	EnemyCreator();
	void addAppearDirection(std::string name, Direction dir);
public:
	static EnemyCreator* getInstance();
	EnemySprite * createEnemySprite(std::string enermyName, int respawnX, int respawnY, std::vector < BulletSprite* >& bulletSprites);
	ObjectSprite* createObjectSprite(std::string name, int respawnX, int respawnY);
	Direction getAppearDir(std::string name);
	std::map < std::string, Direction > appearDirections;
	~EnemyCreator();
};

