#pragma once
#include "AbstractScene.h"
#include "common.h"
#include "Ranking.h"
class DrawRanking : public AbstractScene
{
public:
	DrawRanking();
	AbstractScene* Update() override;				// �`��ȊO�̍X�V�����s
	void Draw() const override;						// �`��Ɋւ��邱�Ƃ�����
};

