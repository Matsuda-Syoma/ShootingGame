#include "Enemy.h"
#include "GameMain.h"
Enemy::Enemy(float _x, float _y, float _speed,float _angle,int _score)
{
	*name = 'e';
	radius = 10;
	location.x = _x;
	location.y = _y;
	speed = _speed;
	angle = (_angle * (float)M_PI * 2) / 360;
	point = _score;
}

Enemy::~Enemy()
{
}

void Enemy::Update(GameMain* gamemain)
{

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

void Enemy::Draw() const
{
	DrawCircle(location.x,location.y,radius,0x00ff00,true);
}
void Enemy::Hit(GameMain* gamemain)
{
	gamemain->SpawnBoom(location.x,location.y);
	PlaySoundMem(Sounds::SE_Hit, DX_PLAYTYPE_BACK, true);
	SetFlg(false);
}

int Enemy::GetPoint()
{
	return point;
}
