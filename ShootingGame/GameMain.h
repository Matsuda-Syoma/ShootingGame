#pragma once
#include"DxLib.h"
#include"AbstractScene.h"
#include"Enemy.h"
#include"Bullet.h"
class GameMain : public AbstractScene
{
public:

	Enemy* enemy;
	Bullet* bullet;
	GameMain();
	// �R���X�g���N�^
	~GameMain();								// �f�X�g���N�^

	virtual AbstractScene* Update() override;	// �`��ȊO�̍X�V�����s
	void Draw() const override;					// �`��Ɋւ��邱�Ƃ�����
	void Game();								// �Q�[���̏���
	bool HitCheck();
};

