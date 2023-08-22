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
	int point = 0;
public:

	// X���W�AY���W�A���x�A�p�x�A�X�R�A
	Enemy(float _x, float _y, float _speed, float _angle, int _score);
	~Enemy();

	void Update(GameMain* gamemain) override;
	void Draw()const override;
	void Hit(GameMain* gamemain)override;
	int GetPoint();
};

