#pragma once
#include"DxLib.h"
#include"AbstractScene.h"
#include"EnemySpawn.h"
#include"Player.h"
#include"Enemy.h"
#include"Bullet.h"
#include"Boom.h"
#include"LoadSounds.h"
#include"UI.h"
class GameMain : public AbstractScene
{
private:
	int EnemySpawnTimer;
	int PlayerLife;
	bool GameOverFlg;
	int MaxEnemy;
	int CamerashakeCount;
	int Camerashake;
public:
	ENEMYDATA data[63];
	Enemy* enemy[ENEMY_MAX];
	Bullet* bullet[BULLET_MAX];
	Boom* boom[ENEMY_MAX];
	Player* player;
	UI* ui;
	GameMain();
	// �R���X�g���N�^
	~GameMain();								// �f�X�g���N�^

	virtual AbstractScene* Update() override;	// �`��ȊO�̍X�V�����s
	void Draw() const override;					// �`��Ɋւ��邱�Ƃ�����
	void Game();								// �Q�[���̏���
	bool HitCheck();							
	void SpawnBullet(char parentname, SphereCollider* parentcollider, float _angle, int _speed);
	void SpawnBoom(float _x, float _y);			// ���ꂽ���̃G�t�F�N�g���X�|�[��
	void SpawnEnemy();							// �G�̃X�|�[��
	void SetPlayerLife(int _i);					// �v���C���[�̎c�@��ݒ�
	int GetPlayerLife();						// �v���C���[�̎c�@���擾
	void GameOver();
	Location GetPlayer();
	void CameraUpdate();
};

