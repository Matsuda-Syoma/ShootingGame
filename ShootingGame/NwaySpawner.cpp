#include "NwaySpawner.h"
#include "GameMain.h"
void NwaySpawner::Shoot(GameMain* gamemain, char parentname, SphereCollider* parentcollider, float _angle, int _count, int _speed, int _size)
{
	for (int i = 0; i < _count; i++) {
		int a = (i - round(_count / 2));
		angleDiff = _angle - (90 / _count * (i - round(_count / 2)));
		if (_count % 2 == 0) {
			gamemain->SpawnBullet(parentname, parentcollider, angleDiff - (90 / _count / 2), _speed, _size);
		}
		else {
			gamemain->SpawnBullet(parentname, parentcollider, angleDiff, _speed, _size);
		}
		
	}
}
