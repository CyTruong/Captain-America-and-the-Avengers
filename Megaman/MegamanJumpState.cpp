#include "MegamanJumpState.h"
// Note ; thêm sate là climpling, súng đạm, check collision
#include "MegamanSlideState.h"
#include"MegamanRunningState.h"
#include"MegamanStandingState.h"
#include"MegamanStandShootState.h"
//MegamanJumpState::MegamanJumpState(MegamanData* data, bool ismove , float vy,)
//{
//
//	this->pData = data;
//	speedX = 1;
//	pData->vy = vy;
//	acceleration = 0.2f;
//
//	this->isMoving = ismove;
//	if (pData->vy < 0) {
//		LogWriter::getInstance()->write("Start Jumpping");
//
//		pData->setiCurrentArray(MegamanData::JUMP);
//		pData->movedir = Direction::createUp(); 
//		isJumpingPress = true;
//	}
//	else
//	{
//		LogWriter::getInstance()->write("Start Falling");
//
//		pData->setiCurrentArray(MegamanData::FALL);
//		pData->movedir = Direction::createDown();
//		isJumpingPress = false;
//	}
//	tempDir = pData->dir;
//}


MegamanJumpState::MegamanJumpState(MegamanData * data, bool isMoving, float vy, bool isCimping)
{
	this->pData = data;
	speedX = 1;
	pData->vy = vy;
	//	acceleration = 0.2f;

	this->isMoving = isMoving; 
	this->isCimping = isCimping; 
	if (pData->vy < 0) {
		LogWriter::getInstance()->write("Start Jumpping");

		pData->setiCurrentArray(MegamanData::JUMP);
		pData->movedir = Direction::createUp();
		isJumpingPress = true;
	}
	else
	{
		LogWriter::getInstance()->write("Start Falling");

		pData->setiCurrentArray(MegamanData::FALL);
		pData->movedir = Direction::createDown();
		isJumpingPress = false;
	}
	tempDir = pData->dir;
}



MegamanJumpState::~MegamanJumpState()
{
}

void MegamanJumpState::onMovePressed(Direction dir)
{
	pData->dir = dir;
	tempDir = dir;
	//hcmt cam move 
	pData->movedir = dir;
	isMoving = true;

	//if (isCimping)
	//{
	//	pData->dir.reverse(); 
	//	pData->movedir = pData->dir;  
	//	pData->vx = 0; 
	//	//pData->vy += 0.2; 
	//	
	//	transition(new MegamanWallClimping(pData)); 


	//}
	
	

}

void MegamanJumpState::onMoveReleased(Direction dir)
{
	tempDir = tempDir ^ dir;
	if (!tempDir.isNone())
	{
		pData->dir = tempDir;
		pData->movedir = tempDir; 

	}
	else
		isMoving = false;
}

void MegamanJumpState::onJumpPressed()
{
	if (isCimping)
	{
		transition(new MegamanJumpState(pData, true));
	}

	// -> truovc

}

void MegamanJumpState::onJumpRelease()
{
	this->pData->vy =  max(this->pData->vy,0);
}

void MegamanJumpState::onSlidePressed()
{
	transition(new MegamanSlideState(pData));
}

void MegamanJumpState::onCollision(RectF rect)
{
	// có 4 trường hợp va chạm
	float vx = pData->vx;
	float vy = pData->vy;
	float top = pData->getBody().y;
	float left = pData->getBody().x;
	float right = left + pData->getBody().width;
	float bottom = top + pData->getBody().height;


	float topR = rect.y;
	float leftR = rect.x;
	float rightR = leftR + rect.width;
	float bottomR = topR + rect.height;

	if (vx > 0.0f)
	{
		if (vy > 0.0f)
		{
			float px = right - leftR;
			float py = bottom - topR;
			if (vy * px > vx * py)
			{
				// va chạm phía trên 
				pData->vy = 0.0f;
				pData->y -= py;

		

				if (isMoving)
				{
					transition(new MegamanRunningState(pData));
				}
				else
				{
					transition(new MegamanStandingState(pData));
				}
			}
			else
			{
				// va chạm bên phải
				pData->x -= px;
				pData->vx = 0.0f;
			}
		}
		else // vy <= 0.0f
		{
			float px = right - leftR;
			float py = bottomR - top;
			if ((-vy * px) > vx * py)
			{
				//va chạm trên
				pData->y += py;
				pData->vy = 0.0f;
			}
			else
			{
				//va chạm bên trái
				pData->x -= px;
				pData->vx = 0.0f;
			}
		}
	}
	else // vx <= 0.0f
	{
		if (vy > 0.0f)
		{
			float px = rightR - left;
			float py = bottom - topR;
			if (vy * px > (-vx * py))
			{
				// top collision

				pData->y -= py;
				pData->vy = 0.0f;
				if (isMoving)
				{ 

					transition(new MegamanRunningState(pData));
				}
				else
				{
					transition(new MegamanStandingState(pData));
				}
			}
			else
			{
				// side collision
				pData->x += px;
				pData->vx = 0.0f;
			}
		}
		else // vy <= 0.0f
		{
			float px = rightR - left;
			float py = bottomR - top;
			if ((-vy * px) > (-vx * py))
			{
				// top collision
				pData->y += py;
				pData->vy = 0.0f;
			}
			else
			{
				// side collision
				pData->x += px;
				pData->vx = 0.0f;
			}
		}
	}
}

