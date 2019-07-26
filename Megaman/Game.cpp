#include "Game.h"
#include "Sound.h"


Game::Game(HWND hWnd)
{
	Graphics::create(hWnd);
	Sound::create(hWnd);
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
