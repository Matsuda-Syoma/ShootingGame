#include "CharaBase.h"
#include "DxLib.h"
#include"GameMain.h"
void CharaBase::Update(GameMain* gamemain)
{
}

CharaBase::CharaBase()
{
}

void CharaBase::Draw() const
{
}

void CharaBase::Hit()
{
}

bool CharaBase::GetFlg()
{
	return flg;
}

void CharaBase::SetFlg(bool _flg)
{
	flg = _flg;
}
