#pragma once
#include"CharaBase.h"
#include"DxLib.h"
class GameMain;							// �O���錾
class Enemy : public CharaBase
{
public:

	Enemy();
	~Enemy();

	void Update(GameMain* gamemain) override;
	void Draw()const override;
	void Hit()override;
};

