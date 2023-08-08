#pragma once
#include"common.h"
#include"CharaBase.h"
#include"PAD_INPUT.h"
#include"BulletsSpawner.h"
class GameMain;						// ‘O•ûéŒ¾
class Player : public CharaBase
{
private:
	int score;
	BulletsSpawner* weapon;
	float speedX;
	float speedY;

public:
	Player();
	~Player();
	void Update(GameMain* gamemain) override;
	void Draw()const override;
	void Hit()override;
};

