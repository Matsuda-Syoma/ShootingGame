#include "DeleteCircle.h"
#include "GameMain.h"

int DeleteCircle::SpawnCircle;

DeleteCircle::DeleteCircle(float _x, float _y, int _i)
{
	location.x = _x;
	location.y = _y;
	flg = true;
	MaxSpawnCount = _i;
	SpawnCircleCount = MaxSpawnCount;
}


bool DeleteCircle::Update()
{
	if (flg) {
		if (SpawnCircleCount > 0) {
			radius = MaxSpawnCount * 20 - SpawnCircleCount * 20;
			SpawnCircleCount--;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void DeleteCircle::Draw() const
{
	SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, (MaxSpawnCount * 10) - ((MaxSpawnCount - SpawnCircleCount) * 10));
	DrawCircleGauge(location.x, location.y, 100.0, SpawnCircle, 0, 2 - SpawnCircleCount / 10);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void DeleteCircle::LoadImages()
{
	SpawnCircle = LoadGraph("Resources/images/circle.png");
}
