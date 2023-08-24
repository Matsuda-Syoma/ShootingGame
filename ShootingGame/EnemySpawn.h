#pragma once
#include "common.h"

class EnemySpawn
{
private:

	static ENEMYDATA data[63];			// 敵の数の最大数
	static int row;						// csvファイルの列の数(読み込まれる敵の量)
public:
	EnemySpawn();						// コンストラクタ
	~EnemySpawn();						// デストラクタ
	static ENEMYDATA LoadEnemy(int i);	// 敵情報の読み込み
	static int GetMaxEnemy();			// 読み込まれた敵の量の取得
};