#pragma once
#include "common.h"
#include "DxLib.h"

#define RANKING_DATA	5
#define NAME_MAX		10

//ç\ë¢ëÃ
struct RANKINGDATA {
	int		no;
	char	name[10];
	long	score;
};

class Ranking
{
private:
	static RANKINGDATA gRanking[RANKING_DATA];

public:
	Ranking();
	~Ranking();

	static void SortRanking(void);

	static void SaveRanking(void);

	static void ReadRanking(void);

	static void Insert(int score, char name[11]);

	static RANKINGDATA GetData(int i);
};

