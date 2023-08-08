#include "Enemy.h"

Enemy::Enemy()
{
	radius = 5;
	location.x = 100;
	location.y = 100;
}

Enemy::~Enemy()
{
}

void Enemy::Update(GameMain* gamemain)
{
}

void Enemy::Draw() const
{
	DrawCircle(location.x,location.y,radius,0x00ff00,true);
}
void Enemy::Hit()
{
}
