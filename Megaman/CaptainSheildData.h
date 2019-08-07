#pragma once
#include "SpriteData.h"

class CaptainSheildData : public SpriteData
{
public:
	RectF* bodyRects;
	enum SpriteArrayIndex
	{	
		HOLDRIGHT,
		HOLDLEFT,
		FLY,
		DESTROY,
		HOLDAIR,
		COUNT
	};
public:
	virtual void setiCurrentArray(int index)
	{
		iCurrentArr = index;
		body = bodyRects[index];
	}

};