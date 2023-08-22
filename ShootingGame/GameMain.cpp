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
	// �v���C���[�̍X�V
	player->Update(this);

	// UI�̍X�V
	ui->Update(player->GetScore(), PlayerLife, GameOverFlg);

	// �G�̍X�V
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (enemy[i] != nullptr) {
			// �v���C���[���G�ɓ���������
			if (player->HitSphere(enemy[i]) && player->GetFlg()) {
				player->Hit(this);
			}
			// �G�̃t���O���؂ꂽ��delete����
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
				player->Hit(this);
			}
			// �G���v���C���[�̒e�ɓ���������
			for (int j = 0; j < ENEMY_MAX; j++) {
				if (enemy[j] != nullptr) {
					if (enemy[j]->HitSphere(bullet[i]) && enemy[j]->name != bullet[i]->GetParent() && enemy[j]->GetFlg()) {
						enemy[j]->Hit(this);
						player->SetScore(enemy[j]->GetPoint());

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

// �v���C���[�̒e�̏o��
void GameMain::SpawnBullet(char* parentname, SphereCollider* parentcollider) {
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] == nullptr) {
			bullet[i] = new Bullet(parentname, parentcollider->GetLocation().x, parentcollider->GetLocation().y, 270);
			break;
		}
	}
}

// �����̏o��
void GameMain::SpawnBoom(float _x, float _y) {
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (boom[i] == nullptr) {
			boom[i] = new Boom(_x, _y);
			break;
		}
	}
}

// �G�̏o��
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

