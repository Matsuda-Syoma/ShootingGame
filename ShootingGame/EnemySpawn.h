#pragma once
#include "common.h"
// 座標x、座標y、生成フレーム

class EnemySpawn
{
private:

	static ENEMYDATA data[63];
	static int row;
public:
	EnemySpawn();
	~EnemySpawn();
	static ENEMYDATA LoadEnemy(int i);
	static int GetMaxEnemy();
};