#include "CharaBase.h"
#include "DxLib.h"
void CharaBase::Update()
{
}

CharaBase* CharaBase::Draw() const
{
	DrawCircle(location.x, location.y, 5, 0xffffff, true);
}

void CharaBase::Hit()
{
}
