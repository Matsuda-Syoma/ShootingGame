#include "GameMain.h"
GameMain::GameMain()
{
	GameOverFlg = false;
	Sounds::LoadSounds();
	EnemySpawn::EnemySpawn();
	for (int i = 0; i < 63; i++) {
		data[i] = EnemySpawn::LoadEnemy(i);
	}
	PlayerLife = 2;
	player = new Player;
	ui = new UI;
	EnemySpawnTimer = 0;
	Boom::LoadImages();
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{
	SpawnEnemy();
	// プレイヤーの更新
	player->Update(this);

	// UIの更新
	ui->Update(player->GetScore(), PlayerLife, GameOverFlg);

	// 敵の更新
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (enemy[i] != nullptr) {
			// プレイヤーが敵に当たったら
			if (player->HitSphere(enemy[i]) && player->GetFlg()) {
				player->Hit(this);
			}
			// 敵のフラグが切れたらdeleteする
			enemy[i]->Update(this);
			if (!enemy[i]->GetFlg()) {
				enemy[i] = nullptr;
				delete enemy[i];
			}
		}
	}

	// 弾の更新
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] != nullptr) {
			// プレイヤーが自分以外の弾に当たったら
			if (player->HitSphere(bullet[i]) && player->name != bullet[i]->GetParent() && player->GetFlg()) {
				player->Hit(this);
			}
			// 敵がプレイヤーの弾に当たったら
			for (int j = 0; j < ENEMY_MAX; j++) {
				if (enemy[j] != nullptr) {
					if (enemy[j]->HitSphere(bullet[i]) && enemy[j]->name != bullet[i]->GetParent() && enemy[j]->GetFlg()) {
						enemy[j]->Hit(this);
						player->SetScore(enemy[j]->GetPoint());

					}
				}
			}

			// 弾の更新処理
			if (!bullet[i]->Update()) {
				bullet[i] = nullptr;
				delete bullet[i];
			}
		}
	}

	// 爆発の更新処理
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (boom[i] != nullptr) {
			if (!boom[i]->Update()) {
				boom[i] = nullptr;
				delete boom[i];
			}
		}
	}

	return this;
}

void GameMain::Draw() const
{
	// 背景
	DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x0031aa, true);

	for (int i = 1; i < 10; i++) {
		DrawBox((int)104 * i, 0, (int)104 * i + 1, SCREEN_HEIGHT, 0x6aceee, true);
	}
	for (int i = 0; i < 11; i++) {
		DrawBox(0, (int)104 * (i) + EnemySpawnTimer % 104, SCREEN_WIDTH, ((int)104 * i + 1) + EnemySpawnTimer % 104, 0x6aceee, true);
	}

	player->Draw();
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Draw();
		}
	}

	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] != nullptr) {
			bullet[i]->Draw();
		}
	}
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (boom[i] != nullptr) {
			boom[i]->Draw();
		}
	}
	ui->Draw();
}

void GameMain::Game()
{
}
bool GameMain::HitCheck()
{
	return false;
}

// プレイヤーの弾の出現
void GameMain::SpawnBullet(char* parentname, SphereCollider* parentcollider) {
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] == nullptr) {
			bullet[i] = new Bullet(parentname, parentcollider->GetLocation().x, parentcollider->GetLocation().y, 270);
			break;
		}
	}
}

// 爆発の出現
void GameMain::SpawnBoom(float _x, float _y) {
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (boom[i] == nullptr) {
			boom[i] = new Boom(_x, _y);
			break;
		}
	}
}

// 敵の出現
void GameMain::SpawnEnemy() {
	EnemySpawnTimer++;

	for (int i = 0; i < 63; i++) {
		if (EnemySpawnTimer == data[i].SpawnTime) {
			for (int j = 0; j < ENEMY_MAX; j++) {
				if (enemy[j] == nullptr) {
					enemy[j] = new Enemy(data[i].x, data[i].y, data[i].speed, data[i].angle, data[i].score);
					break;
				}
			}
		}
	}


}

void GameMain::SetPlayerLife(int _i)
{
	PlayerLife += _i;
}

int GameMain::GetPlayerLife()
{
	return PlayerLife;
}

void GameMain::GameOver()
{
	GameOverFlg = true;
}

