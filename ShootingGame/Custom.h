#pragma once
#include "AbstractScene.h"
#include "ViewPlayer.h"
#include "Bullet.h"
class Custom : public AbstractScene
{
public:
	Custom();

	Bullet* bullet[BULLET_MAX];
	ViewPlayer* player;
	void SpawnBullet(char parentname, SphereCollider* parentcollider, float _angle, int _speed, int _size);


	AbstractScene* Update() override;				// 描画以外の更新を実行
	void Draw() const override;						// 描画に関することを実装
};

