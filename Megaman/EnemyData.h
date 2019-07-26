#pragma once

#include "SpriteData.h"
#include "BulletSprite.h"
#include "UI.h"
#include <vector>

using namespace std;

class EnemyData : public SpriteData
{

public :
	float Megaman_X;
	float Megaman_Y;
	
	bool isPlayerDead;
	
	std::string botName;
	int HP;
	bool isThrougable;
	std::vector < BulletSprite* > bulletsVector;

	int score;
	Direction appearDir;
	int isTargetting; 
	bool isShooter;
	float respawnX;
	float respawnY;

public:
	

	EnemyData(std::vector < BulletSprite* >& bulletsVector)
		:
		bulletsVector(bulletsVector)
	{
		isDesTroyed = false;
		isHittable = true;
		appearDir = Direction::createRight();
		isDead = false;
		score = 0;
	}

	EnemyData()
	{
		bulletsVector = std::vector < BulletSprite* >();
		isDesTroyed = false;
		isHittable = true;
		appearDir = Direction::createRight();
		isDead = false;
		score = 0;
	}

	//virtual int getPlayerIndexToExcute()
	//{
	//	// return 0 : both are dead.
	//	// return 1 : player 1
	//	// return 2 : player 2
	//	float centerY = (y - ppTextureArrays[iCurrentArr]->getHeight() * ppTextureArrays[iCurrentArr]->getAnchorPoint().y) + ppTextureArrays[iCurrentArr]->getHeight() / 2;
	//	float centerX = (x - ppTextureArrays[iCurrentArr]->getWidth() * ppTextureArrays[iCurrentArr]->getAnchorPoint().x) + ppTextureArrays[iCurrentArr]->getWidth() / 2;

	//	if (UIComponents::getInstance()->getNumberPlayer() == 1)
	//	{
	//		if (isPlayerDead)
	//		{
	//			return 0;
	//		}
	//		else
	//		{
	//			return 1;
	//		}
	//	}

	//	if (isPlayerDead && isPlayer2Dead)
	//	{
	//		return 0;
	//	}
	//	else if (!isPlayerDead && isPlayer2Dead)
	//	{
	//		return 1;
	//	}
	//	else if (isPlayerDead && !isPlayer2Dead)
	//	{
	//		return 2;
	//	}
	//	else if (!isPlayerDead && !isPlayer2Dead)
	//	{
	//		float lengthsq1 = pow((playerX - centerX), 2) + pow((playerY - centerY), 2);
	//		float lengthsp2 = pow((player2X - centerX), 2) + pow((player2Y - centerY), 2);
	//		if (lengthsq1 < lengthsp2)
	//		{
	//			return 1;
	//		}
	//		else return 2;
	//	}
	//}
	//
};