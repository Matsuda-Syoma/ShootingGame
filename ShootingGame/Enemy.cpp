#include "Enemy.h"

Enemy::Enemy()
{
	*name = 'e';
	radius = 10;
	location.x = 100;
	location.y = 100;
}

Enemy::~Enemy()
{
}

void Enemy::Update(GameMain* gamemain)
{
	location.y += 1;
}

void Enemy::Draw() const
{
	DrawCircle(location.x,location.y,radius,0x00ff00,true);
}
void Enemy::Hit()
{
	flg = false;
}
