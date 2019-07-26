#pragma once
#pragma once
#include "EnemyState.h"
class ZuliaDeadState :
	public EnemyState
{
public:
	ZuliaDeadState(EnemyData *pData);
	void onUpdate();
	~ZuliaDeadState();
};

