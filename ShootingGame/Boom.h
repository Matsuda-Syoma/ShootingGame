#pragma once
class Boom
{
private:
	float x, y;					// �`�悷����W
	static int Images[11];
	int ImageCnt;
	int ImageCntDelay;
	const int COUNTDELAY = 2;	// �ҋ@����t���[��
public:
	Boom(float _x, float _y);	// �R���X�g���N�^
	~Boom();					// �f�X�g���N�^
	bool Update();				// �����̍X�V
	void Draw()const;			// �`��̍X�V
	static void LoadImages();	// �摜�̓ǂݍ���
};

