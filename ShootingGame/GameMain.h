#pragma once
#include"DxLib.h"
#include"AbstractScene.h"
#include"Player.h"
#include"Enemy.h"
#include"Bullet.h"
class GameMain : public AbstractScene
{
public:

	Enemy* enemy[ENEMY_MAX];
	Bullet* bullet[BULLET_MAX];
	Player* player;
	GameMain();
	// �R���X�g���N�^
	~GameMain();								// �f�X�g���N�^

	virtual AbstractScene* Update() override;	// �`��ȊO�̍X�V�����s
	void Draw() const override;					// �`��Ɋւ��邱�Ƃ�����
	void Game();								// �Q�[���̏���
	bool HitCheck();
	void SpawnBullet(char* _name);
};

