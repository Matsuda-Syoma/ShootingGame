#pragma once
#include"common.h"
#include<math.h>
#include"CharaBase.h"
#include"PAD_INPUT.h"
#include"BulletsSpawner.h"
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
	void Update() override;
	void Draw()const override;
	void Hit()override;
};

