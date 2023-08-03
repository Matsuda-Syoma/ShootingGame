#include "Bullet.h"

Bullet::Bullet()
{
	location.x = SCREEN_WIDTH / 2;
	location.y = SCREEN_HEIGHT / 2;
	radius = 10;
	damage = 1;
	speed = 1;
	angle = 0;
	acceleration = 0;
	angleVelocity = 0;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	angle = 0.25 * (float)M_PI * 2;
	moveX = (speed * cosf(angle));
	moveY = (speed * sinf(angle));
	location.x += moveX;
	location.y += moveY;

}

void Bullet::Draw() const
{
	DrawCircle(location.x, location.y, radius, 0xffffff, true);
}

void Bullet::GetDamage()
{
}
