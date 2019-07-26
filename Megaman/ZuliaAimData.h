#pragma once
#include "SpriteData.h"

class ZuliaAimData : public SpriteData
{
public:
	enum SpriteArrayIndex
	{
		FLY,
		TARGETING,
		COUNT
	};

public:
	virtual void setiCurrentArray(int index)
	{
		iCurrentArr = index;
	}

};