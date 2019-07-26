#pragma once
#include "ObjectSprite.h"

class HPSprite :
	public ObjectSprite
{
private:
	//HPBarSprite* hpBar;
	int index;
public:
	HPSprite();
	void onUpdate();
	ObjectData* getobjData() {
		return this->pData;
	}
	~HPSprite();
};

