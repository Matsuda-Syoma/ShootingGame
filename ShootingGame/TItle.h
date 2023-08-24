#pragma once
#include"DxLib.h"
#include"common.h"
#include"AbstractScene.h"
#include"PAD_INPUT.h"
class Title : public AbstractScene
{
private:
	int Select;
	bool Once = TRUE;
public:
	Title();
	AbstractScene* Update() override;				// 描画以外の更新を実行
	void Draw() const override;						// 描画に関することを実装
};

