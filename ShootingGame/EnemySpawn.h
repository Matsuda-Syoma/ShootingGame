#pragma once
#include "common.h"
// ���Wx�A���Wy�A�����t���[��

class EnemySpawn
{
private:

	static ENEMYDATA data[63];
public:
	int row = 0;
	EnemySpawn();
	~EnemySpawn();
	static ENEMYDATA LoadEnemy(int i);
};