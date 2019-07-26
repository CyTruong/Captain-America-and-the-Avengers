#pragma once
#pragma once
#include "EnemyState.h"
class ShurikanDeadState :
	public EnemyState
{
public:
	ShurikanDeadState(EnemyData *pData);
	void onUpdate();
	~ShurikanDeadState();
};

