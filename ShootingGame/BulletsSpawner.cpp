#include "BulletsSpawner.h"
#include "GameMain.h"
void BulletsSpawner::Shoot(GameMain* gamemain, char parentname, SphereCollider* parentcollider, float _angle)
{
	gamemain->SpawnBullet(parentname,parentcollider, _angle);
}
