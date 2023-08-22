#pragma once
#include "DxLib.h"
#include "common.h"
class UI
{
private:
	int Score;
	int Life;
	bool GameOverFlg;
	const int UISIZE = 140;
	int UiFlash;
	int UiFlashCount;
public:
	UI();
	~UI();
	void Update(int _score, int _life, bool _gameover);
	void Draw()const;
};

