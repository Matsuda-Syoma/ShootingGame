#pragma once
#include "common.h"
// 座標x、座標y、生成フレーム

class EnemySpawn
{
public:
	EnemySpawn();
	~EnemySpawn();

private:

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
};