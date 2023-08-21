#pragma once
#include"CharaBase.h"
#include"DxLib.h"
class GameMain;							// �O���錾
class Enemy : public CharaBase
{
private:
	float angle;		// �p�x
	float acceleration;	// ���x�̕ω���
	float angleVelocity;// �p�x�̕ω���
	float moveX;
	float moveY;
public:

	// X���W�AY���W�A���x�A�p�x
	Enemy(float _x, float _y, float _speed, float _angle);
	~Enemy();

	void Update(GameMain* gamemain) override;
	void Draw()const override;
	void Hit()override;
};

