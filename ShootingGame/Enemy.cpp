#include "Enemy.h"

Enemy::Enemy(float _x, float _y, float _speed,float _angle)
{
	*name = 'e';
	radius = 10;
	location.x = _x;
	location.y = _y;
	speed = _speed;
	angle = (_angle * (float)M_PI * 2) / 360;
}

Enemy::~Enemy()
{
}

void Enemy::Update(GameMain* gamemain)
{
	moveX = (speed * cosf(angle));
	moveY = (speed * sinf(angle));
	location.x += moveX;
	location.y += moveY;
}

void Enemy::Draw() const
{
	DrawCircle(location.x,location.y,radius,0x00ff00,true);
}
void Enemy::Hit()
{
	flg = false;
}
