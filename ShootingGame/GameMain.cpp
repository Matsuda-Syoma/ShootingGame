#include "GameMain.h"

// �R���X�g���N�^
GameMain::GameMain()
{
	GameOverFlg = false;
	Sounds::LoadSounds();
	Boom::LoadImages();
	DeleteCircle::LoadImages();
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemy[i] = 0;
	}
	for (int i = 0; i < BULLET_MAX; i++) {
		bullet[i] = 0;
	}
	for (int i = 0; i < ENEMY_MAX; i++) {
		boom[i] = 0;
	}

	EnemySpawn::EnemySpawn();
	MaxEnemy = EnemySpawn::GetMaxEnemy();
	for (int i = 0; i < MaxEnemy; i++) {
		data[i] = EnemySpawn::LoadEnemy(i);
	}
	PlayerLife = 2;
	player = new Player;
	ui = new UI;
	EnemySpawnTimer = 0;
	CamerashakeCount = 0;
	Camerashake = 0;
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

	CameraUpdate();

	// �Q�[���N���Aor�{�X�o��
	if (MaxEnemy <= 0) {

	}

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
				MaxEnemy--;
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

	// �~�̍X�V����
	for (int i = 0; i < CIRCLE_MAX; i++) {
		if (deletecircle[i] != nullptr) {
			for (int j = 0; j < BULLET_MAX; j++) {
					if (bullet[j] != nullptr) {
						if (deletecircle[i]->HitSphere(bullet[j])) {
							bullet[j] = nullptr;
							delete bullet[j];
						}
					}
				}
			if (!deletecircle[i]->Update()) {
				deletecircle[i] = nullptr;
				delete deletecircle[i];
			}
		}
	}

	return this;
}

void GameMain::Draw() const
{
	// �w�i
	DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x0031aa, true);

	// �w�i�̏c��
	for (int i = 1; i < 10; i++) {
		DrawBox(((int)104 * i) + Camerashake, 0, ((int)104 * i + 1) + Camerashake, SCREEN_HEIGHT, 0x6aceee, true);
	}
	// �w�i�̉���
	for (int i = 0; i < 11; i++) {
		DrawBox(0, ((int)104 * (i)+EnemySpawnTimer % 104) + Camerashake / 2, SCREEN_WIDTH,
			(((int)104 * i + 1) + EnemySpawnTimer % 104) + Camerashake / 2, 0x6aceee, true);
	}

	// �v���C���[�̕`��
	player->Draw(Camerashake);

	// �G�̕`��
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Draw(Camerashake);
		}
	}

	// �e�̕`��
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] != nullptr) {
			bullet[i]->Draw();
		}
	}

	// �����̕`��
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (boom[i] != nullptr) {
			boom[i]->Draw();
		}
	}


	// �~�̕`��
	for (int i = 0; i < CIRCLE_MAX; i++) {
		if (deletecircle[i] != nullptr) {
			deletecircle[i]->Draw();
		}
	}

	// UI�̕`��
	ui->Draw();
}

void GameMain::Game()
{
}
bool GameMain::HitCheck()
{
	return false;
}

// �e�̏o��
void GameMain::SpawnBullet(char parentname, SphereCollider* parentcollider, float _angle, int _speed) {
	// �e��nullptr�������琶�����ă��[�v�𔲂���
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] == nullptr) {
			bullet[i] = new Bullet(parentname, parentcollider->GetLocation().x, parentcollider->GetLocation().y, _angle, _speed);
			break;
		}
	}
}

// �����̏o��
void GameMain::SpawnBoom(float _x, float _y) {
	// ������nullptr�������琶�����ă��[�v�𔲂���
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

	// �G��nullptr�������琶�����ă��[�v�𔲂���
	for (int i = 0; i < EnemySpawn::GetMaxEnemy(); i++) {
		if (EnemySpawnTimer == data[i].SpawnTime) {
			for (int j = 0; j < ENEMY_MAX; j++) {
				if (enemy[j] == nullptr) {
					enemy[j] = new Enemy(data[i].x, data[i].y, data[i].speed, data[i].Bspeed, data[i].angle, data[i].score, data[i].Bcount);
					break;
				}
			}
		}
	}
}

// �e�������~�̏o��
void GameMain::SpawnCircle(float _x, float _y, int _i) {
	// �~��nullptr�������琶�����ă��[�v�𔲂���
	for (int i = 0; i < CIRCLE_MAX; i++) {
		if (deletecircle[i] == nullptr) {
			deletecircle[i] = new DeleteCircle(_x, _y, _i);
			break;
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

Location GameMain::GetPlayer() 
{
	return player->GetLocation();
}

void GameMain::CameraUpdate() {
	if (CamerashakeCount > 0) {
		Camerashake = round(CamerashakeCount / 2);
		if (CamerashakeCount % 2 == 0) {
			Camerashake *= -1;
		}
		CamerashakeCount--;
	}
}

void GameMain::SetCameraShake(int _i) {
	CamerashakeCount = _i;
}