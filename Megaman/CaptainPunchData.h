#pragma once
#include "SpriteData.h"

class CaptainPunchData : public SpriteData
{
public:
	RectF* bodyRects;
	enum SpriteArrayIndex
	{
		ACTIVE,
		NONE,
		COUNT
	};
public:
	virtual void setiCurrentArray(int index)
	{
		iCurrentArr = index;
		body = bodyRects[index];
	}

};