#pragma once
#include "EnemySprite.h"
#include "ZuliaData.h"
class ZuliaSprite :
	public EnemySprite
{

public:
	ZuliaSprite(float x, float y,Direction dir, std::vector<BulletSprite*>& bullet);
	void setCollisionRect(CollisionRectF rect);
	void draw(Camera * cam) override;
	~ZuliaSprite();
};

