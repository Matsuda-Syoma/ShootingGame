#include "DrawRanking.h"
#include "TItle.h"

DrawRanking::DrawRanking()
{
	Ranking::ReadRanking();
}

AbstractScene* DrawRanking::Update()
{
	// Aボタンでタイトルへ
	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_A))
	{
		return new Title();
	}
	return this;
}

void DrawRanking::Draw() const
{
	DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x8888ff, true);
	SetFontSize(48);
	for (int i = 0; i < RANKING_DATA; i++) {
		DrawFormatString(290, 300 + i * 50, 0x000000,"%2d %-10s %10d",Ranking::GetData(i).no,Ranking::GetData(i).name,Ranking::GetData(i).score);
	}
	DrawString(425, 650, "Aでタイトル", 0x000000);
	SetFontSize(16);
}
