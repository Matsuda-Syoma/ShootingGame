#include "EnemySpawn.h"
#include "DxLib.h"

ENEMYDATA EnemySpawn::data[63];

EnemySpawn::EnemySpawn()
{
	int fp;
	char buf[100];
	char c;
	int a;
	int col = 1;	// ��
	int row = 0;	// �s
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

			// �o���^�C�~���O
		case 3:
			data[row].SpawnTime = atoi(buf);
			break;

			// �p�x
		case 4:
			data[row].angle = atoi(buf);
			break;

			// �G�X�s�[�h
		case 5: 
			data[row].speed = atoi(buf);
			break;

			// �e�X�s�[�h
		case 6:
			data[row].Bspeed = atoi(buf);
			break;

			// HP
		case 7:
			data[row].hp = atoi(buf); 
			break;
		// �X�R�A
		case 8:
			data[row].score = atoi(buf);
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
	//for (int i = 0; i < row; i++) {
	//	printfDx("[%d][%d][%d][%d][%d][%d][%d]\n", data[i].x, data[i].y, data[i].SpawnTime, data[i].angle, data[i].speed, data[i].Bspeed, data[i].hp);
	//}
	FileRead_close(fp);
}


EnemySpawn::~EnemySpawn()
{
}

ENEMYDATA EnemySpawn::LoadEnemy(int i)
{
	return data[i];
}
