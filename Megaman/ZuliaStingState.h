#pragma once
#include "EnemyState.h"
class ZuliaStingState :
	public EnemyState
{
private:
	RectF Range;
	// a điểm bắt đầu , b điểm kết thúc
	// y = Ax+ B
	float xa, xb, ya, yb;
	float A, B;
	float speed;
	int waiiting2stingcount;
	float getYfromX(float Y);
public:
	ZuliaStingState(EnemyData * pdata,RectF Range);
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void onDead() override;
	~ZuliaStingState();
};

