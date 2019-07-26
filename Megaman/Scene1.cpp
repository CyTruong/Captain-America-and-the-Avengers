
#include "Scene1.h"
#include "Sound.h"
#include "define.h"

void Scene1::loadSound()
{
	Sound::getInstance()->loadSound("Resource\\Sound\\MgmBulletNormalMFire.wav","MgmBulletNormalMFire");
	Sound::getInstance()->loadSound("Resource\\Sound\\MgmBulletNormalSFire.wav","MgmBulletNormalSFire");
	Sound::getInstance()->loadSound("Resource\\Sound\\MgmBulletNormalLFire.wav", "MgmBulletNormalLFire");
	Sound::getInstance()->loadSound("Resource\\Sound\\MgmWallJump.wav", "MgmBulletNormalLFire");
	Sound::getInstance()->loadSound("Resource\\Sound\\MgmTakeDameged.wav", "MgmTakeDameged");
	Sound::getInstance()->loadSound("Resource\\Sound\\MgmCharge.wav", "MgmCharge");
	Sound::getInstance()->loadSound("Resource\\Sound\\SingleGunFire.wav", "SingleGunFire");
	Sound::getInstance()->loadSound("Resource\\Sound\\stage1.wav", "BlastHornet");
	Sound::getInstance()->loadSound("Resource\\Sound\\Bullet_Destroy.wav", "BulletDestroy");
	Sound::getInstance()->loadSound("Resource\\Sound\\Bullet_Destroy2.wav", "BulletDestroy2");
	Sound::getInstance()->loadSound("Resource\\Sound\\Dash.wav", "Dash");
	Sound::getInstance()->loadSound("Resource\\Sound\\Jump.wav", "Jump");
	Sound::getInstance()->loadSound("Resource\\Sound\\Elevator.wav", "Elevator");
	Sound::getInstance()->loadSound("Resource\\Sound\\Enemy_Destroy.wav", "Enemy_Destroy");
	Sound::getInstance()->loadSound("Resource\\Sound\\Death.wav", "Death");


	
	
}

Scene1::Scene1()
{
	std::string mapName = "BlastHornetStage2";

	pMap = new Map(mapName);


	loadSound();

	int viewPortSize = pMap->getMapRect().width < pMap->getMapRect().height ? pMap->getMapRect().width : pMap->getMapRect().height;
	viewPortSize = 480;
	viewPort = new ViewPort(RectI(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));


	cam = new Camera(viewPort, 0, 0, RectF(0, 0, 16 * 30, 30 * 16), RectF(0, 0, 128 * 16, 30 * 16));



	pMegaman = new MegamanSprite(16 * 5, 0, cam->getMoveDir());
	//pMegaman = new MegamanSprite(7500, 1800, cam->getMoveDir());
   //pMegaman = new MegamanSprite( 1940, 1035, cam->getMoveDir());
   //pMegaman = new MegamanSprite(120, 120+16*48, cam->getMoveDir());

	// Texture Hp 
	hpHub = new HPBarSprite(cam, 15, 80);

	//hpHubBoss = new HPBarSprite(cam, 210, 80, 0);




	isPause = false;
	isFinish = false;
	isGameOver = false;
	nTransitionFrames = 5 * 60;
	count = 0;


	//Sound::getInstance()->play("stage" + std::to_string(UIComponents::getInstance()->getCurrentStage()), true, 1);
	//Sound::getInstance()->play("BlastHornet", true, 1);
}

Scene1 ::~Scene1()
{
	delete pMegaman;
	pMegaman = NULL;
	delete viewPort;
	viewPort = NULL;

	delete cam;
	cam = NULL;
	delete pMap;
	pMap = NULL;

	//del hp 

}

void Scene1::onCollision()
{

	pMap->onCollisionvsPlayer(pMegaman, cam);
	pMap->onCollision(cam);
}

