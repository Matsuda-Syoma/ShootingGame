#pragma once
#include"DxLib.h"
#include"AbstractScene.h"
#include"Player.h"
#include"Enemy.h"
#include"Bullet.h"
class GameMain : public AbstractScene
{
public:

	Enemy* enemy[ENEMY_MAX];
	Bullet* bullet[BULLET_MAX];
	Player* player;
	GameMain();
	// コンストラクタ
	~GameMain();								// デストラクタ

	virtual AbstractScene* Update() override;	// 描画以外の更新を実行
	void Draw() const override;					// 描画に関することを実装
	void Game();								// ゲームの処理
	bool HitCheck();
	void SpawnBullet(char* _name);
};

