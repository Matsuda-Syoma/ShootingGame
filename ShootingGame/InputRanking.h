#pragma once
#include "DxLib.h"
#include "common.h"
#include "AbstractScene.h"

#define MOZI_ALPHA 88

class InputRanking : public AbstractScene
{
private:
	int MoziSelectCol;		// 列
	int MoziSelectRow;		// 行
	int MoziSize;
	char MoziFrame[11];
	char MoziWork[2];
public:
	InputRanking();
	AbstractScene* Update() override;				// 描画以外の更新を実行
	void Draw() const override;						// 描画に関することを実装
};

