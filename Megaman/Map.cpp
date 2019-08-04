#include "Map.h"
#include <algorithm> 
#include <typeinfo>
#include "CollisionMap1.h"
#include "CollisionBossMap1.h"

Map::Map(std::string mapName)
	:
	mapName(mapName)
{
	//change tmx >txt 

	//change de xml 

	// load tile set
	this->tileSize = TILE_SIZE;

	if (mapName=="Map1")
	{
		this->width = NUMBER_COLUMM_MAP1;
		this->height = NUMBER_ROW_MAP1;
	}
	else if (mapName=="BossMap1")
	{
		this->width = NUMBER_COLUMM_BOSSMAP1;
		this->height = NUMBER_ROW_BOSSMAP1;
	}
	
	
	loadTileSet( mapName);

	// load from file txt 


	// load Layer

	//for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	//{
	//	if (e->Value() == std::string("layer"))
	//	{
	//		loadLayer(e);
	//	}
	//}

	loadLayer(mapName);
	// create tileTmx in BackGroundLayer
	for (int i = 0; i < layers.size(); i++)
	{
		//	if (layers[i]->getName() == "BackgroundLayer")
		layers[i]->createTileTmx();
	}

	// Load CollisionLayer
	//for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	//{
	//	if (e->Value() == std::string("objectgroup") && e->Attribute("name") == std::string("CollisionLayer"))
	//	{
	//		
	//	}
	//}
	vector<CollisionRectF> colRectF; 


		collisionMap1 colRect(mapName);
	
		colRectF= colRect.getColRectF();


	loadCollisionRect(colRectF);


	/*for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("objectgroup") && e->Attribute("name") == std::string("ObjLayer"))
		{
			loadObject();
		}
	}*/

	loadObject();

	// create quadtree

	createMapGridTree();
	createMapCollsionTree();
	bIsFinish = false;

	bulletSprites = std::vector < BulletSprite* >();
}


Map::~Map()
{
	for (int i = 0; i < tileSets.size(); i++)
	{
		if (tileSets[i])
			delete tileSets[i];
	}
	tileSets.clear();

	for (int i = 0; i < layers.size(); i++)
	{
		if (layers[i])
			delete layers[i];
	}
	layers.clear();

	collisionRectFs.clear();

	for (int i = 0; i < bulletSprites.size(); i++)
	{
		if (bulletSprites[i])
			delete bulletSprites[i];
	}
	bulletSprites.clear();
	for (int i = 0; i < Objects.size(); i++)
	{
		if (Objects[i])
			delete Objects[i];
	}
	Objects.clear();

	for (auto it = EnemyMap.begin(); it != EnemyMap.end(); it++)
	{
		delete it->second;
	}

	for (auto it = objectMap.begin(); it != objectMap.end(); it++)
	{
		delete it->second;
	}
	
	delete mapCollisionGrid;
//cy	delete mapCollisionTree;


}
#pragma region 


void Map::loadTileSet(string mapname)
{
	std::string s = std::string("Resource\\Map\\"+mapname+"Tileset.png");

	TileSet* tileSet;
	tileSet = new TileSet();
	std::wstring tileSetSource(s.begin(), s.end());

	//tileSet->name = e->Attribute("name");
	tileSet->name = mapname+"Tileset";

	//Graphics::getInstance()->loadTexture(s, e->Attribute("name"));
	Graphics::getInstance()->loadTexture(s, tileSet->name);
	tileSet->pTexture = Graphics::getInstance()->getTexture(tileSet->name)->pTexture;

	

	tileSet->width = TILE_SIZE*this->width; 
	tileSet->height = TILE_SIZE*this->height;
	tileSet->firstGridID = 0;
	tileSet->tileWidth = TILE_SIZE;
	tileSet->tileHeight = TILE_SIZE;
	tileSet->spacing = 0;
	tileSet->margin = 0;


	int nCol = tileSet->width / (tileSet->tileWidth + tileSet->spacing);
	if (tileSet->width % (tileSet->tileWidth + tileSet->spacing) > tileSet->tileWidth)
	{
		nCol++;
	}
	int nRow = tileSet->height / (tileSet->tileHeight + tileSet->spacing);
	if (tileSet->tileHeight % (tileSet->tileHeight + tileSet->spacing) > tileSet->tileHeight)
	{
		nRow++;
	}

	tileSet->nColumns = nCol;
	tileSet->nRows = nRow;
	tileSet->lastGridID = nCol * nRow + tileSet->firstGridID - 1;

	//for (TiXmlElement* ele = e->FirstChildElement(); ele != NULL; ele = ele->NextSiblingElement())
	//{
	//	if (ele->Value() == std::string("tile"))
	//	{
	//		tileSet->loadAnimationTiled(ele);
	//	}
	//}


	tileSets.push_back(tileSet);

}

