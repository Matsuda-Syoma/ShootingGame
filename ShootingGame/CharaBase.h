#pragma once
#include"SphereCollider.h"
#include<string>
class GameMain;
class CharaBase : public SphereCollider
{
protected:
	float speed;
	int image;

public:
	char name[3] = "n";
	CharaBase();
	virtual void Update(GameMain* gamemain);		// �X�V����
	virtual void Draw()const;	// �`�揈��
	virtual void Hit();			// �����������̏���
};

