#pragma once
#include "SpriteData.h"

class SingelGunNormalBulletData : public SpriteData {
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