#pragma once
#include "SpriteData.h"

class DoubleRocketNormalBulletData : public SpriteData {
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