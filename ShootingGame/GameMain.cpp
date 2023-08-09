#include "GameMain.h"

GameMain::GameMain()
{
	enemy[0] = new Enemy;
	player = new Player;
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{
	// プレイヤーの更新
	player->Update(this);

	// 敵の更新
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Update(this);
		}
	}

	// 弾の更新
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] != nullptr) {

			// プレイヤーが自分以外の弾に当たったら
			if (player->HitSphere(bullet[i]) && player->name != bullet[i]->GetParent()) {
				printfDx("hitp ");
			}

			for (int j = 0; j < ENEMY_MAX; j++) {
				if (enemy[j] != nullptr) {
					if (enemy[j]->HitSphere(bullet[i]) && enemy[j]->name != bullet[i]->GetParent()) {
						printfDx("hite ");
					}
				}
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
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Draw();
			break;
		}
	}

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

void GameMain::SpawnBullet(char* parent) {
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] == nullptr) {
			bullet[i] = new Bullet(parent, player->GetLocation().x, player->GetLocation().y, 0.75);
			break;
		}
	}
}