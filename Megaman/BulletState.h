#pragma once
#include "SpriteState.h"
#include "SpriteData.h"
#include "MgmNormalBulletData.h"
#

class BulletState : public SpriteState 
{
protected:
	SpriteData *pData;
public:
	BulletState() {}
};