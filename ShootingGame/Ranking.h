#pragma once
#include "common.h"
//�\����
struct RANKINGDATA {
	int		no;
	char	name[11];
	long	score;
};
class Ranking
{
public:
	Ranking();
	~Ranking();

	void SortRanking(void);

};

