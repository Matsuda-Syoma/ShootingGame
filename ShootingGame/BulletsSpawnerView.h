#pragma once
#include"Bullet.h"
class Custom;				// 前方宣言
class BulletsSpawnerView
{
private:
	int speed;				// 速度
	float angle;			// 角度
	float acceleration;		// 速度の変化量
	float angleVelocity;	// 角度の変化量
public:
	virtual void Shoot(Custom* custom, char parentname, SphereCollider* parentcollider, float _angle, int _count, int _speed, int _size);
};

