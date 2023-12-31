#pragma once
#include"CharaBase.h"
#include"DxLib.h"
//#include"BulletsSpawner.h"
#include"NwaySpawner.h"
class GameMain;								// 前方宣言
class Enemy : public CharaBase
{
private:
	float angle;								// 角度
	float acceleration;							// 速度の変化量
	float angleVelocity;						// 角度の変化量
	float moveX;								// 移動する距離X
	float moveY;								// 移動する距離Y
	float Normalize = 0;						// 飛ばす向き
	int hp = 1;									// HP
	int Maxhp;
	int point = 0;								// 増えるスコア
	NwaySpawner* weapon = new NwaySpawner;		// Nwayの生成
	int ShootDelay;								// Shootの撃つタイミング(nフレーム毎)
	int Bcount = 1;								// 弾の量
	int Bspeed = 5;								// 弾のスピード
	int Bsize = 4;								// 弾のサイズ
	int ShootFrame = 60;						// 撃つフレーム
	int StopFrame = -1;							// 止まるフレーム
	bool BossFlg;
	int HpCircle;
	int BossMoveCount = 0;
	int BossMaxMoveCount;
public:

	// X座標,Y座標,速度,弾速度,角度,スコア,弾数,HP,弾の撃つ間隔,止まるタイミング
	Enemy(float _x, float _y, float _speed, int _bspeed, float _angle, int _score, int _bcount, int _hp,int _sframe, int _stop, int _bsize);
	~Enemy();

	void Update(GameMain* gamemain) override;	// 処理の更新
	float Map(float value, float start1, float stop1, float start2, float stop2);
	void Draw(int camerashake)const override;	// 描画の更新
	void Hit(GameMain* gamemain)override;		// ダメージを受けた時の処理
	int GetPoint();								// 自身のスコアを取得
	void SetBossFlg(bool _flg);
	void Shoot(GameMain* gamemain);
};

