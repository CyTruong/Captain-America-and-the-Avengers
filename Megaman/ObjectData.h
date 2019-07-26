#pragma once
#include "SpriteData.h"
class ObjectData : public SpriteData
{
public:
	ObjectData() {
		appearDir = Direction::createRight();
		this->vx = 0;
		this->vy = 0;
	};
	float playerX;
	float playerY;
	std::string objectName;
	bool isPlayerCollisionable;
	bool isEnemyCollisionable;
	int HP;
	CollisionRectF collisionRect;
	Direction appearDir;
};

