#pragma once
#include "define.h"
class CamBound
{
public:
	CamBound(int Ya, int Yb, int Xa, int Xb)
	{
		ya = Ya * TILE_SIZE;
		yb = Yb * TILE_SIZE;
		xa = Xa * TILE_SIZE;
		xb = Xb * TILE_SIZE;
	}
	
	void create(int Ya, int Yb, int Xa, int Xb)
	{
		ya = Ya * TILE_SIZE;
		yb = Yb * TILE_SIZE;
		xa = Xa * TILE_SIZE;
		xb = Xb * TILE_SIZE;
	}


	int ya, yb, xa, xb; 
private:
	// (a,b) la gioi han theo truc y,x ; 

	
};
