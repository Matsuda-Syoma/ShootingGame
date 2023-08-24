#include "Boom.h"
#include "DxLib.h"

int Boom::Images[11];

// コンストラクタ
Boom::Boom(float _x,float _y)
{
	x = _x;
	y = _y;
	ImageCnt = 0;
	ImageCntDelay = COUNTDELAY;
}

// デストラクタ
Boom::~Boom()
{
	for (int i = 0; i < 11; i++) {
		Images[i] = NULL;
	}
}

// 
bool Boom::Update()
{
	// Delayが0になったら画像の変数を増やす
	if (--ImageCntDelay < 0) {
		ImageCnt++;
		ImageCntDelay = COUNTDELAY;
	}
	// 画像の変数が11以上になったらフラグを切る
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
