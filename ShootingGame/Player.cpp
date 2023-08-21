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
	if (flg) {
		speedX = (round(((float)PAD_INPUT::GetPadThumbLX() / 32767) * 100) / 100) * speed;
		speedY = (round(((float)PAD_INPUT::GetPadThumbLY() / 32767) * 100) / 100) * speed;

		location.x += speedX;
		location.y += speedY;
		if (shootdelay > 0) {
			shootdelay--;
		}
		if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_A) && shootdelay <= 0) {
			weapon->Shoot(gamemain, name);
			PlaySoundMem(Sounds::SE_Shoot, DX_PLAYTYPE_BACK, true);
			shootdelay = 2;		// ���weapon����ǂݍ��ނ悤�ɂ���
		}
	}
}

void Player::Draw() const
{
	if (flg) {
		DrawCircle(location.x, location.y, radius, 0xffffff, true);
	}
}

void Player::Hit()
{
}
