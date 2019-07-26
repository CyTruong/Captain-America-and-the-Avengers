#pragma once
#include "EnemyState.h"
class ZuliaNormalFlyState :
	public EnemyState
{
private:
	RectF Range;
	// a điểm bắt đầu , b điểm kết thúc
	// y = Ax+ B
	float xa, xb, ya, yb;
	float A, B;
	float speed;
	int nextMech;
	float getYfromX(float Y);
	void doMech();
public:
	ZuliaNormalFlyState(EnemyData *pData,float desX,float desY,RectF Range,int nextMech = 0);
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void onDead() override;
	~ZuliaNormalFlyState();
};

