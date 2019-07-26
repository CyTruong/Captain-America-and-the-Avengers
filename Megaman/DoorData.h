#pragma once
#include "SpriteData.h"
#include"ObjectData.h"
class DoorData:public ObjectData
{
public:
	DoorData();
	~DoorData();

	enum DoorArrIndex
	{
	    PRESENT,
		OPEN,
		OPENED,
		CLOSE,
		COUNT

	};

private:

};

