#include "BulletsSpawner.h"
#include "GameMain.h"
void BulletsSpawner::Shoot(GameMain* gamemain, char parentname, SphereCollider* parentcollider, float _angle, int _count, int _speed, int _size)
{
	gamemain->SpawnBullet(parentname,parentcollider, _angle, _speed, _size);
}
