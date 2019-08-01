#pragma once
#include "Sound.h"
#include "Windows.h"
//#include "EnemySprite.h"
#include<string> 

class UIComponents
{
public:
	enum
	{
		LEFT,
		RIGHT,
		UP,
		DOWN,
		FIRE,
		JUMP,
		SLIDE,
		SELECT,
		COUNT
	} KEY;
	~UIComponents();
	static UIComponents* getInstance();
	int getMegamanHp();
	int getScore();
	void inscreaseMegamanHp();
	void descreaseMegamanHp();

	void descreaseShurikanHp();
	int  getShurikanHp(); 
	void setShurikanHp(int hp ); 

	void addScore(int val);
	void setStage(int val);
	void gameOverReset();
	char getKey(int index);
	void setKey(int index, char keyCode);
	char getDefaultKey(int index);
	void setDefaultKeyBoard();
	void resetStage();
	bool isAllowedKey(char keyCode);
	void cleanUp();

	void setMegamanX(float x) {
		this->Megaman_X = x;
	}
	void setMegamanY(float y) {
		this->Megaman_Y = y;
	}
	float getMegamanX() {
		return this->Megaman_X;
	}
	float getMegamanY() {
		return this->Megaman_Y;
	}
	void setisTargeting(bool is) {
		this->isTargetting = is;
	}
	bool isTargeting() {
		return this->isTargetting;
	}
	void setisSheildFlying(bool is) {
		this->isSheildFlying = is;
	}
	bool isSheildFlying() {
		return this->isSheildFlying;
	}

private:
	static UIComponents* instance;
	UIComponents();
	int score;
	int currentStage;
	int Megamanhp;
	float Megaman_X;
	float Megaman_Y;
	bool isTargetting;
	// boss hp 
	int Shurikanhp; 
	bool isSheildFlying;

	char configKeyBoard[COUNT];
	char defaultKeyBoard[COUNT];
};

