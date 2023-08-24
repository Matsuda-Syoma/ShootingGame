#pragma once
#include"SphereCollider.h"
#define _USE_MATH_DEFINES
#include<math.h>
class GameMain;
class CharaBase : public SphereCollider
{
protected:
	bool flg = true;
	float speed;
	int image;

public:
	char name = 'n';
	CharaBase();
	virtual void Update(GameMain* gamemain);	// 更新処理
	virtual void Draw(int camerashake)const;	// 描画処理
	virtual void Hit(GameMain* gamemain);		// 当たった時の処理
	virtual bool GetFlg();						// フラグを取得
	virtual void SetFlg(bool _flg);				// フラグを設定
};

