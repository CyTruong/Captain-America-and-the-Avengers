#pragma once
#include "ObjectSprite.h"
#include "HPSprite.h"


class HPBarSprite :
	public ObjectSprite
{
private:
	float posX, posY;
	vector<HPSprite*> hpSprites;
public:
	HPBarSprite(Camera * & cam,float posX, float posY);
	void onUpdate();
	void draw(Camera *cam) override;
	~HPBarSprite();
};

