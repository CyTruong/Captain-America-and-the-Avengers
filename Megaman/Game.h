﻿#pragma once
#include "SceneManager.h"
#include <d3d9.h>
#include "Scene1.h" 
#include "Boss1Scene.h"
//thiếu

class Game
{
public:
	Game(HWND);
	~Game();
	void Clean();
	void Update();
	void Draw();
	
	/// xem dang o map nao 
	int flag; 

};

