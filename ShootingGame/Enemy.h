#pragma once
#include"CharaBase.h"
#include"DxLib.h"
//#include"BulletsSpawner.h"
#include"NwaySpawner.h"
class GameMain;							// 前方宣言
class Enemy : public CharaBase
{
private:
	float angle;		// 角度
	float acceleration;	// 速度の変化量
	float angleVelocity;// 角度の変化量
	float moveX;
	float moveY;
	int point = 0;
	NwaySpawner* weapon = new NwaySpawner;
	int ShootDelay;
	int Bcount = 1;
	int Bspeed = 5;
public:

	// X座標、Y座標、速度、角度、スコア
	Enemy(float _x, float _y, float _speed, int _bspeed, float _angle, int _score, int _bcount);
	~Enemy();

	void Update(GameMain* gamemain) override;
	void Draw()const override;
	void Hit(GameMain* gamemain)override;
	int GetPoint();
};

