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

	if ((SCREEN_WIDTH - UI_WIDTH) < location.x + radius) {
		location.x = (SCREEN_WIDTH - UI_WIDTH) - radius;
	}
	if (0 > location.x - radius) {
		location.x = 0 + radius;
	}
	if (flg) {
		speedX = (round(((float)PAD_INPUT::GetPadThumbLX() / 32767) * 100) / 100) * speed;
		speedY = (round(((float)PAD_INPUT::GetPadThumbLY() / 32767) * 100) / 100) * speed;

		if (shootdelay > 0) {
			shootdelay--;
		}
		if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_A) && shootdelay <= 0 || PAD_INPUT::GetNowKey(XINPUT_BUTTON_B) && shootdelay <= 0) {
			weapon->Shoot(gamemain, name, this);
			PlaySoundMem(Sounds::SE_Shoot, DX_PLAYTYPE_BACK, true);
			shootdelay = 6;		// Œã‚Åweapon‚©‚ç“Ç‚Ýž‚Þ‚æ‚¤‚É‚·‚é
		}
		if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_B)) {
			speedX /= 2;
			speedY /= 2;
		}

		location.x += speedX;
		location.y += speedY;
	}
	else {

	}
}

void Player::Draw() const
{
	if (flg) {
		DrawCircle(location.x, location.y, radius, 0xffffff, true);
	}
}

void Player::Hit(GameMain* gamemain)
{
	gamemain->SpawnBoom(location.x, location.y);
	SetFlg(false);
	WaitTimer(250);
	PlaySoundMem(Sounds::SE_PlayerHit, DX_PLAYTYPE_BACK, true);
}

int Player::GetScore()
{
	return Score;
}
