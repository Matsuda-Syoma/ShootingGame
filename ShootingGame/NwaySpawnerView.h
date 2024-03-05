#pragma once
#include "BulletsSpawnerView.h"
class NwaySpawnerView : public BulletsSpawnerView
{
private:
	float angleDiff = 0;
public:
	void Shoot(Custom* custom, char parentname, SphereCollider* parentcollider, float _angle, int _count, int _speed, int _size)override;
};

