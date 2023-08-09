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
public:

	Enemy(float _x, float _y, float _speed, float _angle);
	~Enemy();

	void Update(GameMain* gamemain) override;
	void Draw()const override;
	void Hit()override;
};

