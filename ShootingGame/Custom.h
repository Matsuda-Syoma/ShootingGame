#pragma once
#include "AbstractScene.h"
#include "ViewPlayer.h"
#include "Bullet.h"
class Custom : public AbstractScene
{
public:
	Custom();

	Bullet* bullet[BULLET_MAX];
	ViewPlayer* player;
	void SpawnBullet(char parentname, SphereCollider* parentcollider, float _angle, int _speed, int _size);


	AbstractScene* Update() override;				// �`��ȊO�̍X�V�����s
	void Draw() const override;						// �`��Ɋւ��邱�Ƃ�����
};

