#include "Enemy.h"
#include "GameMain.h"
Enemy::Enemy(float _x, float _y, float _speed, int _bspeed, float _angle,int _score, int _bcount,int _hp, int _sframe)
{
	name = 'e';
	radius = 10;
	location.x = _x;
	location.y = _y;
	speed = _speed;
	angle = (_angle * (float)M_PI * 2) / 360;
	point = _score;
	ShootDelay = _sframe;
	Bcount = _bcount;
	Bspeed = _bspeed;
	hp = _hp;
	ShootFrame = _sframe;
}

Enemy::~Enemy()
{
	delete weapon;
}

void Enemy::Update(GameMain* gamemain)
{
	float ShootAngleX = gamemain->GetPlayer().x - location.x;
	float ShootAngleY = gamemain->GetPlayer().y - location.y;
	float Normalize = atan2(ShootAngleX, ShootAngleY) * 180.0f / M_PI;
	if (--ShootDelay < 0) {
		weapon->Shoot(gamemain, name, this, 90 - Normalize, Bcount, Bspeed);
		ShootDelay = ShootFrame;
	}

	if ((SCREEN_WIDTH - UI_WIDTH) < location.x - radius) {
		flg = false;
	}
	if (0 > location.x + radius) {
		flg = false;
	}

	if ((SCREEN_HEIGHT) < location.y - radius) {
		flg = false;
	}
	if (-100 > location.y + radius) {
		flg = false;
	}

	moveX = (speed * cosf(angle));
	moveY = (speed * sinf(angle));
	location.x += moveX;
	location.y += moveY;
}

void Enemy::Draw(int camerashake) const
{
	DrawCircle(location.x + camerashake,location.y + camerashake,radius,0x00ff00,true);
}
void Enemy::Hit(GameMain* gamemain)
{
	--hp;
	if (hp <= 0) {
		gamemain->SpawnBoom(location.x, location.y);
		gamemain->SetScore(point);
		PlaySoundMem(Sounds::SE_Hit, DX_PLAYTYPE_BACK, true);
		SetFlg(false);
	}
}

int Enemy::GetPoint()
{
	return point;
}
