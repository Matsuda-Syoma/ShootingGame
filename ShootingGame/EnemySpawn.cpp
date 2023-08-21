#include "EnemySpawn.h"
#include "DxLib.h"

EnemySpawn::EnemySpawn()
{
	int fp;
	ENEMYDATA data[99];
	char buf[100];
	char dust[7][100];
	char c;
	int a;
	int col = 1;	// 列
	int row = 0;	// 行
	int count = 0;

	memset(buf, 0, sizeof(buf));

	fp = FileRead_open("Resources/EnemyData.csv");

	while (FileRead_getc(fp) != '\n');

	while (1) {
		while (1) {
			c = FileRead_getc(fp);
			buf[count] = c;
			//printfDx("%c", buf[count]);
			if (c != ',') {
				printfDx("%c", buf[count]);
			}
			else {
				buf[count] = '\0';
				printfDx("|");
				break;
			}
			if (c == EOF) {
				goto out;
			}
			count++;
		}
		//printfDx("%d", col);
		switch (col) {
		case 1:	data[row].x = atoi(buf); break;
		case 2: data[row].y = atoi(buf); break;
		case 3: data[row].SpawnTime = atoi(buf); break;
		case 4: data[row].angle = atoi(buf); break;
		case 5: data[row].speed = atoi(buf); break;
		case 6: data[row].Bspeed = atoi(buf); break;
		case 7: data[row].hp = atoi(buf); break;
		}
		memset(buf, 0, sizeof(buf));
		count = 0;
		col++;
		if (c == '\n') {
				col = 1;
				++row;
				printfDx("v");	
		}
	}
out:
	//printfDx("[%d][%d][%d][%d][%d][%d][%d]", data[row].x, data[row].y, data[row].SpawnTime, data[row].angle, data[row].speed, data[row].Bspeed, data[row].hp);
	FileRead_close(fp);
}

//EnemySpawn::EnemySpawn()
//{
//	FILE* fp = NULL;
//	ENEMYDATA data[7];
//	char buf[100];
//	int c = 0;
//	int a;
//	int col = 1;	// 列
//	int row = 0;	// 行
//
//	memset(buf, 0, sizeof(buf));
//	fopen_s(&fp,"Resources/EnemyData.csv", "r");
//		// ヘッダ-読み飛ばし
//
//	fgets(buf, sizeof(buf), fp);
//	//while ((a = fgetc(fp)) != EOF)
//	//{
//	//	//	読み込んだ1文字を画面に出力する
//	//	if ((a == '\n')) {
//	//		printfDx("|||");
//	//	}
//	//	printfDx("%c", a);
//	//}
//
//
//	while (c != EOF) {
//		while (1) {
//			c = fgetc(fp);
//			printfDx("%c",c);
//			// 末尾ならループを抜ける
//			if (c == EOF) {
//				goto out;
//			}
//			// カンマか改行でなければ文字としてつなげる
//			if (c != ',' && c != '\n') {
//				strcat_s(buf,sizeof(buf) - 1, (const char*)&c);
//				//printfDx("%s ", buf);
//			}
//			// カンマか改行ならループ抜ける
//			else {
//				break;
//			}
//			//ここに来たということは、1セル分の文字列が出来上がったということ
//			switch (col) {
//			case 1:	data[row].x = atof(buf); break;
//			case 2: data[row].y = atof(buf); break;
//			case 3: data[row].SpawnTime = atoi(buf); break;
//			case 4: data[row].angle = atof(buf); break;
//			case 5: data[row].speed = atof(buf); break;
//			case 6: data[row].Bspeed = atof(buf); break;
//			case 7: data[row].hp = atoi(buf); break;
//			}
//			//バッファを初期化
//			memset(buf, 0, sizeof(buf));
//			//列数を足す
//			++col;
//
//			//もし読み込んだ文字が改行だったら列数を初期化して行数を増やす
//			if (c == '\n') {
//				col = 1;
//				++row;
//			}
//		}
//	out: 
//		continue;
//	}
//	fclose(fp);
//}

EnemySpawn::~EnemySpawn()
{
}



//CONTROL::CONTROL()
//{
//	player = new PLAYER;
//
//	back = new BACK;
//
//
//
//	//敵クラス生成
//	for (int i = 0; i < ENEMY_NUM; ++i) {
//		enemy[i] = new ENEMY(data[i].type, data[i].stype, data[i].m_pattern, data[i].s_pattern, data[i].in_time, data[i].stop_time, data[i].shot_time,
//			data[i].out_time, data[i].x, data[i].y, data[i].speed, data[i].hp, data[i].item);
//	}
//
//
//}
