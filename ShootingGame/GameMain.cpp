#include "GameMain.h"

GameMain::GameMain()
{
	enemy = new Enemy;
	bullet = new Bullet;
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{
	enemy->Update();
	bullet->Update();
	return this;
}

void GameMain::Draw() const
{
	enemy->Draw();
	bullet->Draw();
}

void GameMain::Game()
{
}
bool GameMain::HitCheck()
{
	return false;
}