#pragma once
#include"SphereCollider.h"
class CharaBase : public SphereCollider
{
private:
	float speed;
	int image;

public:
	virtual void Update() = 0;		// 更新処理
	virtual void Draw()const = 0;	// 描画処理
	virtual void Hit() = 0;			// 当たった時の処理
};

