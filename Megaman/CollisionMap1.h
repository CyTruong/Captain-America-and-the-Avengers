#pragma once
#include"CollisionRect.h"
class collisionMap1
{
public:
	std::vector < CollisionRectF > getColRectF()
	{
		return	collisionRectFs;
	};
	collisionMap1();
	~collisionMap1();

private:
	std::vector < CollisionRectF > collisionRectFs;
};

collisionMap1::collisionMap1()

{
	CollisionRectF col;
	RectI r;
	r.x = 0;
	r.y = 27 * 16;
	r.width = 16 * 128;
	r.height = 16;
	col.rect = r;
	col.type = "ground";
	collisionRectFs.push_back(col);

	r.x = 0;
	r.y = 0;
	r.width = 16;
	r.height = 16 * 30;
	col.rect = r;
	col.type = "wall";
	collisionRectFs.push_back(col);


	/*r.x = 3 * 16;
	r.y = 16 * 25;
	r.width = 16 * 3;
	r.height = 16;
	col.rect = r;
	col.type = "ground";
	collisionRectFs.push_back(col);*/

	

	// chan cuoi wall 
	/*r.x = 8*16;
	r.y = 0;
	r.width = 16;
	r.height = 16 * 30;
	col.rect = r;
	col.type = "wall";
	collisionRectFs.push_back(col);*/



}


collisionMap1::~collisionMap1()
{ 
	collisionRectFs.clear(); 

   
}