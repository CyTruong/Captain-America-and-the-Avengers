#pragma once
#include "SpriteData.h"

class MgmNormalBulletData : public SpriteData
{
public:
	RectF* bodyRects;
	enum SpriteArrayIndex
	{
		FLY,
		DESTROY,
		COUNT
	};
public :
	virtual void setiCurrentArray(int index)
	{
		iCurrentArr = index;
		body = bodyRects[index];
	}
	
};