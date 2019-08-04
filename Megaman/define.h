#pragma once
#include "LogWriter.h"

#define FPS 60
#define MSPF 1000.0f/ 60
#define SCREEN_HEIGHT 256	
#define SCREEN_WIDTH 256
#define RESOURCE_SPRITE "Resource\\Sprite\\"
#define TILE_SIZE 16
#define VIEWPORT_SIZE 256 


#define MEGAMANRUNSPEED 3
#define SINGLEGUNRUNSPEED 1.25

#define MEGAMAN_CHARGE_LIMIT_N 20
#define MEGAMAN_CHARGE_LIMIT_S 60
#define MEGAMAN_CHARGE_LIMIT_M 80
#define MEGAMAN_CHARGE_LIMIT_L 110

#define FIRE_COUNTING_FRAME 10
// TileSet 
#define nColumnsOfTileset 16 


// map1 
#define NUMBER_COLUMM_MAP1 128
#define NUMBER_ROW_MAP1 30
#define START_MAP1_POINT_X 0
#define START_MAP1_POINT_Y 224
// bossMap1

#define NUMBER_COLUMM_BOSSMAP1 16
#define NUMBER_ROW_BOSSMAP1 16
#define START_BOSSMAP1_POINT_X 0
#define START_BOSSMAP1_POINT_Y 0 



enum BulletTypes
{
	SHEILD,
	KICK,
	PUNCH
};

enum BulletSize
{
	SMALL,
	MEDIUM,
	LARGE
};


#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#define M_E        2.71828182845904523536   // e
#define M_LOG2E    1.44269504088896340736   // log2(e)
#define M_LOG10E   0.434294481903251827651  // log10(e)
#define M_LN2      0.693147180559945309417  // ln(2)
#define M_LN10     2.30258509299404568402   // ln(10)
#define M_PI       3.14159265358979323846   // pi
#define M_PI_2     1.57079632679489661923   // pi/2
#define M_PI_4     0.785398163397448309616  // pi/4
#define M_1_PI     0.318309886183790671538  // 1/pi
#define M_2_PI     0.636619772367581343076  // 2/pi
#define M_2_SQRTPI 1.12837916709551257390   // 2/sqrt(pi)
#define M_SQRT2    1.41421356237309504880   // sqrt(2)
#define M_SQRT1_2  0.707106781186547524401  // 1/sqrt(2)