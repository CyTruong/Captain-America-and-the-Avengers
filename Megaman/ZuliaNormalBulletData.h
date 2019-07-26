#pragma once
#include "SpriteData.h"

class ZuliaNormalBulletData : public SpriteData
{
public:
	enum SpriteArrayIndex
	{
		FLY,
		STAND,
		DESTROY,
		COUNT
	};

public:
	virtual void setiCurrentArray(int index)
	{
		iCurrentArr = index;
	}

};