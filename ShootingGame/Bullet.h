#pragma once
#define _USE_MATH_DEFINES
#include<math.h>

#include"common.h"
#include"DxLib.h"
#include"SphereCollider.h"
class Bullet : public SphereCollider
{
private:
	int damage;			// �_���[�W
	int speed;			// ���x
	float angle;		// �p�x
	float acceleration;	// ���x�̕ω���
	float angleVelocity;// �p�x�̕ω���
	float moveX;		// �ړ����鋗��X
	float moveY;		// �ړ����鋗��Y
	char parent;		// ���������e�̖��O

public:
	// �R���X�g���N�^
	Bullet(char _name, float _x, float _y, float _angle, int _speed);
	~Bullet();			// �f�X�g���N�^
	bool Update();		// 
	void Draw()const;	// 
	void GetDamage();	// 
	char GetParent();	// 
};

