#pragma once
#include "common.h"
// ���Wx�A���Wy�A�����t���[��

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