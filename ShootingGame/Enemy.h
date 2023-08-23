#pragma once
#include"CharaBase.h"
#include"DxLib.h"
//#include"BulletsSpawner.h"
#include"NwaySpawner.h"
class GameMain;							// �O���錾
class Enemy : public CharaBase
{
private:
	float angle;		// �p�x
	float acceleration;	// ���x�̕ω���
	float angleVelocity;// �p�x�̕ω���
	float moveX;
	float moveY;
	int point = 0;
	NwaySpawner* weapon = new NwaySpawner;
	int ShootDelay;
	int Bcount = 1;
	int Bspeed = 5;
public:

	// X���W�AY���W�A���x�A�p�x�A�X�R�A
	Enemy(float _x, float _y, float _speed, int _bspeed, float _angle, int _score, int _bcount);
	~Enemy();

	void Update(GameMain* gamemain) override;
	void Draw()const override;
	void Hit(GameMain* gamemain)override;
	int GetPoint();
};