void Map::loadLayer(string mapname)
{

	mapArr = new int*[height]; 	// w, h 128 ,30 
	TileLayer* pTileLayer = new TileLayer(tileSize, width, height, mapName, tileSets);
	std::vector<std::vector<int>>  data(height, vector<int>(width, 0));
	pTileLayer->fromfile(mapArr);

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			data[j][i] = mapArr[j][i];


		}

	}



	//std::string decodedIDs;

	//TiXmlElement* pDataNode = NULL;

	//for (TiXmlElement* e = pTileElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	//{
	//	if (e->Value() == std::string("data"))
	//	{
	//		pDataNode = e;
	//	}
	//}

	//for (TiXmlNode* e = pDataNode->FirstChild(); e != NULL; e = e->NextSibling())
	//{
	//	TiXmlText* text = e->ToText();

	//	std::string t = text->Value();

	//	decodedIDs = base64_decode(t);
	//}

	//// uncompress zlib compression
	//uLongf numGids = width * height * sizeof(int);

	//std::vector< int > gids(width * height);

	//uncompress((Bytef*)&gids[0], &numGids, (const Bytef*)decodedIDs.c_str(), decodedIDs.size());

	//std::vector<int> layerRow(width);

	//for (int j = 0; j < height; j++)
	//{
	//	data.push_back(layerRow);
	//}
	//for (int rows = 0; rows < height; rows++)
	//{
	//	for (int cols = 0; cols < width; cols++)
	//	{
	//		data[rows][cols] = gids[rows * width + cols];
	//	}
	//}

	pTileLayer->setTileIDs(data);

	layers.push_back(pTileLayer);
}

void Map::loadCollisionRect(vector<CollisionRectF> colRectF)
{

	std::string type;

	//for (TiXmlElement* e = pElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	//{
	//	e->Attribute("x", &r.x);
	//	e->Attribute("y", &r.y);
	//	e->Attribute("width", &r.width);
	//	e->Attribute("height", &r.height);
	//	type = e->Attribute("type");
	//	//collisionRects.push_back(r);
	//	collisionRectFs.push_back(CollisionRectF(r, type));
	//}

	collisionRectFs = colRectF;
}

void Map::loadObject()
{//RectI r;

	int id;
	int x;
	int y;
	int rectX;
	int rectY;
	int width;
	int height;
	std::string name;
	std::string type;

	//for (TiXmlElement* e = pElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	//{
	//	name = e->Attribute("name");
	//	type = e->Attribute("type");
	//	e->Attribute("id", &id);
	//	e->Attribute("x", &rectX);
	//	e->Attribute("y", &rectY);
	//	e->Attribute("width", &width);
	//	e->Attribute("height", &height);

	//	if (name == "cameratranslateposition")
	//	{
	//		cameraTranslatePosition = RectF(rectX, rectY, width, height);
	//	}
	//	else if (name == "respawnposition")
	//	{
	//		respawnX = rectX + width / 2;
	//		respawnY = rectY + height;
	//	}
	//	else
	//	{
	//		if (std::find(spriteNames.begin(), spriteNames.end(), name) == spriteNames.end())
	//			spriteNames.push_back(name);
	//		x = rectX;
	//		y = rectY;

	//		if (type != "object")
	//		{
	//			x = rectX + width / 2;
	//			y = rectY + height;
	//		}
	//		Object* object = new Object(name, type, x, y, id, width, height, RectF(rectX, rectY, width, height));
	//		Objects.push_back(object);
	//	}

	//}
	if (mapName=="Map1")
	{
		Object* enemy = new Object("BlueSoldier", "enemy", 224, 16 * 30 - 50 - 16 * 3, 0, 24, 43, RectF(224, 16*30-50-16*3, 24, 43));
		Objects.push_back(enemy);

		Object* enemy1 = new Object("RocketSoldier", "enemy", 320, 16*30-50-16*3, 1, 24, 43, RectF(320, 16 * 30 - 50 - 16 * 3, 24, 43));
		Objects.push_back(enemy1);

		// enemy 2 


	}

	else
	{
		Object* enemy = new Object("Wizard", "enemy", 160, 160, 0, 24, 43, RectF(160, 160, 24, 43));
		Objects.push_back(enemy);

	}
	

}

