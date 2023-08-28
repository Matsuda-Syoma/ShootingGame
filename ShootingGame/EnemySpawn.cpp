#include "EnemySpawn.h"
#include "DxLib.h"

ENEMYDATA EnemySpawn::data[63];
int EnemySpawn::row;

// �R���X�g���N�^
EnemySpawn::EnemySpawn()
{
	int fp;
	char buf[100];
	char c;
	int col = 1;	// csv�t�@�C���̗�
	row = 0;		// csv�t�@�C���̍s
	int count = 0;

	memset(buf, 0, sizeof(buf));

	// �t�@�C���̃��[�h
	fp = FileRead_open("Resources/EnemyData.csv");

	// 1�s�ڂ𖳎�����
	while (FileRead_getc(fp) != '\n');

	// �f�[�^�̓ǂݍ���
	while (1) {
		while (1) {

			// �t�@�C����1�������擾�A������ɂ���
			c = FileRead_getc(fp);
			buf[count] = c;

			// �J���}�A���s�AEOF�Ȃ烋�[�v�𔲂���
			if (c == ',' || c == '\n' || c == EOF) {
				buf[count] = '\0';
				break;
			}
			count++;
		}

		// ��̈ʒu�Ő��l������
		switch (col) {

			// X���W
		case 1:	
			data[row].x = atoi(buf);
			break;

			// Y���W
		case 2: 
			data[row].y = atoi(buf);
			break;

			// �p�x
		case 3:
			data[row].angle = atoi(buf);
			break;

			// �G�X�s�[�h
		case 4: 
			data[row].speed = atoi(buf);
			break;

			// HP
		case 5:
			data[row].hp = atoi(buf);
			break;

			// �X�R�A
		case 6:
			data[row].score = atoi(buf);
			break;

			// �o���^�C�~���O
		case 7:
			data[row].SpawnTime = atoi(buf);
			break;

			// �~�܂�^�C�~���O
		case 8:
			data[row].stopframe = atoi(buf);
			break;

			// �e�X�s�[�h
		case 9:
			data[row].Bspeed = atoi(buf);
			break;

			// �e��
		case 10:
			data[row].Bcount = atoi(buf);
			break;

			// ���˃^�C�~���O
		case 11:
			data[row].shootframe = atoi(buf);
			break;

			// �e�̑傫��
		case 12:
			data[row].Bsize = atoi(buf);
			break;

		}

		memset(buf, 0, sizeof(buf));

		// EOF�Ȃ�out�ɔ��
		if (c == EOF) {
			goto out;
		}

		// EOF�ʂ�Ȃ������Ȃ�ǂݍ��ވʒu�����������Ď��̗��ǂ�
		count = 0;
		col++;

		// ���s�Ȃ玟�̍s�ɍs��
		if (c == '\n') {
				col = 1;
				++row;
		}
	}
out:
	FileRead_close(fp);
}


EnemySpawn::~EnemySpawn()
{

}

// �G���̓ǂݍ���
ENEMYDATA EnemySpawn::LoadEnemy(int i)
{
	return data[i];
}

// �ǂݍ��܂ꂽ�G�̗ʂ̎擾
int EnemySpawn::GetMaxEnemy()
{
	return row;
}
