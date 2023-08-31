#include "GameMain.h"
#include "InputRanking.h"
//テスト
#include "TItle.h"
// コンストラクタ
GameMain::GameMain()
{
	Ranking::ReadRanking();
	GameFlg = 0;
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
	BossFlg = false;
}

GameMain::~GameMain()
{
	delete player;
	delete ui;
	for (int i = 0; i < ENEMY_MAX; i++) {
		delete  enemy[i];
	}
	for (int i = 0; i < ENEMY_MAX; i++) {
		delete boom[i];
	}
	for (int i = 0; i < BULLET_MAX; i++) {
		delete bullet[i];
	}
	for (int i = 0; i < CIRCLE_MAX; i++) {
		delete deletecircle[i];
	}
}

AbstractScene* GameMain::Update()
{
	if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_BACK)) {
		return new Title();
	}

	if (GameFlg != 0 && PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_A)) {
		if (Ranking::GetData(4).score < player->GetScore()) {
			return new InputRanking(player->GetScore());
		}
		return new Title();
	}


	SpawnEnemy();
	// プレイヤーの更新
	player->Update(this);

	// UIの更新
	ui->Update(player->GetScore(), PlayerLife, GameFlg);

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
				MaxEnemy--;
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
						bullet[i]->SetFlg(false);
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

	// 円の更新処理
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


	CameraUpdate();

	// ゲームクリアorボス出す
	if (MaxEnemy <= 0) {
		if (!BossFlg) {
			for (int i = 0; i < ENEMY_MAX; i++) {
				if (enemy[i] == nullptr) {
					enemy[i] = new Enemy(520, 0, 1, 3, 90, 2500, 9, 10 * (Grade + 1), 90, 120, 7);
					enemy[i]->SetBossFlg(true);
					BossFlg = true;
					break;
				}
			}
		}

	}

	return this;
}

void GameMain::Draw() const
{
	// 背景
	DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x003166, true);

	// 背景の縦線
	for (int i = 1; i < 10; i++) {
		DrawBox(((int)104 * i) + Camerashake, 0, ((int)104 * i + 1) + Camerashake, SCREEN_HEIGHT, 0x6ace55, true);
	}
	// 背景の横線
	for (int i = 0; i < 11; i++) {
		DrawBox(0, ((int)104 * (i)+EnemySpawnTimer % 104) + Camerashake / 2, SCREEN_WIDTH,
			(((int)104 * i + 1) + EnemySpawnTimer % 104) + Camerashake / 2, 0x6ace55, true);
	}

	// プレイヤーの描画
	player->Draw(Camerashake);

	// 敵の描画
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Draw(Camerashake);
		}
	}

	// 弾の描画
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] != nullptr) {
			bullet[i]->Draw();
		}
	}

	// 爆発の描画
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (boom[i] != nullptr) {
			boom[i]->Draw();
		}
	}


	// 円の描画
	for (int i = 0; i < CIRCLE_MAX; i++) {
		if (deletecircle[i] != nullptr) {
			deletecircle[i]->Draw();
		}
	}

	// UIの描画
	ui->Draw();
}

void GameMain::Game()
{
}
bool GameMain::HitCheck()
{
	return false;
}

// 弾の出現
void GameMain::SpawnBullet(char parentname, SphereCollider* parentcollider, float _angle, int _speed, int _size) {
	// 弾がnullptrだったら生成してループを抜ける
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] == nullptr) {
			bullet[i] = new Bullet(parentname, parentcollider->GetLocation().x, parentcollider->GetLocation().y, _angle, _speed, _size);
			break;
		}
	}
}

// 爆発の出現
void GameMain::SpawnBoom(float _x, float _y) {
	// 爆発がnullptrだったら生成してループを抜ける
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

	// 敵がnullptrだったら生成してループを抜ける
	for (int i = 0; i < EnemySpawn::GetMaxEnemy(); i++) {
		if (EnemySpawnTimer == data[i].SpawnTime) {
			for (int j = 0; j < ENEMY_MAX; j++) {
				if (enemy[j] == nullptr) {
					enemy[j] = new Enemy(data[i].x, data[i].y, data[i].speed, data[i].Bspeed, data[i].angle, data[i].score, data[i].Bcount + (Grade + GetRand(1)), data[i].hp, data[i].shootframe, data[i].stopframe, data[i].Bsize);
					break;
				}
			}
		}
	}
}

// 弾を消す円の出現
void GameMain::SpawnCircle(float _x, float _y, int _i) {
	// 円がnullptrだったら生成してループを抜ける
	for (int i = 0; i < CIRCLE_MAX; i++) {
		if (deletecircle[i] == nullptr) {
			deletecircle[i] = new DeleteCircle(_x, _y, _i);
			break;
		}
	}
}

// プレイヤーの残機設定
void GameMain::SetPlayerLife(int _i)
{
	PlayerLife += _i;
}

int GameMain::GetPlayerLife()
{
	return PlayerLife;
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

void GameMain::SetScore(int _i) {
	player->SetScore(_i);
}

void GameMain::SetGameFlg(int _flg) {
	GameFlg = _flg;
}

void GameMain::SetSpawnTime(int _i) {
	EnemySpawnTimer = _i;
}

void GameMain::SetMaxEnemy() {
	BossFlg = false;
	MaxEnemy = EnemySpawn::GetMaxEnemy() + 1;
	Grade += 1;
}