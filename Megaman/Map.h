#pragma once

#include "tinyxml.h"
#include "TileLayer.h"
#include <string>
#include <vector>
#include <atlconv.h>
#include "zlib.h"
#include "zconf.h"
#include "base64.h"
#include "QuadTree.h"
#include "Grid.h"
#include "MegamanSprite.h"
#include "EnemyCreator.h"
#include "EnemySprite.h"
#include "ObjectSprite.h"
#include "UI.h"

//H
#include"Camera.h"
#include"CollisionRect.h"
class Map
{

public:
	Map(std::string mapName);
	~Map();
	void draw(Camera* cam);
	void drawTile(Camera* cam);
	void drawEnemy(Camera* cam);
	void drawObj(Camera* cam);
	//chưa có quản lí dc đạn của map
	//void drawBullet(Camera* cam);
	std::vector< TileSet* >* getTileSets() // return the address of this vector
	{
		return &tileSets;
	}
	std::vector < Layer* >* getLayers()
	{
		return &layers;
	}
	RectF getMapRect()
	{ // hcmt lay chieu rong cua hinh chu nhat 
	return RectF(0.0f, 0.0f,15*16,15*16);

	  //	return RectF(0.0f, 0.0f, width * tileSize, height * tileSize);
	}
	void onCollision(Camera* cam);
	void onCollisionvsPlayer(MegamanSprite* sprite, Camera* cam);
	void onSupportPlayer(MegamanSprite* sprite);
	void onSupportSprite();
	void onUpdatePlayerProperties(MegamanSprite* sprite, Camera* cam);
	void onUpdate(Camera* cam);
	float getResX();
	float getResY();
	RectF getCameraTranslatePoint();
	std::vector < std::string>& getSpriteNames();
	bool isFinish();
private:
	std::vector< TileSet* > tileSets; // vector of TileSet Pointer
	std::vector< Layer* > layers; // vector of Layer pointer
	std::vector < CollisionRectF > collisionRectFs;
	std::vector < BulletSprite* > bulletSprites;
	std::vector < Object*> Objects;
	std::vector < std::string> spriteNames;
	std::map < int, EnemySprite* > EnemyMap;
	std::map < int, ObjectSprite* > objectMap;
	int tileSize;
	int width; // number of tile in row
	int height; // number of tile in col
	//QuadTree* mapCollisionTree;
	Grid* mapCollisionGrid;
	int **mapArr;

private:
	void loadTileSet();
	void loadLayer();
	void loadCollisionRect(vector<CollisionRectF> colRectF);
	void createMapGridTree();
	void createMapCollsionTree();
	void loadObject();
	void cleanPlayerBullet(Camera* cam, MegamanSprite* sprite);
	void cleanMap(Camera* cam);
	void addEToMap(Camera* cam);
	std::string mapName;
	float respawnX;
	float respawnY;
	RectF cameraTranslatePosition;
	bool bIsFinish;
};