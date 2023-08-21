#pragma once
#include "BulletsSpawner.h"
class NwaySpawner : public BulletsSpawner
{
private:
	int numBullets;
	float baseAngle;
	float angleDiff;

public:
	NwaySpawner();
	void Shoot(GameMain*, char* _name)override;
};

