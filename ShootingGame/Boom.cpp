#include "Boom.h"
#include "DxLib.h"

int Boom::Images[11];

// �R���X�g���N�^
Boom::Boom(float _x,float _y)
{
	x = _x;
	y = _y;
	ImageCnt = 0;
	ImageCntDelay = COUNTDELAY;
}

// �f�X�g���N�^
Boom::~Boom()
{
	for (int i = 0; i < 11; i++) {
		Images[i] = NULL;
	}
}

// 
bool Boom::Update()
{
	// Delay��0�ɂȂ�����摜�̕ϐ��𑝂₷
	if (--ImageCntDelay < 0) {
		ImageCnt++;
		ImageCntDelay = COUNTDELAY;
	}
	// �摜�̕ϐ���11�ȏ�ɂȂ�����t���O��؂�
	if (ImageCnt >= 11) {
		return false;
	}
	return true;
}

void Boom::Draw() const
{
	DrawRotaGraph(x, y, 1.0f, 0, Images[ImageCnt], true);
}

void Boom::LoadImages()
{
	LoadDivGraph("Resources/images/Boom.png", 11, 5, 3, 80, 80, Images);
}
