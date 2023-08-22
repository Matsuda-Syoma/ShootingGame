#include "UI.h"

UI::UI()
{
	Score = 0;
	Life = 2;

}

UI::~UI()
{
}

void UI::Update(int _score, int _life)
{
	Score = _score;
	Life = _life;
}

void UI::Draw() const
{
	DrawBox(SCREEN_WIDTH - UI_WIDTH, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x00ff00, true);
	SetFontSize(32);
	DrawFormatString(SCREEN_WIDTH - UI_WIDTH + 50, 50, 0x000000, "Score");
	DrawFormatString(SCREEN_WIDTH - UI_WIDTH + 50, 100, 0x000000, "%06d", Score);

	DrawFormatString(SCREEN_WIDTH - UI_WIDTH + 50, 200, 0x000000, "Life");
	for (int i = 0; i < Life; i++) {
		DrawCircle(SCREEN_WIDTH - UI_WIDTH + 50 + i * 40, 250, 10, 0x000000, true);
	}
}
