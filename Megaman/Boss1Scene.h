#pragma once
#pragma once
#include "Scene.h"
#include "Camera.h"
#include"Viewport.h"
#include "MegamanSprite.h"
#include"MegamanState.h"
#include "KeyBoard.h" 
#include"define.h"
#include"Map.h"
#include "BackGround.h"
#include "HPBarSprite.h"

class Boss1Scene: public Scene
{
private:
	void loadSound();

public:

	Boss1Scene();
	virtual ~Boss1Scene();

	virtual void onCollision();
	virtual void handlerInput();
	virtual void render();
	virtual void onUpdate();
	virtual void Update();


private:
	MegamanSprite* pMegaman;
	ViewPort* viewPort;
	Camera* cam;
	Map* pMap;
	BackGround* bg;
	HPBarSprite* hpHub;
	HPBarSprite* hpHubBoss;


	//->texture **hp 
	//Texture** lifeTexture;
	int nTransitionFrames;
	int count;
	int stageIndex;
	bool isGameOver;
	bool isFinish;
	bool isPause;
	int nPlayers;
	// shader lightign 
};
