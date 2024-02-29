#pragma once
#include"DxLib.h"
#include"AbstractScene.h"
#include"EnemySpawn.h"
#include"Player.h"
#include"Enemy.h"
#include"Bullet.h"
#include"Boom.h"
#include"DeleteCircle.h"
#include"LoadSounds.h"
#include"UI.h"
class GameMain : public AbstractScene
{
private:
	int EnemySpawnTimer;
	int BackGroundTimer;
	int PlayerLife;
	int GameFlg;									// 0���ʏ�A1���Q�[���N���A�A2���Q�[���I�[�o�[
	int MaxEnemy;
	int CamerashakeCount;
	int Camerashake;
	int Grade = 0;
	bool BossFlg;
public:
	ENEMYDATA data[63];
	Enemy* enemy[ENEMY_MAX];
	Bullet* bullet[BULLET_MAX];
	Boom* boom[ENEMY_MAX];
	Player* player;
	DeleteCircle* deletecircle[CIRCLE_MAX];
	UI* ui;
	GameMain();										// �R���X�g���N�^
	~GameMain();									// �f�X�g���N�^

	AbstractScene* Update() override;				// �`��ȊO�̍X�V�����s
	void Draw() const override;						// �`��Ɋւ��邱�Ƃ�����
	void Game();									// �Q�[���̏���
	bool HitCheck();							
	void SpawnBullet(char parentname, SphereCollider* parentcollider, float _angle, int _speed, int _size);
	void SpawnBoom(float _x, float _y);				// ���ꂽ���̃G�t�F�N�g���X�|�[��
	void SpawnCircle(float _x, float _y, int _i);	// ���������~�̃X�|�[��
	void SpawnEnemy();								// �G�̃X�|�[��
	void SetPlayerLife(int _i);						// �v���C���[�̎c�@��ݒ�
	int GetPlayerLife();							// �v���C���[�̎c�@���擾
	Location GetPlayer();
	void CameraUpdate();
	void SetCameraShake
	(int _i);
	void SetScore(int _i);
	void SetGameFlg(int _flg);
	void SetSpawnTime(int _i);
	void SetMaxEnemy();
};

