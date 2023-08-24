#include "Bullet.h"

Bullet::Bullet(char _name, float _x,float _y,float _angle, int _speed)
{
	location.x = _x;
	location.y = _y;
	parent = _name;
	radius = 2;
	damage = 1;
	speed = _speed;
	angle = (_angle * (float)M_PI * 2) / 360;
	acceleration = 0;
	angleVelocity = (0 * (float)M_PI * 2) / 360;
}

Bullet::~Bullet()
{
}

bool Bullet::Update()
{

	angle += angleVelocity;

	// 角度に向かって移動量を指定する
	moveX = (speed * cosf(angle));
	moveY = (speed * sinf(angle));

	// 移動量分座標を動かす
	location.x += moveX;
	location.y += moveY;


	// 画面外に行ったらフラグを切る
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
	DrawCircle(location.x, location.y, radius - 2, 0xffffff, true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 127);
	DrawCircle(location.x, location.y, radius, 0xffffff, true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
}

void Bullet::GetDamage()
{
}

char Bullet::GetParent()
{
	return parent;
}
