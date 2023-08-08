#include "GameMain.h"

GameMain::GameMain()
{
	enemy = new Enemy;
	player = new Player;
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{
	player->Update(this);
	enemy->Update(this);
	//if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_A)) {
	//	SpawnBullet();
	//}
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] != nullptr) {

			if (player->HitSphere(bullet[i])) {
				//printfDx("hit");
			}

			if (!bullet[i]->Update()) {
				bullet[i] = nullptr;
				delete bullet[i];
			}
		}
	}

	return this;
}

void GameMain::Draw() const
{
	player->Draw();
	enemy->Draw();

	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] != nullptr) {
			bullet[i]->Draw();
		}
	}
}

void GameMain::Game()
{
}
bool GameMain::HitCheck()
{
	return false;
}

void GameMain::SpawnBullet() {
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] == nullptr) {
			bullet[i] = new Bullet(player->GetLocation().x, player->GetLocation().y, 0.75);
			break;
		}
	}
}