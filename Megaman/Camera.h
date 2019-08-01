#pragma once
#include "ViewPort.h"
#include "iostream"
#include "Direction.h"
#include "CamBound.h"
#include "Map1CamBounds.h"
// sai so 
#define ss 0 
class CamPos
{
public:
	// a b  c 
	// x y1 y2
	// y x1 x2 
	float a, b, c;

	// x , y, xy ; 
	int d;
	CamPos() {};

	CamPos(float A, float  B, float C, int D) {

		a = A * TILE_SIZE;
		b = B * TILE_SIZE;
		c = C * TILE_SIZE;
		d = D;

	}


private:

};


class Camera
{
private:
	ViewPort* viewPort;
	RectF mapRect;
	float x;
	float y;
	float vx;
	float vy;
	RectF cameraTranslatePoint;
	Direction moveDir;

	int NumberOfcamPos;
	int f;
	int isGate1;
	vector<CamBound> camBounds;
	int numberOfBound; 


public:
    

	Camera(ViewPort* viewPort, float x, float y, RectF rect, RectF cameraTranslatePoint, vector<CamBound > cbounds, int nBounds )
	{
		camBounds = cbounds; 
		numberOfBound = cbounds.size();


		this->viewPort = viewPort;
		
		this->x = x;
		this->y = y;
	

		moveDir = Direction::createRight();
		vx = vy = 5;

	}
	void setPosX(float x, bool c)
	{
		//int a = x-VIEWPORT_SIZE/2;
		int a = x ;

		if (c == 1)
		{
			return;

		}
		if (this->x < a && moveDir.isRight())
		{
			//

			this->x = a;
			this->x = max(this->x, mapRect.x);
			this->x = min(this->x, mapRect.width + mapRect.x - viewPort->getWidth());

			//	this->x = max(this->x, mapRect.x);
				//this->x = min(this->x, mapRect.width + mapRect.x - viewPort->getWidth());
		}


		else if (this->x > x - (float)viewPort->getWidth() / 2.0f && moveDir.isLeft())
		{
			this->x = a;
			this->x = max(this->x, mapRect.x);
			this->x = min(this->x, mapRect.width + mapRect.x - viewPort->getWidth());



		}



	}
	void setPosY(float y, bool c)
	{

		//int b = y - VIEWPORT_SIZE / 2;
		int b = y;
		if (this->y > b && moveDir.isUp())
		{
			this->y = b;
			this->y = max(this->y, mapRect.y);
			this->y = min(this->y, mapRect.height + mapRect.y - viewPort->getHeight());
		}

		else if (this->y < b && moveDir.isDown())
		{
			this->y = b;
			this->y = max(this->y, mapRect.y);
			this->y = min(this->y, mapRect.height + mapRect.y - viewPort->getHeight());

		}
	}

	void setPosition(float x, float y)
	{
		if (this->x < x - (float)viewPort->getWidth() / 2.0f && moveDir.isRight())
		{
			this->x = x - (float)viewPort->getWidth() / 2.0f;
			this->x = max(this->x, mapRect.x);
			this->x = min(this->x, mapRect.width + mapRect.x - viewPort->getWidth());
		}


		else if (this->x > x - (float)viewPort->getWidth() / 2.0f && moveDir.isLeft())
		{
			this->x = x - (float)viewPort->getWidth() / 2.0f;
			this->x = max(this->x, mapRect.x);
			this->x = min(this->x, mapRect.width + mapRect.x - viewPort->getWidth());



		}


		if (this->y > y - (float)viewPort->getHeight() / 2.0f && moveDir.isUp())
		{
			this->y = y - (float)viewPort->getHeight() / 2.0f;
			//this->y = max(this->y, mapRect.y);
			//this->y = min(this->y, mapRect.height + mapRect.y - viewPort->getHeight());
		}

		else if (this->y < y - (float)viewPort->getHeight() / 2.0f && moveDir.isDown())
		{
			this->y = y - (float)viewPort->getHeight() / 2.0f;
			//this->y = max(this->y, mapRect.y);
			//this->y = min(this->y, mapRect.height + mapRect.y - viewPort->getHeight());

		}
	}



	int getWidth()
	{
		return viewPort->getWidth();
	}
	int getHeight()
	{
		return viewPort->getHeight();
	}
	float getX()
	{
		return x;
	}
	float getY()
	{
		return y;
	}
	RectF getRect()
	{
		return RectF(x, y, getWidth(), getHeight());
	}

	void update(float playerX, float playerY, Direction d, int isCamStop, int id)
	{
		int s= viewPort->getWidth();

		// de xem da thuc hien o bound chua 
		int flag = 0; 
		for (int  i = 0; i <numberOfBound; i++)
		{
			 
			// truc x 
			if (playerX>camBounds[i].xa && playerX < camBounds[i].xb + s )
			{ 
				if (playerX > camBounds[i].xa+s/2 && playerX < camBounds[i].xb + s/2)
				{
					this->x = playerX - s / 2 - vx; 
				}
 			
				if (playerX <= camBounds[i].xa +s/2)
				{
					this->x = camBounds[i].xa;

				}
				if (playerX >=camBounds[i].xb + s / 2)
				{
					this->x = camBounds[i].xb ;

				}

				flag = 1; 

			}

			// truc y 
			if (playerY > camBounds[i].ya && playerY < camBounds[i].yb + s)
			{
				if (playerY > camBounds[i].ya + s / 2 && playerY < camBounds[i].yb + s / 2)
				{
					this->y = playerY - s / 2 - vy;
				}

				if (playerY <= camBounds[i].ya + s / 2)
				{
					this->y = camBounds[i].ya;

				}
				if (playerY >= camBounds[i].yb + s / 2)
				{
					this->y = camBounds[i].yb;

				}
				flag ++; 
			}
			
			if (flag==2 )
			{
				break; 
			}
			flag = 0; 
		}

		moveDir = d; 


	}




	Direction getMoveDir() { return moveDir; }
	ViewPort* getViewport() { return viewPort; }

};