#pragma once
#include "common.h"

class EnemySpawn
{
private:

	static ENEMYDATA data[63];			// �G�̐��̍ő吔
	static int row;						// csv�t�@�C���̗�̐�(�ǂݍ��܂��G�̗�)
public:
	EnemySpawn();						// �R���X�g���N�^
	~EnemySpawn();						// �f�X�g���N�^
	static ENEMYDATA LoadEnemy(int i);	// �G���̓ǂݍ���
	static int GetMaxEnemy();			// �ǂݍ��܂ꂽ�G�̗ʂ̎擾
};