#pragma once
#include"DxLib.h"
#include"AbstractScene.h"
#include"EnemySpawn.h"
#include"Player.h"
#include"Enemy.h"
#include"Bullet.h"
#include"Boom.h"
#include"DeleteCircle.h"
#include"LoadSounds.h"
#include"UI.h"
class GameMain : public AbstractScene
{
private:
	int EnemySpawnTimer;
	int PlayerLife;
	bool GameOverFlg;
	int MaxEnemy;
	int CamerashakeCount;
	int Camerashake;
public:
	ENEMYDATA data[63];
	Enemy* enemy[ENEMY_MAX];
	Bullet* bullet[BULLET_MAX];
	Boom* boom[ENEMY_MAX];
	Player* player;
	DeleteCircle* deletecircle[CIRCLE_MAX];
	UI* ui;
	GameMain();										// コンストラクタ
	~GameMain();									// デストラクタ

	virtual AbstractScene* Update() override;		// 描画以外の更新を実行
	void Draw() const override;						// 描画に関することを実装
	void Game();									// ゲームの処理
	bool HitCheck();							
	void SpawnBullet(char parentname, SphereCollider* parentcollider, float _angle, int _speed);
	void SpawnBoom(float _x, float _y);				// やられた時のエフェクトをスポーン
	void SpawnCircle(float _x, float _y, int _i);	// 球を消す円のスポーン
	void SpawnEnemy();								// 敵のスポーン
	void SetPlayerLife(int _i);						// プレイヤーの残機を設定
	int GetPlayerLife();							// プレイヤーの残機を取得
	void GameOver();
	Location GetPlayer();
	void CameraUpdate();
	void SetCameraShake(int _i);
};

