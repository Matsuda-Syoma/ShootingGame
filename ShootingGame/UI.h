#pragma once
#include "DxLib.h"
#include "common.h"
class UI
{
private:
	int Score;
	int Life;
public:
	UI();
	~UI();
	void Update(int _score, int _life);
	void Draw()const;
};

