#pragma once
#include"Bullet.h"
class GameMain;				// �O���錾
class BulletsSpawner
{
private:
	int speed;				// ���x
	float angle;			// �p�x
	float acceleration;		// ���x�̕ω���
	float angleVelocity;	// �p�x�̕ω���
public:
	void Shoot(GameMain* game);
};

