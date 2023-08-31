#include "InputRanking.h"
#include "Ranking.h"
#include <string>
#include "DrawRanking.h"

char MoziSmall[] = "abcdefghijklmnopqrstuvwxyz";
char MoziBig[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char MoziNumber[] = "01234567890123456789      ";

InputRanking::InputRanking(int _score)
{
	Score = _score;
	MoziSelectCol = 0;
	MoziSelectRow = 0;
	MoziSize = 48;
	memset(MoziFrame, 0, sizeof(MoziFrame));
	memset(MoziWork, 0, sizeof(MoziWork));
}

AbstractScene* InputRanking::Update()
{
	//右
	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_DPAD_RIGHT)) {
		if (++MoziSelectRow > sizeof(MoziSmall) - 2) {
			MoziSelectRow = 0;
		}
	}
	//左
	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_DPAD_LEFT)) {
		if (--MoziSelectRow < 0) {
			MoziSelectRow = sizeof(MoziSmall) - 2;
		}
	}
	//上
	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_DPAD_UP)) {
		if (--MoziSelectCol < 0) {
			MoziSelectCol = 3;
		}
	}
	//下
	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_DPAD_DOWN)) {
		if (++MoziSelectCol > 3) {
			MoziSelectCol = 0;
		}
	}

	switch (MoziSelectCol)
	{
	case 3:
		// データ入力の終了
		if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_A)) {
			if (strcmp(MoziFrame, " ") != -1) {

				Ranking::Insert(Score, MoziFrame);
				return new DrawRanking();
			}
		}
		break;
	default:

		if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_A) && strlen(MoziFrame) < 10) {
			if (MoziSelectCol == 0) {
				strncpy_s(MoziWork, &MoziSmall[MoziSelectRow], 1);
				strcat_s(MoziFrame, MoziWork);
			}
			if (MoziSelectCol == 1) {
				strncpy_s(MoziWork, &MoziBig[MoziSelectRow], 1);
				strcat_s(MoziFrame, MoziWork);
			}
			if (MoziSelectCol == 2) {
				strncpy_s(MoziWork, &MoziNumber[MoziSelectRow], 1);
				strcat_s(MoziFrame, MoziWork);
			}
		}
		break;
	}

	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_B)) {
		strncpy_s(MoziFrame, MoziFrame, strlen(MoziFrame) - 1);
	}
	return this;
}

void InputRanking::Draw() const
{
	DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x8888ff, true);
	SetFontSize(MoziSize);
	DrawFormatString(340, 100, 0x000000, "ランキングに登録します！");
	DrawFormatString(340, 150, 0x000000, "名前を入力してください！");

	DrawFormatString(720, SCREEN_HEIGHT - MoziSize, 0x000000, "Aで入力、Bで1つ戻る");

	// 文字表示場所
	DrawBox(450, 505, 740, 570, 0x000055, true);
	DrawFormatString(460, 515, 0xffffff, "%s", MoziFrame);
	// 右、左、中央

	// 1段目
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, MOZI_ALPHA);
	SetFontSize(MoziSize);
	if (MoziSelectCol == 0) {
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	DrawFormatString(SCREEN_WIDTH / 2, 300, 0x000000, "%c", MoziSmall[((sizeof(MoziSmall)) + (MoziSelectRow)) % (sizeof(MoziSmall) - 1)]);
	DrawFormatString(SCREEN_WIDTH / 2 - 112, 300, 0x000000, "%c", MoziSmall[((sizeof(MoziSmall)) + (MoziSelectRow - 2)) % (sizeof(MoziSmall) - 1)]);
	SetFontSize(MoziSize + 16);
	DrawFormatString(SCREEN_WIDTH / 2 - (MoziSize + 16), 284, 0x000000, "%c", MoziSmall[MoziSelectRow]);
	if (MoziSelectCol == 0) {
		DrawFormatString(SCREEN_WIDTH / 2 - (MoziSize + 16), 284, 0x88ff00, "%c", MoziSmall[MoziSelectRow]);
	}

	// 2段目
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, MOZI_ALPHA);
	SetFontSize(MoziSize);
	if (MoziSelectCol == 1) {
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	DrawFormatString(SCREEN_WIDTH / 2, 370, 0x000000, "%c", MoziBig[((sizeof(MoziBig)) + (MoziSelectRow)) % (sizeof(MoziBig) - 1)]);
	DrawFormatString(SCREEN_WIDTH / 2 - 112, 370, 0x000000, "%c", MoziBig[((sizeof(MoziBig)) + (MoziSelectRow - 2)) % (sizeof(MoziBig) - 1)]);
	SetFontSize(MoziSize + 16);
	DrawFormatString(SCREEN_WIDTH / 2 - (MoziSize + 16), 354, 0x000000, "%c", MoziBig[MoziSelectRow]);
	if (MoziSelectCol == 1) {
		DrawFormatString(SCREEN_WIDTH / 2 - (MoziSize + 16), 354, 0x88ff00, "%c", MoziBig[MoziSelectRow]);
	}

	// 3段目
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, MOZI_ALPHA);
	SetFontSize(MoziSize);
	if (MoziSelectCol == 2) {
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	DrawFormatString(SCREEN_WIDTH / 2, 440, 0x000000, "%c", MoziNumber[((sizeof(MoziNumber)) + (MoziSelectRow)) % (sizeof(MoziNumber) - 1)]);
	DrawFormatString(SCREEN_WIDTH / 2 - 112, 440, 0x000000, "%c", MoziNumber[((sizeof(MoziNumber)) + (MoziSelectRow - 2)) % (sizeof(MoziNumber) - 1)]);
	SetFontSize(MoziSize + 16);
	DrawFormatString(SCREEN_WIDTH / 2 - (MoziSize + 16), 424, 0x000000, "%c", MoziNumber[MoziSelectRow]);
	if (MoziSelectCol == 2) {
		DrawFormatString(SCREEN_WIDTH / 2 - (MoziSize + 16), 424, 0x88ff00, "%c", MoziNumber[MoziSelectRow]);
	}


	// 4段目
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, MOZI_ALPHA);
	SetFontSize(MoziSize);
	if (MoziSelectCol == 3) {
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawString(555, 585, "End", 0x88ff00);
	}
	else {
		DrawString(555, 585, "End", 0x000000);
	}

	// 設定を戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetFontSize(16);
}