void MegamanJumpState::onCollision(CollisionRectF rect)
{
	//LogWriter::getInstance()->write("Jump collision "+ rect.type );
	// có 4 trường hợp va chạm
	//hcmt 
	float vx = pData->vx;
	float vy = pData->vy;
	float top = pData->getBody().y;
	float left = pData->getBody().x;
	float right = left + pData->getBody().width;
	float bottom = top + pData->getBody().height;


	float topR = rect.rect.y;
	float leftR = rect.rect.x;
	float rightR = leftR + rect.rect.width;
	float bottomR = topR + rect.rect.height;

	if (vx > 0.0f)
	{
		if (vy > 0.0f)
		{
			float px = right - leftR;
			float py = bottom - topR;
			if (vy * px > vx * py)
			{
				// va chạm phía trên 
				pData->vy = 0.0f;
				pData->y -= py;

					if (isMoving)
					{
						transition(new MegamanRunningState(pData));
					}
					else
					{
						transition(new MegamanStandingState(pData));
					}
			}
			else
			{// va chạm bên phải
				pData->x -= px;
				pData->vx = 0.0f;


				/*if (rect.type=="wall")

				{ 
					pData->x -= 2; 

					pData->movedir = Direction::createUp(); 

					transition(new MegamanWallClimping(pData)); 

				}*/
				 
			}
		}
		else // vy <= 0.0f
		{
			float px = right - leftR;
			float py = bottomR - top;
			if ((-vy * px) > vx * py)
			{
				//va chạm trên
				pData->y += py;
				pData->vy = 0.0f;
			}
			else
			{
				pData->x -= px;
				pData->vx = 0.0f;

			/*	if (rect.type == "wall")
				{  

					pData->movedir = Direction::createUp();

					transition(new MegamanWallClimping(pData));

				}*/
				//va chạm bên trái
				;
			}
		}
	}
	else // vx <= 0.0f
	{
		if (vy > 0.0f)
		{
			float px = rightR - left;
			float py = bottom - topR;
			if (vy * px > (-vx * py))
			{
				// top collision

				pData->y -= py;
				pData->vy = 0.0f;

				if (isMoving)
				{
					transition(new MegamanRunningState(pData));
				}
				else
				{
					transition(new MegamanStandingState(pData));
				}
			}
			else
			{
				// side collision
				pData->x += px;
				pData->vx = 0.0f;

			/*	if (rect.type == "wall")
				{

					pData->movedir = Direction::createUp();

					transition(new MegamanWallClimping(pData));

				}*/
			}
		}
		else // vy <= 0.0f
		{
			float px = rightR - left;
			float py = bottomR - top;
			if ((-vy * px) > (-vx * py))
			{
				// top collision
				pData->y += py;
				pData->vy = 0.0f;
			}
			else
			{
				// side collision
				pData->x += px;
				pData->vx = 0.0f;

				//if (rect.type == "wall")
				//{

				//	pData->movedir = Direction::createUp();

				//	transition(new MegamanWallClimping(pData));

				//}
			}
		}
	}
}

