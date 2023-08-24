#include "Player.h"
#include "GameMain.h"
Player::Player()
{
	name = 'p';

	Init();

	radius = 5;
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

	// 画面外に出ないようにする
	if ((SCREEN_WIDTH - UI_WIDTH) < location.x + radius) {
		location.x = (SCREEN_WIDTH - UI_WIDTH) - (float)radius;
	}
	if (0 > location.x - radius) {
		location.x = 0 + (float)radius;
	}
	if ((SCREEN_HEIGHT) < location.y + radius) {
		location.y = SCREEN_HEIGHT - (float)radius;
	}
	if (-0 > location.y - radius) {
		location.y = 0 + (float)radius;
	}

	// フラグがたっているときの処理
	if (flg) {
		speedX = (round(((float)PAD_INPUT::GetPadThumbLX() / 32767) * 100) / 100) * speed;
		speedY = (round(((float)PAD_INPUT::GetPadThumbLY() / 32767) * 100) / 100) * speed;

		if (shootdelay > 0) {
			shootdelay--;
		}
		if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_A) && shootdelay <= 0 || PAD_INPUT::GetNowKey(XINPUT_BUTTON_B) && shootdelay <= 0) {
			weapon->Shoot(gamemain, name, this, 270, 1, 10);
			PlaySoundMem(Sounds::SE_Shoot, DX_PLAYTYPE_BACK, true);
			shootdelay = 6;		// 後でweaponから読み込むようにする
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
			if (gamemain->GetPlayerLife() >= 0) {
				Init();
				gamemain->SetPlayerLife(-1);
				gamemain->SpawnCircle(location.x, location.y, 20);
				SpawnTime = MAXSPAWNTIME;
			}
			else {
				gamemain->GameOver();
			}
		}
	}
}

void Player::Draw(int camerashake) const
{
	if (flg) {
		DrawCircle(location.x + camerashake, location.y + camerashake, radius, 0xffffff, true);
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

