#pragma once
#include "ViewPort.h"
#include "iostream"
#include "Direction.h"

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

		a = A * 16;
		b = B * 16;
		c = C * 16;
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


public:

	CamPos * pCamPos;
	Camera(ViewPort* viewPort, float x, float y, RectF rect, RectF cameraTranslatePoint)
	{
		f = 0;

		this->viewPort = viewPort;
		this->cameraTranslatePoint = cameraTranslatePoint;
		//mapRect = Rect(0,0,128*16,16*30);
		mapRect = cameraTranslatePoint;

		this->x = 0;
		this->y = 0;
		NumberOfcamPos = 1;
		pCamPos = new CamPos[NumberOfcamPos];

		pCamPos[0] = CamPos(0, 0, 98, 0);
		//pCamPos[1] = CamPos(48 ,32,64, 1);
		//pCamPos[2] = CamPos(16, 48, 98, 0);
	 //   pCamPos[3] = CamPos(64, 104, 138, 0);
		////pCamPos[4] = CamPos(24, 56, 63, 0); 
		//
		////boss1 vs2 
		//pCamPos[4] = CamPos(64, 145, 145, 2);

		//pCamPos[5] = CamPos(64, 159, 185, 0);
		//pCamPos[6] = CamPos(64, 262, 364 , 0);
		//pCamPos[7] = CamPos(369, 68, 100, 1); 
		//pCamPos[8] = CamPos(106,369 ,475 , 0);
		//pCamPos[9] = CamPos(106, 479, 479, 2); 







//pCamPos[10] = CamPos(96, 32, 70, 1); 



		/*this->x = x - (float)viewPort->getWidth() / 2.0f;
		this->y = y - (float)viewPort->getHeight() / 2.0f*/

		//this->x = max(this->x, mapRect.x);
		//this->y = max(this->y, mapRect.y);

		//this->x = min(this->x, mapRect.width + mapRect.x - viewPort->getWidth());
		//this->y = min(this->y, mapRect.height + mapRect.y - viewPort->getHeight());

		moveDir = Direction::createRight();
		/*
				if (this->y == cameraTranslatePoint.y)
				{
					moveDir = Direction::createRight();
				}
				else if (this->x == cameraTranslatePoint.x)
				{
					moveDir = Direction::createUp();
				}*/
		vx = vy = 1.0f;

	}
	void setPosX(float x, bool c)
	{
		int a = x - 240;

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
			//this->x = max(this->x, mapRect.x);
			//this->x = min(this->x, mapRect.width + mapRect.x - viewPort->getWidth());



		}



	}
	void setPosY(float y, bool c)
	{

		int b = y - 240;

		if (this->y > b && moveDir.isUp())
		{
			this->y = b;
			//this->y = max(this->y, mapRect.y);
			//this->y = min(this->y, mapRect.height + mapRect.y - viewPort->getHeight());
		}

		else if (this->y < b && moveDir.isDown())
		{
			this->y = b;
			//this->y = max(this->y, mapRect.y);
			//this->y = min(this->y, mapRect.height + mapRect.y - viewPort->getHeight());

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

	void update(float x, float y, Direction d, int isCamStop, int i)
	{


		// kiem tra nam trong trục x or y 
		// thì chỉ thay đổi trục ngược lại
		string xx = to_string(x);
		int da = x - this->x;
		int db = y - this->y;

		/*
		int a = x - (float)viewPort->getWidth()/2;
		int b = y - (float)viewPort->getHeight()/2;*/


		int a = x - 240;
		int b = y - 240;
		moveDir = d;



		// var xac dinh di qua boss1 chua va toi boss 2 chua 


		if (i == -1)
		{
			setPosX(x, 0);
			setPosY(y, 0);
			return;

		}

		if (pCamPos[i].d == 2)
		{
			this->y = pCamPos[i].a;
			this->x = pCamPos[i].b;

		}




		if (pCamPos[i].d == 0)
		{
			this->y = pCamPos[i].a;

			if (a >= pCamPos[i].b - ss && a <= pCamPos[i].c + ss)
			{
				setPosX(x, 0);
			}


		}


		if (pCamPos[i].d == 1)
		{

			this->x = pCamPos[i].a;

			if (b >= pCamPos[i].b - ss && b <= pCamPos[i].c + ss)
			{
				setPosY(y, 0);
			}




		}






		//}




		//setPosition(x, y);
	}




	Direction getMoveDir() { return moveDir; }
	ViewPort* getViewport() { return viewPort; }

};