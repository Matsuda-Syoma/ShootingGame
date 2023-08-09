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

