#include "UI.h"

UI::UI()
{
	Score = 0;
	Life = 2;
	GameFlg = 0;
	UiFlash = 0;
	UiFlashCount = 1;
}

UI::~UI()
{
}

void UI::Update(int _score, int _life, int _gameflg)
{
	Score = _score;
	Life = _life;
	GameFlg = _gameflg;
	if (GameFlg != 0) {
		UiFlash += UiFlashCount;
	}
	if (UiFlash > 60 || UiFlash < 0) {
		UiFlashCount *= -1;
	}

}

void UI::Draw() const
{
	DrawBox(SCREEN_WIDTH - UI_WIDTH, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x00ff00, true);
	SetFontSize(32);
	DrawFormatString(SCREEN_WIDTH - UI_WIDTH + 50, 50, 0x000000, "Score");
	DrawFormatString(SCREEN_WIDTH - UI_WIDTH + 50, 100, 0x000000, "%06d", Score);

	DrawFormatString(SCREEN_WIDTH - UI_WIDTH + 50, 200, 0x000000, "Life");
	for (int i = 0; i < Life + 1; i++) {
		DrawCircle(SCREEN_WIDTH - UI_WIDTH + 50 + i * 40, 250, 10, 0x000000, true);
	}

	if (GameFlg != 0) {
		DrawBox(UISIZE, (UISIZE * 2), SCREEN_WIDTH - UI_WIDTH - UISIZE, SCREEN_HEIGHT - (UISIZE * 2), 0x000000, true);
		DrawBox(UISIZE + 5, (UISIZE * 2) + 5, SCREEN_WIDTH - UI_WIDTH - UISIZE - 5, SCREEN_HEIGHT - (UISIZE * 2) - 5, 0x00ff00, true);
		DrawBox(UISIZE + 10, (UISIZE * 2) + 10, SCREEN_WIDTH - UI_WIDTH - UISIZE - 10, SCREEN_HEIGHT - (UISIZE * 2) - 10, 0x000000, true);
		DrawBox(UISIZE + 15, (UISIZE * 2) + 15, SCREEN_WIDTH - UI_WIDTH - UISIZE - 15, SCREEN_HEIGHT - (UISIZE * 2) - 15, 0xffffff, true);
		DrawFormatString(UISIZE + 250, 330, 0x000000, "Score :");
		DrawFormatString(UISIZE + 400, 330, 0x000000, "%06d", Score);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, UiFlash * 4);
		DrawFormatString(UISIZE + 260, 370, 0x000000, "Aƒ{ƒ^ƒ“‚ÅŽŸ‚Ö");
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	SetFontSize(16);
}
