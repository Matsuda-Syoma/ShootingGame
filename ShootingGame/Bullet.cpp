#include "Bullet.h"

Bullet::Bullet()
{
	location.x = SCREEN_WIDTH / 2;
	location.y = SCREEN_HEIGHT / 2;
	radius = 10;
	damage = 1;
	speed = 1;
	angle = (0 * (float)M_PI * 2);
	acceleration = 0;
	angleVelocity = 0;
}

Bullet::~Bullet()
{
}

bool Bullet::Update()
{
	angle += angleVelocity;
	moveX = (speed * cosf(angle));
	moveY = (speed * sinf(angle));
	location.x += moveX;
	location.y += moveY;

	if (location.x < 0) {
		return false;
	}
	if (location.x > SCREEN_WIDTH) {
		return false;
	}
	if (location.y < 0) {
		return false;
	}
	if (location.y > SCREEN_HEIGHT) {
		return false;
	}
	return true;
}

void Bullet::Draw() const
{
	DrawCircle(location.x, location.y, radius, 0xffffff, true);
}

void Bullet::GetDamage()
{
}
