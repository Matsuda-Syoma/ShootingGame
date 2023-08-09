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
	char *parent;

public:
	Bullet();
	Bullet(char* _name, float _x, float _y, float _angle);
	~Bullet();
	bool Update();
	void Draw()const;
	void GetDamage();
	char* GetParent();
};

