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
	virtual void Shoot(GameMain* gamemain, char parentname, SphereCollider* parentcollider, float _angle, int _count, int _speed, int _size);
};

