#pragma once
#define _USE_MATH_DEFINES
#include<math.h>

#include"common.h"
#include"DxLib.h"
#include"SphereCollider.h"
class Bullet : public SphereCollider
{
private:
	int damage;			// ダメージ
	int speed;			// 速度
	float angle;		// 角度
	float acceleration;	// 速度の変化量
	float angleVelocity;// 角度の変化量
	float moveX;		// 移動する距離X
	float moveY;		// 移動する距離Y
	char parent;		// 生成した親の名前

public:
	// コンストラクタ
	Bullet(char _name, float _x, float _y, float _angle, int _speed);
	~Bullet();			// デストラクタ
	bool Update();		// 
	void Draw()const;	// 
	void GetDamage();	// 
	char GetParent();	// 
};

