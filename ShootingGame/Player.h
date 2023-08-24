#pragma once
#include"common.h"
#include"CharaBase.h"
#include"PAD_INPUT.h"
#include"NwaySpawner.h"
class GameMain;						// �O���錾
class Player : public CharaBase
{
private:
	int Score;
	NwaySpawner* weapon = new NwaySpawner;
	float speedX;
	float speedY;
	float SpawnCount = 0;
	int MAXSPAWNCOUNT = 20;
	int shootdelay = 0;
	int SpawnTime;
	const int MAXSPAWNTIME = 90;

public:
	Player();
	~Player();
	void Init();
	void Update(GameMain* gamemain) override;
	void Draw(int camerashake)const override;
	void Hit(GameMain* gamemain);
	int GetScore();
	void SetScore(int _score);
};

