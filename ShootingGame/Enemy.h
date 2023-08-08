#pragma once
#include"CharaBase.h"
#include"DxLib.h"
class GameMain;							// ‘O•ûéŒ¾
class Enemy : public CharaBase
{
public:

	Enemy();
	~Enemy();

	void Update(GameMain* gamemain) override;
	void Draw()const override;
	void Hit()override;
};

