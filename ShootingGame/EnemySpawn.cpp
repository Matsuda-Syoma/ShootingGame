#include "EnemySpawn.h"
#include "DxLib.h"

ENEMYDATA EnemySpawn::data[63];
int EnemySpawn::row;

// コンストラクタ
EnemySpawn::EnemySpawn()
{
	int fp;
	char buf[100];
	char c;
	int col = 1;	// csvファイルの列
	row = 0;		// csvファイルの行
	int count = 0;

	memset(buf, 0, sizeof(buf));

	// ファイルのロード
	fp = FileRead_open("Resources/EnemyData.csv");

	// 1行目を無視する
	while (FileRead_getc(fp) != '\n');

	// データの読み込み
	while (1) {
		while (1) {

			// ファイルの1文字を取得、文字列にする
			c = FileRead_getc(fp);
			buf[count] = c;

			// カンマ、改行、EOFならループを抜ける
			if (c == ',' || c == '\n' || c == EOF) {
				buf[count] = '\0';
				break;
			}
			count++;
		}

		// 列の位置で数値を入れる
		switch (col) {

			// X座標
		case 1:	
			data[row].x = atoi(buf);
			break;

			// Y座標
		case 2: 
			data[row].y = atoi(buf);
			break;

			// 角度
		case 3:
			data[row].angle = atoi(buf);
			break;

			// 敵スピード
		case 4: 
			data[row].speed = atoi(buf);
			break;

			// HP
		case 5:
			data[row].hp = atoi(buf);
			break;

			// スコア
		case 6:
			data[row].score = atoi(buf);
			break;

			// 出現タイミング
		case 7:
			data[row].SpawnTime = atoi(buf);
			break;

			// 止まるタイミング
		case 8:
			data[row].stopframe = atoi(buf);
			break;

			// 弾スピード
		case 9:
			data[row].Bspeed = atoi(buf);
			break;

			// 弾数
		case 10:
			data[row].Bcount = atoi(buf);
			break;

			// 発射タイミング
		case 11:
			data[row].shootframe = atoi(buf);
			break;

			// 弾の大きさ
		case 12:
			data[row].Bsize = atoi(buf);
			break;

		}

		memset(buf, 0, sizeof(buf));

		// EOFならoutに飛ぶ
		if (c == EOF) {
			goto out;
		}

		// EOF通らなかったなら読み込む位置を初期化して次の列を読む
		count = 0;
		col++;

		// 改行なら次の行に行く
		if (c == '\n') {
				col = 1;
				++row;
		}
	}
out:
	FileRead_close(fp);
}


EnemySpawn::~EnemySpawn()
{

}

// 敵情報の読み込み
ENEMYDATA EnemySpawn::LoadEnemy(int i)
{
	return data[i];
}

// 読み込まれた敵の量の取得
int EnemySpawn::GetMaxEnemy()
{
	return row;
}
