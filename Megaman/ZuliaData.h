#pragma once
#include "EnemyData.h"
class ZuliaData :
	public EnemyData
{
public :
	RectF Range;

public:
	enum ZuliaMechIndex {
		FLY2CORNER,
		ALPHAFLY,
		STING_PLAYER,
		BEESHOOT,
		TARGETBEESHOOT,
		MECHCOUNT
	};

	enum ZuliaAniIndex {
		NORMALFLY,
		STING,
		SHOOT,
		WINGS,
		AIM, 
		DIE,
		ANICOUNT
	};
	

public:
	ZuliaData(std::vector<BulletSprite*>& bullet);
	ZuliaData();
	~ZuliaData();
};

