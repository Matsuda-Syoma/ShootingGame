#pragma once
#include"DxLib.h"
#include"common.h"
#include"AbstractScene.h"
#include"PAD_INPUT.h"
class Title : public AbstractScene
{
private:
	int Select;
	bool Once = TRUE;
public:
	Title();
	AbstractScene* Update() override;				// �`��ȊO�̍X�V�����s
	void Draw() const override;						// �`��Ɋւ��邱�Ƃ�����
};

