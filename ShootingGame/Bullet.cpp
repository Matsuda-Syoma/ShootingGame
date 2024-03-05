#include "Bullet.h"

Bullet::Bullet(char _name, float _x,float _y,float _angle, int _speed, int _size)
{
	location.x = _x;
	location.y = _y;
	parent = _name;
	radius = _size;
	damage = 1;
	speed = _speed;
	angle = (_angle * (float)M_PI * 2) / 360;
	acceleration = 0;
	angleVelocity = (0 * (float)M_PI * 2) / 360;
	screenMinX = 0;
	screenMinY = 0;
	screenMaxX = SCREEN_WIDTH;
	screenMaxY = SCREEN_HEIGHT;
}

Bullet::~Bullet()
{
}

bool Bullet::Update()
{

	if (!flg) {
		return false;
	}

	angle += angleVelocity;

	// 角度に向かって移動量を指定する
	moveX = (speed * cosf(angle));
	moveY = (speed * sinf(angle));

	// 移動量分座標を動かす
	location.x += moveX;
	location.y += moveY;


	// 画面外に行ったらフラグを切る
	if (location.x < screenMinX) {
		return false;
	}
	if (location.x > screenMaxX) {
		return false;
	}
	if (location.y < screenMinY) {
		return false;
	}
	if (location.y > screenMaxY) {
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

void Bullet::SetFlg(bool _b) 
{
	flg = _b;
}
void Bullet::SetDeleteScreen(float x1, float y1, float x2, float y2)
{
	screenMinX = x1;
	screenMinY = y1;
	screenMaxX = x2;
	screenMaxY = y2;
}