void Map::createMapCollsionTree()
{
	/*mapCollisionTree = new QuadTree(0, RectF(0.0f, 0.0f, tileSize * width, tileSize * height));
	
	mapCollisionTree->clear();

	for (int i = 0; i < collisionRectFs.size(); i++)
	{
		mapCollisionTree->insert(collisionRectFs[i]);
	}
*/
}

void Map::createMapGridTree() {
	mapCollisionGrid = new Grid();
	//mapCollisionGrid->clear();
	for (int i = 0; i < collisionRectFs.size(); i++) {
		mapCollisionGrid->insert(collisionRectFs[i]);
	}
}
void Map::cleanMap(Camera* cam)
{
	// clean Enemy
	RectF camRect(cam->getX(), cam->getY(), cam->getWidth(), cam->getHeight());
	for (std::map < int, EnemySprite* > ::iterator it = EnemyMap.begin(); it != EnemyMap.end(); )
	{
		EnemySprite* temp = it->second;
		RectF SpriteRect(temp->getBody());
		if (temp->isDesTroyed())
		{
			//if (temp->isDead())
			//{
			//	//UIComponents::getInstance()->addScore(temp->getScore(), temp->getKillByIndex());
			//}
			//if (temp->getName().find("final") != std::string::npos)
			//{
			//	Sound::getInstance()->stop();
			//	Sound::getInstance()->play("explode.wav", false, 1);

			//	bIsFinish = true;
			//}
			delete temp;
			it = EnemyMap.erase(it);
		}
		else
			it++;
	}

	for (int i = 0; i < bulletSprites.size(); i++)
	{
		Sprite* temp = bulletSprites[i];
		if (!camRect.checkCollision(temp->getBody()) || temp->isDesTroyed())
		{
			delete temp;
			bulletSprites.erase(bulletSprites.begin() + i);
		}
	}


	//// clean ObjectSprite

	//for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); )
	//{
	//	ObjectSprite* temp = it->second;
	//	RectF SpriteRect(temp->getBody());

	//	if (it->second->isDesTroyed())
	//	{
	//		delete temp;
	//		it = objectMap.erase(it);
	//	}
	//	else
	//		it++;
	//}




	//if (bIsFinish)
	//{
	//	for (std::map < int, EnemySprite* > ::iterator it = EnemyMap.begin(); it != EnemyMap.end(); it++)
	//	{
	//		it->second->die();
	//	}

	//	for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); it++)
	//	{
	//		it->second->die();
	//	}

	//	for (int i = 0; i < bulletSprites.size(); i++)
	//	{
	//		bulletSprites[i]->die();
	//	}

	//}


}


void Map::cleanPlayerBullet(Camera* cam, MegamanSprite* sprite)
{
	/*RectF camRect(cam->getX(), cam->getY(), cam->getWidth(), cam->getHeight());
	std::vector<BulletSprite* >& playerBullets = sprite->getBullets();

	for (int i = 0; i < playerBullets.size(); i++)
	{
		Sprite* temp = playerBullets[i];
		if (!camRect.checkCollision(temp->getBody()) || temp->isDesTroyed())
		{
			delete temp;
			playerBullets.erase(playerBullets.begin() + i);
		}
	}*/
}

