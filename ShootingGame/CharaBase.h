#pragma once
#include"SphereCollider.h"
#include<string>
class GameMain;
class CharaBase : public SphereCollider
{
protected:
	float speed;
	int image;

public:
	char name[3] = "n";
	CharaBase();
	virtual void Update(GameMain* gamemain);		// 更新処理
	virtual void Draw()const;	// 描画処理
	virtual void Hit();			// 当たった時の処理
};

