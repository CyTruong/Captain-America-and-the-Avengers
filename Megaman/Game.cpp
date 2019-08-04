#include "Game.h"
#include "Sound.h"


Game::Game(HWND hWnd)
{
	Graphics::create(hWnd);
	Sound::create(hWnd);
	
	flag = 0; 
	SceneManager::GetInstance()->createScene(new Scene1());


}
void Game::Update()
{
	/*if (!SceneManager::GetInstance()->isSceneTransitioning())
	{
		SceneManager::getInstance()->getCurrentScene()->onUpdate();
	}
	else
	{
		SceneTransition::getInstance()->update();
		SceneManager::getInstance()->updateWithEffect();
	}*/
	SceneManager::GetInstance()->GetCurScene()->onUpdate();

	if (UIComponents::getInstance()->getMegamanX()>126*16 &&flag==0)
	{ 
		flag = 1; 
		SceneManager::GetInstance()->createScene(new Boss1Scene());

	}	

}

void Game::Draw()
{
	SceneManager::GetInstance()->GetCurScene()->render();
}


void Game::Clean()
{
	//UIComponents::getInstance()->cleanUp();
	//Sound::getInstance()->cleanUp();
	//Graphics::getInstance()->cleanUp();	
}



Game::~Game()
{
}