void Map::addEToMap(Camera* cam)
{
	
	//mapCollisionTree->clear();
	//Thêm obj collision vào list có thể va chạm 
	mapCollisionGrid->clear();
	for (int i = 0; i < Objects.size(); i++)
	{

		if (EnemyMap.find(Objects[i]->id) == EnemyMap.end() && objectMap.find(Objects[i]->id) == objectMap.end())
			mapCollisionGrid->insert(Objects[i]);
	}

	//Lấy danh sách các object trong cam
	std::vector < Object * > returnList;

	RectF camRect = cam->getRect();
	mapCollisionGrid->getObjectlist(returnList, camRect);

	//Với mỗi obj trong map , thêm vào obj map hay enemy map
	for (int i = 0; i < returnList.size(); i++)
	{
		RectF body = returnList[i]->body;
		std::string type = returnList[i]->type;
		if (camRect.checkCollision(body))
		{
			Direction appearDir = EnemyCreator::getInstance()->getAppearDir(returnList[i]->name);
			if (EnemyMap.find(returnList[i]->id) == EnemyMap.end() && objectMap.find(returnList[i]->id) == objectMap.end())
			{
				if (type == "enemy")
				{
					EnemySprite* EnemySprite = EnemyCreator::getInstance()->createEnemySprite(returnList[i]->name, returnList[i]->x, returnList[i]->y, bulletSprites);
					if (EnemySprite != nullptr)
						EnemyMap[returnList[i]->id] = EnemySprite;
				}
				else
				if(type == "object")
				{
					ObjectSprite* objectSprite = EnemyCreator::getInstance()->createObjectSprite(returnList[i]->name, returnList[i]->x, returnList[i]->y);
					if (objectSprite != nullptr)
						objectMap[returnList[i]->id] = objectSprite;
				}
				continue;
			}
			

		}
	}
}



void Map::draw(Camera* cam)
{
	/*for (int i = 0; i < layers.size(); i++)
	{
		if (layers[i]->getName() == "BackgroundLayer")
			layers[i]->draw(cam);
	}

	for (std::map < int, EnemySprite* > ::reverse_iterator it = EnemyMap.rbegin(); it != EnemyMap.rend(); ++it)
	{
		if (!it->second->isDesTroyed()) {
			it->second->draw(cam);
		}
	}

	for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); ++it)
	{
		it->second->draw(cam);
	}

	for (int i = 0; i < bulletSprites.size(); i++)
	{
		bulletSprites[i]->draw(cam);
	}
*/
}

void Map::drawTile(Camera * cam)
{
	
	for (int i = 0; i < layers.size(); i++)
	{
	//	if (layers[i]->getName() == "BackgroundLayer")
			layers[i]->draw(cam);
	}



}

void Map::drawEnemy(Camera * cam)
{
	for (std::map < int, EnemySprite* > ::reverse_iterator it = EnemyMap.rbegin(); it != EnemyMap.rend(); ++it)
	{
		if (!it->second->isDesTroyed()) {
			it->second->draw(cam);
		}
	}

}

void Map::drawObj(Camera * cam)
{
	for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); ++it)
	{
		it->second->draw(cam);
	}

}



