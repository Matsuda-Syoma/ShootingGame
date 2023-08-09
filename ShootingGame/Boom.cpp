#include "Boom.h"
#include "DxLib.h"

int Boom::Images[11];

Boom::Boom(float _x,float _y)
{
	x = _x;
	y = _y;
	ImageCnt = 0;
	ImageCntDelay = COUNTDELAY;
}

Boom::~Boom()
{
}

bool Boom::Update()
{
	if (--ImageCntDelay < 0) {
		ImageCnt++;
		ImageCntDelay = COUNTDELAY;
	}
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
