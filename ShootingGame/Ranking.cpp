#include "Ranking.h"

RANKINGDATA Ranking::gRanking[RANKING_DATA];

Ranking::Ranking()
{
}

Ranking::~Ranking()
{
}

void Ranking::SortRanking(void)
{
	int i, j;
	RANKINGDATA work;

	// �I��@�\�[�g
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (gRanking[i].score <= gRanking[j].score) {
				work = gRanking[i];
				gRanking[i] = gRanking[j];
				gRanking[j] = work;
			}
		}
	}

	// ���ʕt��
	for (i = 0; i < RANKING_DATA; i++) {
		gRanking[i].no = 1;
	}
	// ���_�������ꍇ�́A�������ʂƂ���
	// �����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (gRanking[i].score > gRanking[j].score) {
				gRanking[j].no++;
			}
		}
	}
}

void Ranking::SaveRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	// �t�@�C���I�[�v��
	if ((fp = fopen("Resources/data/rankingdata.txt", "w")) == NULL) {
		/* �G���[���� */
		printf("Ranking Data Error\n");

	}

	// �����L���O�f�[�^���z��f�[�^����������
	for (int i = 0; i < RANKING_DATA; i++) {
		fprintf(fp, "%2d %10s %10d\n", gRanking[i].no, gRanking[i].name, gRanking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

}

void Ranking::ReadRanking(void)
{
	FILE* fp = NULL;

	//�t�@�C���I�[�v��
	if (fopen_s(&fp, "Resources/data/rankingdata.txt", "r") != NULL) {
		//�G���[����
		printf("Ranking Data Error\n");
	}

	//�����L���O�f�[�^�z����f�[�^��ǂݍ���
	for (int i = 0; i < RANKING_DATA; i++) {
		fscanf(fp, "%2d %10s %10d", &gRanking[i].no, gRanking[i].name, &gRanking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);
}

void Ranking::Insert(int score, char name[11]) {

	ReadRanking();

	if (gRanking[RANKING_DATA - 1].score < score) {

		gRanking[RANKING_DATA - 1].score = score;
		for (int i = 0; i < NAME_MAX; i++) {
			gRanking[RANKING_DATA - 1].name[i] = name[i];
			SortRanking();
			SaveRanking();
		}
	}
}

RANKINGDATA Ranking::GetData(int i)
{
	return gRanking[i];
}