void Map::onCollision(Camera* cam)
{
	// map collision vs Player
	

#pragma region EnemyvsMap
	//hcmt 
	RectF camRect = cam->getRect();

	for (std::map < int, EnemySprite* > ::iterator EnemyIt = EnemyMap.begin(); EnemyIt != EnemyMap.end(); EnemyIt++)
	{
		if (!EnemyIt->second->isDesTroyed()) {

			std::vector < CollisionRectF > returnLists;

			mapCollisionGrid->getObjectlist(returnLists, EnemyIt->second->getBody(), camRect);

			for (int i = 0; i < returnLists.size(); i++)
			{
				std::vector < CollisionRectF > throughRectVector = EnemyIt->second->getThroughRect();
				if (std::find(throughRectVector.begin(), throughRectVector.end(), returnLists[i]) == throughRectVector.end())
				{
					if (EnemyIt->second->getBody().checkCollision(returnLists[i].rect))
					{
						EnemyIt->second->onCollision(returnLists[i]);
					}
				}

			}


			for (std::map < int, ObjectSprite* > ::iterator objectIt = objectMap.begin(); objectIt != objectMap.end(); objectIt++)
			{
				// if  cho phep va cham hay k 

					CollisionRectF r = objectIt->second->getCollisionRect();
					if (EnemyIt->second->getBody().checkCollision(r.rect))
					{
						EnemyIt->second->onCollision(r);
					}
				

			}

		}


	}
#pragma endregion 

#pragma region EnemyBulletvsMap


	for (std::map < int, EnemySprite* > ::iterator EnemyIt = EnemyMap.begin(); EnemyIt != EnemyMap.end(); EnemyIt++)
	{
		if (!EnemyIt->second->isDesTroyed()) {
			vector<BulletSprite* > bullets = EnemyIt->second->getBullets();
			for (int i = 0; i < bullets.size(); i++) {
				std::vector < CollisionRectF > returnLists;


				mapCollisionGrid->getObjectlist(returnLists, bullets[i]->getBody(), camRect);
				for (int j = 0; j < returnLists.size(); j++)
				{
					if (bullets[i]->getBody().checkCollision(returnLists[j].rect))
					{
						if (!bullets[i]->isDesTroyed()) {
							bullets[i]->onCollision(returnLists[j]);
						}
					}
				}
			}
		}
	
	}


#pragma endregion 

#pragma region ObjectvsMap

	//obj vs obj
	//có 4tree
	
	for (std::map < int, ObjectSprite* > ::iterator objectIt = objectMap.begin(); objectIt != objectMap.end(); objectIt++)
	{
		std::vector < CollisionRectF > objectCollisionReturnList;

		mapCollisionGrid->getObjectlist(objectCollisionReturnList, objectIt->second->getBody(), camRect);

		for (int i = 0; i < objectCollisionReturnList.size(); i++)
		{
			CollisionRectF cRect = objectCollisionReturnList[i];
			if (objectIt->second->getBody().checkCollision(cRect.rect))
			{
				objectIt->second->onCollision(cRect);
			}
		}

	}


#pragma endregion 

	RectF cameraRect = cam->getRect();

#pragma region EnemyObjectvsCamera

	for (std::map < int, EnemySprite* > ::iterator it = EnemyMap.begin(); it != EnemyMap.end(); it++)
	{
		it->second->onCameraCollision(cameraRect);
	}
	for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); it++)
	{
		it->second->onCameraCollision(cameraRect);
	}

#pragma endregion 

	//// update through rect list of Enemy
	//for (std::map < int, EnemySprite* > ::iterator it = EnemyMap.begin(); it != EnemyMap.end(); it++)
	//{
	//	it->second->updateThroughRect();
	//}
	//// update through rect list of object
	//for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); it++)
	//{
	//	it->second->updateThroughRect();
	//}
}

