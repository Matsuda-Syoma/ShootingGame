#pragma once
#include "DxLib.h"
#include "SphereCollider.h"
class GameMain;						// �O���錾
class DeleteCircle : public SphereCollider
{
private:
	bool flg = false;
	static int SpawnCircle;
	float SpawnCircleCount = 0;
	int MaxSpawnCount;
public:
	DeleteCircle(float _x, float _y, int _i);
	bool Update();
	void Draw()const;
	static void LoadImages();
};

