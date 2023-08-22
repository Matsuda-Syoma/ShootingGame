#pragma once
#include"CharaBase.h"
#include"DxLib.h"
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
public:

	// X座標、Y座標、速度、角度、スコア
	Enemy(float _x, float _y, float _speed, float _angle, int _score);
	~Enemy();

	void Update(GameMain* gamemain) override;
	void Draw()const override;
	void Hit(GameMain* gamemain)override;
	int GetPoint();
};

