#pragma once
#include "SpriteData.h"

class ZuliaSpecialBulletData : public SpriteData
{
public:
	enum SpriteArrayIndex
	{
		FLY,
		DESTROY,
		COUNT
	};

public:
	virtual void setiCurrentArray(int index)
	{
		iCurrentArr = index;
	}

};