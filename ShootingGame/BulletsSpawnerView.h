#pragma once
#include"Bullet.h"
class Custom;				// �O���錾
class BulletsSpawnerView
{
private:
	int speed;				// ���x
	float angle;			// �p�x
	float acceleration;		// ���x�̕ω���
	float angleVelocity;	// �p�x�̕ω���
public:
	virtual void Shoot(Custom* custom, char parentname, SphereCollider* parentcollider, float _angle, int _count, int _speed, int _size);
};

