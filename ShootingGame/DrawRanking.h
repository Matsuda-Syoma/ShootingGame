#pragma once
#include "AbstractScene.h"
#include "common.h"
#include "Ranking.h"
class DrawRanking : public AbstractScene
{
public:
	DrawRanking();
	AbstractScene* Update() override;				// 描画以外の更新を実行
	void Draw() const override;						// 描画に関することを実装
};

