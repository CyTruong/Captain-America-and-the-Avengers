#pragma once
#include "SpriteData.h"

class CaptainSheildData : public SpriteData
{
public:
	RectF* bodyRects;
	enum SpriteArrayIndex
	{	
		HOLD,
		FLY,
		DESTROY,
		COUNT
	};
public:
	virtual void setiCurrentArray(int index)
	{
		iCurrentArr = index;
		body = bodyRects[index];
	}

};