#pragma once
#define _USE_MATH_DEFINES
#include<math.h>

#include"common.h"
#include"DxLib.h"
#include"SphereCollider.h"
class Bullet : public SphereCollider
{
private:
	int damage;		// ダメージ
	int speed;		// 速度
	float angle;	// 角度
	float acceleration;	// 速度の変化量
	float angleVelocity;// 角度の変化量
	float moveX;
	float moveY;

public:
	Bullet();
	~Bullet();
	void Update();
	void Draw()const;
	void GetDamage();
};

