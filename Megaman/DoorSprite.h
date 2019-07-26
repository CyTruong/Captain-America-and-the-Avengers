#pragma once
#include "ObjectSprite.h"
class DoorSprite:public ObjectSprite

{
public:
	DoorSprite(float, float );
	void onUpdate()override ;
	//void onCollision(CollisionRectF cRect) ; 
	~DoorSprite();

private:

};
