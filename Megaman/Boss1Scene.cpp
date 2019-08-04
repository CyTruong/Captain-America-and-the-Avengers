
#include "Scene1.h"
#include "Sound.h"
#include "define.h"
#include "Boss1Scene.h"
void Boss1Scene::loadSound()
{

}

Boss1Scene::Boss1Scene()
{     
	std::string mapName = "BossMap1";

	pMap = new Map(mapName);

	// if mapname ; 

	int numberColumOfMap = NUMBER_COLUMM_BOSSMAP1;
	int numberRowOfMap = NUMBER_ROW_BOSSMAP1;
	int startPointX = START_BOSSMAP1_POINT_X;
	int startPointY = START_BOSSMAP1_POINT_Y;



	loadSound();

	int viewPortSize = pMap->getMapRect().width < pMap->getMapRect().height ? pMap->getMapRect().width : pMap->getMapRect().height;
	viewPortSize = VIEWPORT_SIZE;
	viewPort = new ViewPort(RectI(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));


	//cam = new Camera(viewPort, startPointX, startPointY, RectF(0, 0, TILE_SIZE * 16, TILE_SIZE * 16), RectF(0, 0, numberColumOfMap * TILE_SIZE, numberRowOfMap * TILE_SIZE));
	Cambounds camBounds (mapName);

	cam = new Camera(viewPort, startPointX, startPointY, RectF(0, 0, TILE_SIZE * 16, TILE_SIZE * 16), RectF(0, 0, numberColumOfMap * TILE_SIZE, numberRowOfMap * TILE_SIZE), camBounds.getCamBounds(), 2);

	pMegaman = new MegamanSprite(TILE_SIZE * 2, TILE_SIZE * 2, cam->getMoveDir());
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

Boss1Scene ::~Boss1Scene()
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

void Boss1Scene::onCollision()
{

	pMap->onCollisionvsPlayer(pMegaman, cam);
	pMap->onCollision(cam);
}

void Boss1Scene::handlerInput()
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
					Sound::getInstance()->play("Dash", false, 1);
					pMegaman->getState()->onSlidePressed();
				}
			}
		}
	}

	KeyBoard::GetInstance()->Clean();

}
void Boss1Scene::onUpdate()
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
void Boss1Scene::render()
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

void Boss1Scene::Update()
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

	if (UIComponents::getInstance()->getShurikanHp() != 0)
	{
		isCamStop = 1;

	}
	else
	{    // const is range of boss1 room 

		if (pMegaman->getX() > 2320 && pMegaman->getX() < 2544)
		{
			isCamStop = 1;


		}
	}

	// truyen vao not tiep theo 
	int Mx = pMegaman->getX();
	int My = pMegaman->getY();
	int i = -1;

	// kiem tra loai map ma cam di chuyen onlyngang ,doc , ngangdoc , boss 


	

	cam->update(pMegaman->getX(), pMegaman->getY(), pMegaman->getMoveDir(), isCamStop, i);


	//update megaman theo cái cam
	pMegaman->setCameraRect(cam->getRect());

	hpHub->update();

	//bg->update();
	/*if (pMegaman->getX() > 478 * 16)
	{
		hpHubBoss->update();


	}*/
}

