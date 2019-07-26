#include "ElevatorData.h"



ElevatorData::ElevatorData()
{
	this->objectName = "elevator";
	this->isDesTroyed = false;
	this->isHittable = false;
	this->isPlayerCollisionable = true;
	this->isEnemyCollisionable = true;
}


ElevatorData::~ElevatorData()
{
}
