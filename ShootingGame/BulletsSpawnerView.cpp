#include "BulletsSpawnerView.h"
#include "Custom.h"
void BulletsSpawnerView::Shoot(Custom* custom, char parentname, SphereCollider* parentcollider, float _angle, int _count, int _speed, int _size)
{
	custom->SpawnBullet(parentname,parentcollider, _angle, _speed, _size);
}
