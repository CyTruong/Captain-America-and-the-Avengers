#pragma once

#include"Scene.h"


class SceneManager
{
public:

	~SceneManager() {};

	void Update(float delta);
	void ReplaceScene(Scene* scene);

	static SceneManager * GetInstance();
	Scene * GetCurScene();

	void createScene(Scene* scene);



private:
	SceneManager();
	static SceneManager* Instance;
	Scene *		CurScene;
	Scene *     destScene;


};


