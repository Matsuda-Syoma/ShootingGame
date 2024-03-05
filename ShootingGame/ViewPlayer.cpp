#include "ViewPlayer.h"
#include "Custom.h"
ViewPlayer::ViewPlayer()
{
	name = 'p';

	radius = 3;
	speed = 5;

	location.x = 160;
	location.y = 320;
	image = LoadGraph("Resources/images/player.bmp");
}

ViewPlayer::~ViewPlayer()
{
}


void ViewPlayer::Update(Custom* custom)
{
	// フラグがたっているときの処理
	if (shootdelay > 0) {
		shootdelay--;
	}
	if (shootdelay <= 0) {
		weapon->Shoot(custom, name, this, 270, 1, 10, 4);
		//PlaySoundMem(Sounds::SE_Shoot, DX_PLAYTYPE_BACK, true);
		shootdelay = 6;		// 後でweaponから読み込むようにする
	}
}

void ViewPlayer::Draw(int camerashake) const
{
	DrawRotaGraph(location.x + camerashake, location.y + camerashake, 1.0, 0.0, image, true);
}
