#pragma once
#include "Object.h"
#include "define.h"
#include <vector>
#include "UI.h"

class  GridNode
{
public:
	vector<Object*> arrObj;
	vector< CollisionRectF> arrCollisionRecF;
};
class Grid {
private:
	int nodeWidth, nodeHeight;
	int gameWidth, gameHeight;
	GridNode** Nodes;
	int hang, cot;

public:
	Grid() {

		//hcmt 
		if (UIComponents::getInstance()->getMegamanX() > 126 * 16)
		{
			gameHeight = 16*16;
			gameWidth = 16*16;

		}
		else
		{
			gameHeight = 480;
			gameWidth = 128 * 16;
		}
		nodeWidth = SCREEN_WIDTH / 2;
		nodeHeight = SCREEN_HEIGHT / 2;
		hang = gameHeight / nodeHeight + 1;
		cot = gameWidth / nodeWidth + 1;
		Nodes = new GridNode*[hang + 1];
		for (int i = 0; i <= hang; i++) {
			Nodes[i] = new GridNode[cot + 1];
		}

	}
	void insert(CollisionRectF collisionRe) {
		int PosX = collisionRe.rect.x / nodeWidth;
		int PosY = collisionRe.rect.y / nodeHeight;
		int posXW = (collisionRe.rect.x + collisionRe.rect.width) / nodeWidth;
		int posYH = (collisionRe.rect.y + collisionRe.rect.height) / nodeHeight;
		for (int i = PosY; i <= posYH; i++) {
			for (int j = PosX; j <= posXW; j++) {
				Nodes[i][j].arrCollisionRecF.push_back(collisionRe);
			}
		}
	}
	void insert(Object *obj) {
		int PosX = obj->body.x / nodeWidth;
		int PosY = obj->body.y / nodeHeight;
		int posXW = (obj->body.x + obj->body.width) / nodeWidth;
		int posYH = (obj->body.y + obj->body.height) / nodeHeight;
		for (int i = PosY; i <= posYH; i++) {
			for (int j = PosX; j <= posXW; j++) {
				Nodes[i][j].arrObj.push_back(obj);
			}
		}
	}

	void clear() {

	}
	void getObjectlist(std::vector < Object* >& returnList, RectF camRect)
	{
		int posX = camRect.x / nodeWidth;
		int posY = camRect.y / nodeHeight;
		int posX2 = (camRect.x + camRect.width) / nodeWidth;
		int posY2 = (camRect.y + camRect.height) / nodeHeight;
		for (int i = posY; i <= posY2; i++) {
			for (int j = posX; j <= posX2; j++) {
				for (int k = 0; k < Nodes[i][j].arrObj.size(); k++) {
					returnList.push_back(Nodes[i][j].arrObj[k]);
				}
			}
		}

	}

	void getObjectlist(std::vector < CollisionRectF >& returnList, RectF object, RectF camRect)
	{

		int posX = object.x / nodeWidth;
		int posY = object.y / nodeHeight;
		int posX2 = (object.x + object.width) / nodeWidth;
		int posY2 = (object.y + object.height) / nodeHeight;
		for (int i = posY; i <= posY2; i++) {
			for (int j = posX; j <= posX2; j++) {
				for (int k = 0; k < Nodes[i][j].arrCollisionRecF.size(); k++) {
					if (Nodes[i][j].arrCollisionRecF[k].rect.checkCollision(camRect)) {
						returnList.push_back(Nodes[i][j].arrCollisionRecF[k]);
					}
				}
			}
		}

	}


};