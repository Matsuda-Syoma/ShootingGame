#include "Ranking.h"

RANKINGDATA gRanking[RANKING_DATA];

Ranking::Ranking()
{
}

Ranking::~Ranking()
{
}

void Ranking::SortRanking(void)
{
	int i, j;
	RANKINGDATA work;

	// 選択法ソート
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (gRanking[i].score <= gRanking[j].score) {
				work = gRanking[i];
				gRanking[i] = gRanking[j];
				gRanking[j] = work;
			}
		}
	}

	// 順位付け
	for (i = 0; i < RANKING_DATA; i++) {
		gRanking[i].no = 1;
	}
	// 得点が同じ場合は、同じ順位とする
	// 同順位があった場合の次の順位はデータ個数が加算された順位とする
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (gRanking[i].score > gRanking[j].score) {
				gRanking[j].no++;
			}
		}
	}
}

int  SaveRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	// ファイルオープン
	if ((fp = fopen("data/rankingdata.txt", "w")) == NULL) {
		/* エラー処理 */
		printf("Ranking Data Error\n");
		return -1;
	}

	// ランキングデータ分配列データを書き込む
	for (int i = 0; i < RANKING_DATA; i++) {
		fprintf(fp, "%2d %10s %10d\n", gRanking[i].no, gRanking[i].name, gRanking[i].score);
	}

	//ファイルクローズ
	fclose(fp);
	return 0;

}