#pragma once
#include "Graphics.h"

class MapCreator {
private: 
	static MapCreator* _instance;
	LPDIRECT3DTEXTURE9 tileSet;
public:

	static MapCreator* getInstance() {
		if (_instance == nullptr) {
			_instance = new MapCreator();
		}
		return _instance;
	};

	 void settitleset(LPDIRECT3DTEXTURE9 title) {
		 this->tileSet = title;
	}

	 void cut() {
		 D3DLOCKED_RECT RECT;
		tileSet->LockRect()
	 }


};


