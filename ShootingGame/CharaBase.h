#pragma once
#include"SphereCollider.h"
#define _USE_MATH_DEFINES
#include<math.h>
class GameMain;
class CharaBase : public SphereCollider
{
protected:
	bool flg = true;
	float speed;
	int image;

public:
	char name = 'n';
	CharaBase();
	virtual void Update(GameMain* gamemain);	// �X�V����
	virtual void Draw(int camerashake)const;	// �`�揈��
	virtual void Hit(GameMain* gamemain);		// �����������̏���
	virtual bool GetFlg();						// �t���O���擾
	virtual void SetFlg(bool _flg);				// �t���O��ݒ�
};

