#pragma once
#include"CharaBase.h"
#include"DxLib.h"
class Enemy : public CharaBase
{
public:

	Enemy();
	~Enemy();

	void Update() override;
	void Draw()const override;
	void Hit()override;
};

