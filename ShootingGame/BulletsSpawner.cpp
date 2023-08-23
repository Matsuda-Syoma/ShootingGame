#include "BulletsSpawner.h"
#include "GameMain.h"
void BulletsSpawner::Shoot(GameMain* gamemain, char parentname, SphereCollider* parentcollider, float _angle, int _count, int _speed)
{
	gamemain->SpawnBullet(parentname,parentcollider, _angle, _speed);
}