void Map::onCollisionvsPlayer(MegamanSprite* sprite, Camera* cam)
{
	
#pragma region mapvsPlayer


	// player vs Collision Rect
	std::vector < CollisionRectF > returnList;
	
	RectF camRect = RectF( cam->getX(), cam->getY(), cam->getWidth(), cam->getHeight() );
	mapCollisionGrid->getObjectlist(returnList, sprite->getBody(), camRect);


	for (int i = 0; i < returnList.size(); i++)
	{
		std::vector < CollisionRectF > throughRectVector = sprite->getThroughRect();
		if (std::find(throughRectVector.begin(), throughRectVector.end(), returnList[i]) == throughRectVector.end())
		{
			if (sprite->getBody().checkCollision(returnList[i].rect))
			{  
				sprite->onCollision(returnList[i]);
			}
			
		}

	}

	// player vs object 


	for (std::map < int, ObjectSprite* > ::iterator objectIt = objectMap.begin(); objectIt != objectMap.end(); objectIt++)
	{
		if (objectIt->second->isPlayerCollisionable())
		{
			CollisionRectF* r = objectIt->second->getRefCollisionRect();
			
			std::vector < CollisionRectF* > throughRectVector = sprite->getDynamicThroughRect();
			int size = 0;
			size = throughRectVector.size();
			if (std::find(throughRectVector.begin(), throughRectVector.end(), r) == throughRectVector.end())
			{ 
				if (sprite->getBody().checkCollision(r->rect))
				{
					sprite->onDynamicObjectCollision(r);
					CollisionRectF cRect = CollisionRectF(sprite->getBody(), "Megaman");
   			  	objectIt->second->onCollision(cRect);
					// Xét nhặt item here
				}
			}
		}

	}



#pragma endregion 


#pragma region EnemyvsPlayer
	for (std::map < int, EnemySprite* > ::iterator it = EnemyMap.begin(); it != EnemyMap.end(); it++)
	{
		if (!it->second->isDesTroyed()) {
			RectF r = it->second->getBody();
			if (sprite->isHittable() && r.checkCollision(sprite->getBody()) && !it->second->isThroughable())
			{
				if (!sprite->isUndying())
				{
					if (it->second->isHittable())
						UIComponents::getInstance()->descreaseMegamanHp();
					sprite->damaged();
				}
			}

		}
		
	}
#pragma endregion 


#pragma region EnemyBulletvsPlayer

	for (std::map < int, EnemySprite* > ::iterator EnemyIt = EnemyMap.begin(); EnemyIt != EnemyMap.end(); EnemyIt++)
	{
		if (!EnemyIt->second->isDesTroyed()) {
			vector<BulletSprite* > bullets = EnemyIt->second->getBullets();
			for (int i = 0; i < bullets.size(); i++) {
				if (sprite->isHittable() && bullets[i]->getBody().checkCollision(sprite->getBody()))
				{
					bullets[i]->destroy();
					sprite->damaged();
					break;
				}
			}
		}
		
	}
#pragma endregion 

#pragma region playerBulletvsEnemy

	std::vector < BulletSprite* >& bullets = sprite->getBullets();
	for (int bulletIt = 0; bulletIt < bullets.size(); bulletIt++)
	{
		if (!bullets[bulletIt]->isDesTroyed()) {
			for (std::map < int, EnemySprite* > ::iterator EnemyIt = EnemyMap.begin(); EnemyIt != EnemyMap.end(); EnemyIt++)
			{
				if (!EnemyIt->second->isDesTroyed()) {
					BulletSprite* tempB = bullets[bulletIt];
					EnemySprite* tempE = EnemyIt->second;
					RectF rB = tempB->getBody();
					RectF rE = tempE->getBody();
					if (rE.checkCollision(rB) && EnemyIt->second->isHittable())
					{
						//sát thương gây ra bởi đạn luôn = 1
						tempE->beShooted(1);
						CollisionRectF cRect = CollisionRectF(rE, "enemy");
						tempB->onCollision(cRect);
						break;
					}
				}

			}
		}
		
	}


#pragma endregion 

#pragma region playerBulletvsObjetSprite

	/*for (int bulletIt = 0; bulletIt < bullets.size(); bulletIt++)
	{
		for (std::map < int, ObjectSprite* > ::iterator objectIt = objectMap.begin(); objectIt != objectMap.end(); objectIt++)
		{
			BulletSprite* tempB = bullets[bulletIt];
			ObjectSprite* tempE = objectIt->second;
			RectF rB = tempB->getBody();
			RectF rE = tempE->getBody();
			if (rE.checkCollision(rB) && objectIt->second->isHittable())
			{
				tempE->beShooted(sprite->getDamage());
				tempB->die();
				break;
			}
		}
	}*/

#pragma endregion  

	RectF cameraRect = cam->getRect();

#pragma region playervsCamera
	//sprite->onCameraCollision(cameraRect);
#pragma endregion 


	// update through rect list of player
	sprite->updateThroughRect();
}



