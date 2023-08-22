#include "BulletsSpawner.h"
#include "GameMain.h"
void BulletsSpawner::Shoot(GameMain* gamemain, char* parentname, SphereCollider* parentcollider)
{
	gamemain->SpawnBullet(parentname,parentcollider);
}
