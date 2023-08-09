#include "Player.h"
#include "GameMain.h"
Player::Player()
{
	*name = 'p';
	location.x = SCREEN_WIDTH / 2;
	location.y = SCREEN_HEIGHT - 20;

	radius = 15;
	speed = 7;
}

Player::~Player()
{
}

void Player::Update(GameMain* gamemain)
{
	speedX = (round(((float)PAD_INPUT::GetPadThumbLX() / 32767) * 100) / 100) * speed;
	speedY = (round(((float)PAD_INPUT::GetPadThumbLY() / 32767) * 100) / 100) * speed;

	location.x += speedX;
	location.y += speedY;
	if (shootdelay > 0) {
		shootdelay--;
	}
	if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_A) && shootdelay <= 0) {
		weapon->Shoot(gamemain,name);
		shootdelay = 5;		// å„Ç≈weaponÇ©ÇÁì«Ç›çûÇﬁÇÊÇ§Ç…Ç∑ÇÈ
	}
}

void Player::Draw() const
{
	DrawCircle(location.x, location.y, radius, 0x8888ff, true);
}

void Player::Hit()
{
}
