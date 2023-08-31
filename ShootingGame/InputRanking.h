#pragma once
#include "DxLib.h"
#include "common.h"
#include "AbstractScene.h"
#include "Ranking.h"

#define MOZI_ALPHA 88

class InputRanking : public AbstractScene
{
private:
	int Score;
	int MoziSelectCol;		// ��
	int MoziSelectRow;		// �s
	int MoziSize;
	char MoziFrame[11];
	char MoziWork[2];
public:
	InputRanking(int _score);
	AbstractScene* Update() override;				// �`��ȊO�̍X�V�����s
	void Draw() const override;						// �`��Ɋւ��邱�Ƃ�����
};

