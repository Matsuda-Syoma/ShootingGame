#pragma once
#include "common.h"
// ���Wx�A���Wy�A�����t���[��

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