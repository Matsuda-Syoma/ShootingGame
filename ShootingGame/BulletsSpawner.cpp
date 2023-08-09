#include "BulletsSpawner.h"
#include "GameMain.h"
void BulletsSpawner::Shoot(GameMain* gamemain, char* parent)
{
	gamemain->SpawnBullet(parent);
}