void MegamanJumpState::onDynamicObjectCollision(CollisionRectF * cRect)
{
	//LogWriter::getInstance()->write("Jump collision object " +cRect->type);
	// có 4 trường hợp va chạm
	//hcmt 
	float vx = pData->vx;
	float vy = pData->vy;
	float top = pData->getBody().y;
	float left = pData->getBody().x;
	float right = left + pData->getBody().width;
	float bottom = top + pData->getBody().height;


	float topR = cRect->rect.y;
	float leftR = cRect->rect.x;
	float rightR = leftR + cRect->rect.width;
	float bottomR = topR + cRect->rect.height;

	if (vx > 0.0f)
	{
		if (vy > 0.0f)
		{
			float px = right - leftR;
			float py = bottom - topR;
			if (vy * px > vx * py)
			{
				// va chạm phía trên 
				pData->vy = 0.0f;
				pData->y -= py;

				if (isMoving)
				{
					transition(new MegamanRunningState(pData));
				}
				else
				{
					transition(new MegamanStandingState(pData));
				}
			}
			else
			{// va chạm bên phải
				pData->x -= px;
				pData->vx = 0.0f;



			}
		}
		else // vy <= 0.0f
		{
			float px = right - leftR;
			float py = bottomR - top;
			if ((-vy * px) > vx * py)
			{
				//va chạm trên
				pData->y += py;
				pData->vy = 0.0f;
			}
			else
			{
				pData->x -= px;
				pData->vx = 0.0f;

			}
		}
	}
	else // vx <= 0.0f
	{
		if (vy > 0.0f)
		{
			float px = rightR - left;
			float py = bottom - topR;
			if (vy * px > (-vx * py))
			{
				// top collision

				pData->y -= py;
				pData->vy = 0.0f;

				if (isMoving)
				{
					transition(new MegamanRunningState(pData));
				}
				else
				{
					transition(new MegamanStandingState(pData));
				}
			}
			else
			{
				// side collision
				pData->x += px;
				pData->vx = 0.0f;
			}
		}
		else // vy <= 0.0f
		{
			float px = rightR - left;
			float py = bottomR - top;
			if ((-vy * px) > (-vx * py))
			{
				// top collision
				pData->y += py;
				pData->vy = 0.0f;
			}
			else
			{
				// side collision
				pData->x += px;
				pData->vx = 0.0f;
			}
		}
	}

}


void MegamanJumpState::onUpdate()
{
	hittableCalculation();
	undyingCalculation();
	pData->ppTextureArrays[pData->iCurrentArr]->update();


	if (pData->isCharging) {
		pData->ChargingCount++;
		pData->bulletSize = getSizeofBullet(pData->ChargingCount);
		pData->ppTextureArrays[pData->bulletSize]->update();
	}

	

	if (isMoving)
	{
		pData->vx = pData->transform(speedX);
	}
	else
	{
		pData->vx = 0.0f;
	}

	pData->vy += acceleration;

	//hcmt 
	pData->movedir = pData->dir; 

	if (pData->vy < 0)
	{

		pData->movedir = Direction::createUp();


	}
	if (pData->vy>0)
	{

		pData->movedir = Direction::createDown();

	}


	if (pData->vy>= 0 && !pData->isFrire) {
		pData->setiCurrentArray(MegamanData::FALL);
		isJumpingPress = false;
	}
	
	if (pData->isFrire && pData->iCurrentArr == MegamanData::FALL) {
		pData->setiCurrentArray(MegamanData::FALLSHOOT);
	}else
	if (!pData->isFrire && pData->iCurrentArr == MegamanData::FALLSHOOT) {
		pData->setiCurrentArray(MegamanData::FALL);
	}

	if (pData->isFrire) {
		pData->FireCountFrames++;
		if (pData->FireCountFrames > FIRE_COUNTING_FRAME) {
			pData->FireCountFrames = 0;
			pData->isFrire = false;
		}
	}


	pData->x += pData->vx ;
	pData->y += pData->vy ;


}

void MegamanJumpState::onFirePressed()
{
	//pData->isCharging = true;

}

void MegamanJumpState::onFireRelease()
{
	if (!this->pData->isFrire) {
		pData->isCharging = false;
		pData->isFrire = true;
		pData->ChargingCount = 0;


		float bulletX;
		float bulletY;
		float angle;

		if (pData->dir.isRight())
		{
			bulletX = pData->ppTextureArrays[pData->iCurrentArr]->getWidth() / 2 + pData->x;
		}
		else
		{
			bulletX = -pData->ppTextureArrays[pData->iCurrentArr]->getWidth() / 2 + pData->x;
		}

		bulletY = pData->y - pData->ppTextureArrays[pData->iCurrentArr]->getHeight() * 5 / 12 + 3;


		if (pData->dir.isRight())
		{
			angle = 0.0f;
		}
		else
		{
			angle = M_PI;
		}
		this->pData->bulletType = BulletTypes::KICK;
		createBullet(bulletX, bulletY, angle);
		this->pData->bulletType = BulletTypes::SHEILD;
	}
}

void MegamanJumpState::onVeticalDirectionPressed(Direction d)
{
	pData->verticalDir = d;
}

void MegamanJumpState::onVeticalDirectionReleased()
{
	pData->verticalDir = Direction::createNone();
	pData->setiCurrentArray(MegamanData::RUN);

}

void MegamanJumpState::onDead()
{
}
