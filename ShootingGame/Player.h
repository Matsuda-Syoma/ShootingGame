#pragma once
#include"common.h"
#include"CharaBase.h"
#include"PAD_INPUT.h"
#include"BulletsSpawner.h"
class GameMain;						// ‘O•ûéŒ¾
class Player : public CharaBase
{
private:
	int Score;
	BulletsSpawner* weapon;
	float speedX;
	float speedY;
	int shootdelay = 0;

public:
	Player();
	~Player();
	void Update(GameMain* gamemain) override;
	void Draw()const override;
	void Hit(GameMain* gamemain);
	int GetScore();
	void SetScore(int _score);
};

