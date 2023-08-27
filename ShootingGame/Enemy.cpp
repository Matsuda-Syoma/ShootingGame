#include "Enemy.h"
#include "GameMain.h"
Enemy::Enemy(float _x, float _y, float _speed, int _bspeed, float _angle,int _score, int _bcount,int _hp, int _sframe, int _stop)
{
	name = 'e';
	radius = 10;
	location.x = _x;
	location.y = _y;
	speed = _speed;
	angle = (_angle * (float)M_PI * 2) / 360;
	point = _score;
	ShootDelay = 0;
	Bcount = _bcount;
	Bspeed = _bspeed;
	hp = _hp;
	ShootFrame = _sframe;
	StopFrame = _stop;
	HpCircle = LoadGraph("Resources/images/circle.png");
}

Enemy::~Enemy()
{
	delete weapon;
}

void Enemy::Update(GameMain* gamemain)
{

	if ((SCREEN_WIDTH - UI_WIDTH) < location.x - radius) {
		flg = false;
	}
	if (0 > location.x + radius) {
		flg = false;
	}

	if ((SCREEN_HEIGHT) < location.y - radius) {
		flg = false;
	}
	if (-100 > location.y + radius) {
		flg = false;
	}

	if (StopFrame == -1) {
		moveX = (speed * cosf(angle));
		moveY = (speed * sinf(angle));
		location.x += moveX;
		location.y += moveY;
	}
	if (StopFrame > 0) {

		StopFrame--;
		moveX = (speed * cosf(angle));
		moveY = (speed * sinf(angle));
		location.x += moveX;
		location.y += moveY;
	}

	float ShootAngleX = gamemain->GetPlayer().x - location.x;
	float ShootAngleY = gamemain->GetPlayer().y - location.y;
	float Normalize = atan2(ShootAngleX, ShootAngleY) * 180.0f / M_PI;

	// ボスのとき
	if (BossFlg) {
		if (StopFrame <= 0) {
			moveX = acceleration;
			location.x += moveX;
			if (--BossMoveCount < 0) {
				acceleration *= -1;
				BossMoveCount = BossMaxMoveCount;
			}
			// 攻撃
			if (--ShootDelay < 0) {
				weapon->Shoot(gamemain, name, this, 90 - Normalize, Bcount, Bspeed);
				ShootDelay = ShootFrame;
			}
		}
	}

	// ボスじゃないとき
	else {

		if (--ShootDelay < 0) {
			weapon->Shoot(gamemain, name, this, 90 - Normalize, Bcount, Bspeed);
			ShootDelay = ShootFrame;
		}
	}
}
float Enemy::Map(float value, float start1, float stop1, float start2, float stop2) {
	return start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
}
void Enemy::Draw(int camerashake) const
{
	DrawCircle(location.x + camerashake,location.y + camerashake,radius,0x00ff00,true);
	if (BossFlg) {
		DrawCircleGauge(location.x, location.y, 100 * ((float)hp / (float)Maxhp), HpCircle, 0, radius * 0.02);
	}
}
void Enemy::Hit(GameMain* gamemain)
{
	--hp;
	if (hp <= 0) {
		gamemain->SpawnBoom(location.x, location.y);
		gamemain->SetScore(point);
		PlaySoundMem(Sounds::SE_Hit, DX_PLAYTYPE_BACK, true);
		SetFlg(false);
	}
}

int Enemy::GetPoint()
{
	return point;
}

void Enemy::SetBossFlg(bool _flg)
{
	BossFlg = _flg;
	acceleration = 2;
	radius = 20;
	BossMaxMoveCount = 180;
	BossMoveCount = BossMaxMoveCount / 2;
	Maxhp = hp;
}
