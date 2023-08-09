#include "GameMain.h"
#include "EnemySpawn.h"
GameMain::GameMain()
{
	player = new Player;
	EnemySpawnTimer = 0;
	Boom::LoadImages();
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{
	SpawnEnemy();
	// �v���C���[�̍X�V
	player->Update(this);

	// �G�̍X�V
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (enemy[i] != nullptr) {
			// �v���C���[���G�ɓ���������
			if (player->HitSphere(enemy[i]) && player->GetFlg()) {
				SpawnBoom(player->GetLocation().x, player->GetLocation().y);
				player->SetFlg(false);
				WaitTimer(250);
			}
			enemy[i]->Update(this);
			if (!enemy[i]->GetFlg()) {
				enemy[i] = nullptr;
				delete enemy[i];
			}
		}
	}

	// �e�̍X�V
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] != nullptr) {
			// �v���C���[�������ȊO�̒e�ɓ���������
			if (player->HitSphere(bullet[i]) && player->name != bullet[i]->GetParent() && player->GetFlg()) {
				SpawnBoom(player->GetLocation().x, player->GetLocation().y);
				player->SetFlg(false);
			}
			// �G���v���C���[�̒e�ɓ���������
			for (int j = 0; j < ENEMY_MAX; j++) {
				if (enemy[j] != nullptr) {
					if (enemy[j]->HitSphere(bullet[i]) && enemy[j]->name != bullet[i]->GetParent() && enemy[j]->GetFlg()) {
						SpawnBoom(enemy[j]->GetLocation().x, enemy[j]->GetLocation().y);
						enemy[j]->SetFlg(false);

					}
				}
			}

			// �e�̍X�V����
			if (!bullet[i]->Update()) {
				bullet[i] = nullptr;
				delete bullet[i];
			}
		}
	}

	// �����̍X�V����
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
	// �w�i
	DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x0031aa, true);
	for (int i = 1; i < 11; i++) {
		DrawBox((int)128 * i, 0, (int)128 * i + 10, SCREEN_HEIGHT, 0x6aceee, true);
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
			bullet[i] = new Bullet(parent, player->GetLocation().x, player->GetLocation().y, 270);
			break;
		}
	}
}

void GameMain::SpawnBoom(float _x, float _y) {
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (boom[i] == nullptr) {
			boom[i] = new Boom(_x, _y);
			break;
		}
	}
}

void GameMain::SpawnEnemy() {
	EnemySpawnTimer++;

	for (int i = 0; i < 63; i++) {
		if (EnemySpawnTimer == EnemySpawnData[i][2]) {
			for (int i = 0; i < ENEMY_MAX; i++) {
				if (enemy[i] == nullptr) {
					enemy[i] = new Enemy(EnemySpawnData[i][0], EnemySpawnData[i][1],2,90);
					break;
				}
			}
		}
	}


}