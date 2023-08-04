#pragma once
#define _USE_MATH_DEFINES
#include<math.h>

#include"common.h"
#include"DxLib.h"
#include"SphereCollider.h"
class Bullet : public SphereCollider
{
private:
	int damage;		// �_���[�W
	int speed;		// ���x
	float angle;	// �p�x
	float acceleration;	// ���x�̕ω���
	float angleVelocity;// �p�x�̕ω���
	float moveX;
	float moveY;

public:
	Bullet();
	~Bullet();
	bool Update();
	void Draw()const;
	void GetDamage();
};

