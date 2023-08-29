#include"DxLib.h"
#include"common.h"
#include"FPSController.h"
#include"SceneManager.h"
#include"Title.h"
#include"GameMain.h"
#include"InputRanking.h"
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {

	//�^�C�g����ݒ�
	SetMainWindowText("�^�C�g����");

	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(true);

	//�E�B���h�E�T�C�Y�̐ݒ�
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLORBIT);
	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	//DX���C�u�����̏���������
	if (DxLib_Init() == -1)return -1;

	//�`����ʂ𗠂ɂ���i�_�u���o�b�t�@�����O�j
	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager scene = (dynamic_cast<AbstractScene*>(new InputRanking()));

	FpsController FPSct(FRAMERATE, UPDATETIME);

	//�Q�[�����[�v
	while (ProcessMessage() == 0 && scene.Update() != nullptr) {

		PAD_INPUT::UpdateInput();			// PAD�̓��͍X�V
		FPSct.All();

		//��ʂ̏�����
		ClearDrawScreen();
		//�`�揈��
		scene.Draw();
		//����ʂ̓��e��\�ɕ\������
		ScreenFlip();
	}

	//DX���C�u�����̏I������
	DxLib_End();

	return 0;
}
