#pragma once

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define SCREEN_COLORBIT 32

#define UI_WIDTH 240

#define FRAMERATE 60.0			//フレームレート
#define UPDATETIME 800

#define BULLET_MAX 127
#define ENEMY_MAX 30

struct ENEMYDATA
{
	int x;
	int y;
	int SpawnTime;
	int angle;
	int speed;
	int Bspeed;
	int hp;
};