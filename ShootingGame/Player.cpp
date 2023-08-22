#include "Player.h"
#include "GameMain.h"
Player::Player()
{
	*name = 'p';

	Init();

	radius = 15;
	speed = 7;

	SpawnTime = MAXSPAWNTIME;
}

Player::~Player()
{
}

void Player::Init() {
	flg = true;
	location.x = (SCREEN_WIDTH - UI_WIDTH) / 2;
	location.y = SCREEN_HEIGHT - 20;
}

void Player::Update(GameMain* gamemain)
{

	if ((SCREEN_WIDTH - UI_WIDTH) < location.x + radius) {
		location.x = (SCREEN_WIDTH - UI_WIDTH) - radius;
	}
	if (0 > location.x - radius) {
		location.x = 0 + radius;
	}
	if ((SCREEN_HEIGHT) < location.y + radius) {
		location.y = SCREEN_HEIGHT - radius;
	}
	if (-0 > location.y - radius) {
		location.y = 0 + radius;
	}
	if (flg) {
		speedX = (round(((float)PAD_INPUT::GetPadThumbLX() / 32767) * 100) / 100) * speed;
		speedY = (round(((float)PAD_INPUT::GetPadThumbLY() / 32767) * 100) / 100) * speed;

		if (shootdelay > 0) {
			shootdelay--;
		}
		if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_A) && shootdelay <= 0 || PAD_INPUT::GetNowKey(XINPUT_BUTTON_B) && shootdelay <= 0) {
			weapon->Shoot(gamemain, name, this,270);
			PlaySoundMem(Sounds::SE_Shoot, DX_PLAYTYPE_BACK, true);
			shootdelay = 6;		// å„Ç≈weaponÇ©ÇÁì«Ç›çûÇﬁÇÊÇ§Ç…Ç∑ÇÈ
		}
		if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_B)) {
			speedX /= 2;
			speedY /= 2;
		}

		location.x += speedX;
		location.y += speedY;
	}
	else {
		if (--SpawnTime < 0) {
			if (gamemain->GetPlayerLife() > 0) {
				Init();
				gamemain->SetPlayerLife(-1);
				SpawnTime = MAXSPAWNTIME;
			}
			else {
				gamemain->GameOver();
			}
		}
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

void Player::SetScore(int _score)
{
	Score += _score;
}

