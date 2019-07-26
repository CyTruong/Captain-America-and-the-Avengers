#include "SceneManager.h"



SceneManager* SceneManager::Instance = nullptr;


SceneManager::SceneManager()
{

}


SceneManager* SceneManager::GetInstance()
{
	if (Instance == nullptr)
		Instance = new SceneManager();

	return Instance;
}

Scene* SceneManager::GetCurScene()
{
	return CurScene;
}

void SceneManager::createScene(Scene * scene)
{
	if (scene)
	{
		if (1)
		{
			delete CurScene;

			CurScene = scene;

		}

	}

}

void SceneManager::Update(float dt)
{
	SceneManager::GetCurScene()->onUpdate();

}

void SceneManager::ReplaceScene(Scene *scene)
{
	delete CurScene;

	CurScene = scene;
}