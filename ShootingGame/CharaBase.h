#pragma once
#include"SphereCollider.h"
class CharaBase : public SphereCollider
{
protected:
	float speed;
	int image;

public:
	virtual void Update() = 0;		// �X�V����
	virtual void Draw()const = 0;	// �`�揈��
	virtual void Hit() = 0;			// �����������̏���
};

