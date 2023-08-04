#include "GameMain.h"

GameMain::GameMain()
{
	enemy = new Enemy;
	bullet = new Bullet;
	player = new Player;
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{
	player->Update();
	enemy->Update();

	if (bullet != nullptr) {
		if (!bullet->Update()) {
			bullet = nullptr;
			delete bullet;
		}
	}

	return this;
}

void GameMain::Draw() const
{
	player->Draw();
	enemy->Draw();
	if (bullet != nullptr) {
		bullet->Draw();
	}
}

void GameMain::Game()
{
}
bool GameMain::HitCheck()
{
	return false;
}