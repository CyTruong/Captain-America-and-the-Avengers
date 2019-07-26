#pragma once
#include "EnemyData.h"
class ShurikanData :
	public EnemyData
{
public:
	enum SurikenAniIndex
	{
		START,
		SPIN,	//xoay quanh truc x
		WALLSPIN,
		BOUNCE_START, //xoay quang trục z
		BOUNCE_RUN,
		DIE,
		ANI_COUNT
		
	};
	
	enum SurikenMechIndex
	{
		RUNNING_ATACK,
		WALL_CLIMP,
		POUNDING,
		MECH_COUNT
	};

public:
	ShurikanData();
	~ShurikanData();
};

