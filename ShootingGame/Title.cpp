#include "Title.h"
#include "GameMain.h"
#include "DrawRanking.h"
Title::Title()
{
	Select = 0;
}

AbstractScene* Title::Update()
{

	// 十字キー上入力
	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_DPAD_DOWN))
	{
		Select++;
		if (Select > 2)Select = 0;

	}
	// 十字キー下入力
	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_DPAD_UP))
	{
		Select--;
		if (Select < 0)Select = 2;

	}

	// Lスティック上入力
	if (PAD_INPUT::GetPadThumbLY() > 10000 && Once == TRUE)
	{
		Select++;
		if (Select > 2)Select = 0;
		Once = FALSE;
	}

	// Lスティック下入力
	if (PAD_INPUT::GetPadThumbLY() < -10000 && Once == TRUE)
	{
		Select--;
		if (Select < 0)Select = 2;
		Once = FALSE;
	}

	// Lスティックが元に戻されたらOnceをリセット
	if (Once == FALSE && PAD_INPUT::GetPadThumbLY() < 10000 && PAD_INPUT::GetPadThumbLY() > -10000)
	{
		Once = TRUE;
	}


	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_A)) {

		switch (Select) {

		case 0:
			return new GameMain();
			break;
		case 1:
			return new DrawRanking();
			break;
		case 2:
			return nullptr;
			break;
		}
	}
	return this;
}

void Title::Draw() const
{
	DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x8888ff, true);
	SetFontSize(48);
	DrawFormatString(480, 100, 0x000000, "ShootingGame");
	DrawString(520, 240, "START", 0x000000);
	DrawString(520, 320, "RANKING", 0x000000);
	DrawString(520, 400, "END", 0x000000);
	SetFontSize(16);
	DrawTriangle(470, 245 + Select * 80, 500, 265 + Select * 80, 470, 285 + Select * 80, 0xff0000, TRUE);
}
