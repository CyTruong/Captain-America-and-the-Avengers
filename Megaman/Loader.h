//#pragma once
//#include <map>
//#include "SingleGunSprite.h"
//#include "MegamanSprite.h"
//
//class Loader
//{
//private:
//
//	static Loader* sInstance;
//	std::vector<std::string > spriteNamesLoaded;
//	std::map< std::string, TextureArray**> arrayMap;
//public:
//	Loader();
//	static Loader* getInstance();
//	void loadResources(std::string name);
//	void operator()(std::vector< std::string> spriteNames, int& loaded)
//	{
//		for (int i = 0; i < spriteNames.size(); i++)
//		{
//			loadResources(spriteNames[i]);
//			loaded = i + 1;
//		}
//	}
//	~Loader();
//};
//
