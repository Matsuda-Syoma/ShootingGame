#pragma once
#include"common.h"
#include"CharaBase.h"
#include"PAD_INPUT.h"
#include"NwaySpawnerView.h"
class Custom;						// ‘O•ûéŒ¾
class ViewPlayer : public CharaBase
{
private:
	int image;
	int shootdelay = 0;
	NwaySpawnerView* weapon = new NwaySpawnerView;

public:
	ViewPlayer();
	~ViewPlayer();
	void Update(Custom* custom) override;
	void Draw(int camerashake)const override;
};

