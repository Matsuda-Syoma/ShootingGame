#include "BulletsSpawner.h"
#include "GameMain.h"
void BulletsSpawner::Shoot(GameMain* gamemain)
{
	gamemain->SpawnBullet();
}