void Map::onSupportPlayer(MegamanSprite* sprite)
{

#pragma region mapvsPlayer

	//// player vs CollisionRects
	//RectF r = sprite->getBody();
	////r.height += 1;
	//r.y += r.height;
	//r.height = 1;
	//std::vector < CollisionRectF > returnList;
	//mapCollisionTree->getObjectlist(returnList, r);

	//bool isSupported = false;
	//for (int i = 0; i < returnList.size(); i++)
	//{
	//	if (r.checkCollision(returnList[i].rect))
	//	{
	//		sprite->setSupportCollisionRect(returnList[i]);
	//		isSupported = true;
	//		break;
	//	}

	//}
	//// player vs object Map
	//if (!isSupported)
	//{
	//	/*for (std::map < int, ObjectSprite* > ::iterator objectIt = objectMap.begin(); objectIt != objectMap.end(); objectIt++)
	//	{
	//		if (objectIt->second->isPlayerCollisionable())
	//		{
	//			CollisionRectF* collisionRect = objectIt->second->getRefCollisionRect();
	//			if (r.checkCollision(collisionRect->rect))
	//			{

	//				if (objectIt->second->isAffectble())
	//					sprite->setSupportCollisionRect(collisionRect);
	//				isSupported = true;
	//				break;
	//			}
	//		}

	//	}*/
	//}


	//if (!isSupported)
	//{
	//	sprite->onUnsupported();
	//	sprite->setSupportCollisionRect(CollisionRectF());
	//	sprite->setSupportCollisionRect(NULL);
	//}

#pragma endregion 



}

void Map::onSupportSprite()
{
	//mapCollisionGrid->clear();
	//for (int i = 0; i < collisionRectFs.size(); i++)
	//{
	//	mapCollisionGrid->insert(collisionRectFs[i]);
	//}

#pragma region EnemyvsMap


	/*for (std::map < int, EnemySprite* > ::iterator EnemyIt = EnemyMap.begin(); EnemyIt != EnemyMap.end(); EnemyIt++)
	{
		RectF r = EnemyIt->second->getBody();
		r.y += r.height;
		r.height = 1;
		std::vector < CollisionRectF > returnLists;
		mapCollisionTree->getObjectlist(returnLists, EnemyIt->second->getBody());

		bool isSupported = false;

		for (int i = 0; i < returnLists.size(); i++)
		{

			if (r.checkCollision(returnLists[i].rect))
			{
				EnemyIt->second->setSupportCollisionRect(returnLists[i]);
				isSupported = true;
				break;
			}

		}

		if (!isSupported)
		{
			for (std::map < int, ObjectSprite* > ::iterator objectIt = objectMap.begin(); objectIt != objectMap.end(); objectIt++)
			{
				if (objectIt->second->isEnemyCollisionable())
				{
					CollisionRectF collisionRect = objectIt->second->getCollisionRect();
					if (r.checkCollision(collisionRect.rect))
					{

						if (objectIt->second->isAffectble())
						{
							EnemyIt->second->setSupportCollisionRect(collisionRect);
							isSupported = true;
							break;
						}
					}
				}

			}
		}



		if (!isSupported)
		{
			EnemyIt->second->onUnsupported();
			EnemyIt->second->setSupportCollisionRect(CollisionRectF());
		}


	}
*/
#pragma endregion 
}


void Map::onUpdatePlayerProperties(MegamanSprite* sprite, Camera* cam)
{
	cleanPlayerBullet(cam, sprite);

	UIComponents::getInstance()->setMegamanX(sprite->getCenterX());
	UIComponents::getInstance()->setMegamanY(sprite->getCenterY());
	// update Enemy
	for (std::map < int, EnemySprite* > ::iterator it = EnemyMap.begin(); it != EnemyMap.end(); it++)
	{
		it->second->setPlayerProperties(sprite->getCenterX(), sprite->getCenterY(), sprite->isDead());

	}
	// update obj
	for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); it++)
	{
		it->second->setPlayerProperties(sprite->getCenterX(), sprite->getCenterY());
	}
}

void Map::onUpdate(Camera* cam)
{

	for (int i = 0; i < tileSets.size(); i++)
	{
		tileSets[i]->update();
	}



	//cleanMap(cam);
	addEToMap(cam);



	// update Enemy
	for (std::map < int, EnemySprite* > ::iterator it = EnemyMap.begin(); it != EnemyMap.end(); it++)
	{
		
		if (!it->second->isDesTroyed()) {
			it->second->update();
		}
	}


	for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); it++)
	{
		it->second->update();
	}

}

float Map::getResX()
{
	return respawnX;
}
float Map::getResY()
{
	return respawnY;
}

RectF Map::getCameraTranslatePoint()
{
	return cameraTranslatePosition;
}

std::vector < std::string>&  Map::getSpriteNames()
{
	return spriteNames;
}

bool Map::isFinish()
{
	return bIsFinish;
}
#pragma endregion publicFunction