void Scene1::handlerInput()
{
	while (!KeyBoard::GetInstance()->isEmpty())
	{
		KeyEvent e = KeyBoard::GetInstance()->ReadPop_Key();

		//xét is pause


		if (!isPause)
		{
			char keyCode = e.getCode();
			//Lưu ý lỗi michale jack
			if (keyCode == UIComponents::getInstance()->getKey(UIComponents::RIGHT))
			{
				if (e.isPressed())
				{
					pMegaman->getState()->onMovePressed(Direction::createRight());
				}
				else
				{
					pMegaman->getState()->onMoveReleased(Direction::createRight());
				}
			}
			else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::LEFT))
			{
				if (e.isPressed())
				{
					pMegaman->getState()->onMovePressed(Direction::createLeft());
				}
				else
				{
					pMegaman->getState()->onMoveReleased(Direction::createLeft());
				}
			}
			else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::UP))
			{
				if (e.isPressed())
				{
					pMegaman->getState()->onVeticalDirectionPressed(Direction::createUp());
				}
				else
				{
					pMegaman->getState()->onVeticalDirectionReleased();
				}
			}
			else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::DOWN))
			{
				if (e.isPressed())
				{
					pMegaman->getState()->onVeticalDirectionPressed(Direction::createDown());
				}
				else
				{
					pMegaman->getState()->onVeticalDirectionReleased();
				}
			}
			else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::JUMP))
			{
				if (e.isPressed())
				{
					Sound::getInstance()->play("Jump", false, 1);
					pMegaman->getState()->onJumpPressed();
				}
				else
				{
					pMegaman->getState()->onJumpRelease();
				}
			}
			else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::FIRE))
			{
				if (e.isPressed())
				{
					pMegaman->getState()->onFirePressed();
				}
				else
				{
					pMegaman->getState()->onFireRelease();
					Sound::getInstance()->stop("MgmCharge");
				}
			}
			else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::SLIDE)) {
				if (e.isPressed())
				{
					Sound::getInstance()->play("Dash",false,1);
					pMegaman->getState()->onSlidePressed();
				}
			}
		}
	}

	KeyBoard::GetInstance()->Clean();

}
void Scene1::onUpdate()
{
	//	if (isGameOver)
	//	{
	//		count++;
	//		if (count == nTransitionFrames)
	//		{
	//			//GameSaveLoad::getInstance()->checkAndSaveScore(UIComponents::getInstance()->getScore());
	//			SceneManager::getInstance()->createSceneWithRandomTransition(new GameOverScene());
	//			return;
	//		}
	//	}
	//	else if (isFinish)
	//	{
	//		count++;
	//		if (count == nTransitionFrames)
	//		{
	//			if (UIComponents::getInstance()->getCurrentStage() < 3)
	//			{
	//				UIComponents::getInstance()->setStage(UIComponents::getInstance()->getCurrentStage() + 1);
	//				SceneManager::getInstance()->createScene(new LoadingScene());
	//			}
	//			else
	//			{
	//				SceneManager::getInstance()->createScene(new EndingScene());
	//			}
	//			return;
	//		}
	//	}

	this->handlerInput(); 

	// not nessc 

	if (!isPause)
	{
		Update();
		onCollision();

		isFinish = pMap->isFinish();
		/*int lifes = 0;
		for (int i = 0; i < nPlayers; i++)
		{
			lifes += UIComponents::getInstance()->getLifes(i);
		}
		if (lifes <= 0)
		{
			isGameOver = true;
		}*/
	}


}
void Scene1::render()
{

	Graphics::getInstance()->beginRender();
	Graphics::getInstance()->getSpriteHandler()->Begin(D3DXSPRITE_ALPHABLEND);
	//bg->draw(cam);

	//pMap->draw(cam);
	pMap->drawTile(cam);

	pMegaman->draw(cam);

	pMap->drawEnemy(cam);

	

	pMap->drawObj(cam);
	//draw HP col 
	
	hpHub->draw(cam);

	Graphics::getInstance()->getSpriteHandler()->End();
	Graphics::getInstance()->endRender();


}

void Scene1::Update()
{

	//update vị trí của ng chơi cho enemy
	pMap->onUpdatePlayerProperties(pMegaman, cam);

	// update animation of tilesets in here
	pMap->onUpdate(cam);


	// check collision player and rect 


	//pMap->onSupportPlayer(pMegaman);

	// check collision enemy, boss, object vs Map 

	// thang nay update quadtree affter clear () 
	pMap->onSupportSprite();


	pMegaman->update();


	// add stoppoint 0 1 2 
	int isCamStop = 0; 
	
	if (UIComponents::getInstance()->getShurikanHp()!=0 )
	{ 
		isCamStop = 1;

	}
	else
	{    // const is range of boss1 room 

		if (pMegaman->getX()>2320&& pMegaman->getX()<2544)
		{
			isCamStop = 1; 


		}
	}
  
	// truyen vao not tiep theo 
	int Mx = pMegaman->getX();
	int My = pMegaman->getY();
	int i = -1; 

	//
	for (int  j = 0; j < 10; j++)
	{
		if (cam->pCamPos[j].d==0)
		{
			if (My > cam->pCamPos[j].a &&My<cam->pCamPos[j].a + 240 && Mx>cam->pCamPos[j].b&&Mx <= cam->pCamPos[j].c + 120)
			{

				i = j;
			}
		}
		if (cam->pCamPos[j].d == 1)
		{
			if (Mx > cam->pCamPos[j].a &&Mx<cam->pCamPos[j].a + 240 && My > cam->pCamPos[j].b&&My <= cam->pCamPos[j].c+120)
			{
				i = j; 

			}

		}
		if (cam->pCamPos[j].d ==2 )
		{
			if (My > cam->pCamPos[j].a &&My<cam->pCamPos[j].a + 240 && Mx>cam->pCamPos[j].b&&Mx <= cam->pCamPos[j].c + 240)
			{

				i = j;
			}
		}

	}



	cam->update(pMegaman->getX(), pMegaman->getY(), pMegaman->getMoveDir(),isCamStop, i );


	//update megaman theo cái cam
	pMegaman->setCameraRect(cam->getRect());

	hpHub->update();

	//bg->update();
	/*if (pMegaman->getX() > 478 * 16)
	{
		hpHubBoss->update();


	}*/
}

