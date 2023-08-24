#pragma once
#include "BulletsSpawner.h"
class NwaySpawner : public BulletsSpawner
{
private:
	float angleDiff = 0;
public:
	void Shoot(GameMain* gamemain, char parentname, SphereCollider* parentcollider, float _angle, int _count, int _speed)override;
};

