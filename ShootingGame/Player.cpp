#include "Player.h"

Player::Player()
{
	location.x = SCREEN_WIDTH / 2;
	location.y = SCREEN_HEIGHT - 20;

	radius = 3;
	speed = 5;
}

Player::~Player()
{
}

void Player::Update()
{
	speedX = (round(((float)PAD_INPUT::GetPadThumbLX() / 32767) * 100) / 100) * speed;
	speedY = (round(((float)PAD_INPUT::GetPadThumbLY() / 32767) * 100) / 100) * speed;

	location.x += speedX;
	location.y += speedY;
}

void Player::Draw() const
{
	DrawCircle(location.x, location.y, radius, 0x8888ff, true);
}

void Player::Hit()
{
}
