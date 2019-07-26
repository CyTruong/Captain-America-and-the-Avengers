#pragma once
#include "EnemyState.h"
class RocketFlyDeadState :
	public EnemyState
{
public:
	RocketFlyDeadState(EnemyData *pData);
	void onUpdate();
	~RocketFlyDeadState();
};

