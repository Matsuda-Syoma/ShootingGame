#pragma once
#include"SphereCollider.h"
class GameMain;
class CharaBase : public SphereCollider
{
protected:
	float speed;
	int image;

public:
	virtual void Update(GameMain* gamemain);		// �X�V����
	virtual void Draw()const;	// �`�揈��
	virtual void Hit();			// �����������̏���
};

