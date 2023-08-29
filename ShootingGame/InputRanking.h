#pragma once
#include "DxLib.h"
#include "common.h"
#include "AbstractScene.h"

#define MOZI_ALPHA 88

class InputRanking : public AbstractScene
{
private:
	int MoziSelectCol;		// ��
	int MoziSelectRow;		// �s
	int MoziSize;
	char MoziFrame[11];
	char MoziWork[2];
public:
	InputRanking();
	AbstractScene* Update() override;				// �`��ȊO�̍X�V�����s
	void Draw() const override;						// �`��Ɋւ��邱�Ƃ�����
};

