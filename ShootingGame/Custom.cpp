#include "Custom.h"
#include "TItle.h"

Custom::Custom()
{
	player = new ViewPlayer();
}

AbstractScene* Custom::Update()
{
	player->Update(this);
	// Aボタンでタイトルへ
	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_A))
	{
		return new Title();
	}

	// 弾の更新
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] != nullptr) {

			// 弾の更新処理
			if (!bullet[i]->Update()) {
				bullet[i] = nullptr;
				delete bullet[i];
			}
		}
	}

	return this;
}

void Custom::Draw() const
{
	DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x8888ff, true);
	DrawBox(40, 40, 280, 440, 0x003166, true);
	// 弾の描画
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] != nullptr) {
			bullet[i]->Draw();
		}
	}
	player->Draw(0);
	SetFontSize(48);
	DrawString(425, 650, "Aでタイトル", 0x000000);
	SetFontSize(16);
}

// 弾の出現
void Custom::SpawnBullet(char parentname, SphereCollider* parentcollider, float _angle, int _speed, int _size) {
	// 弾がnullptrだったら生成してループを抜ける
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet[i] == nullptr) {
			bullet[i] = new Bullet(parentname, parentcollider->GetLocation().x, parentcollider->GetLocation().y, _angle, _speed, _size);
			bullet[i]->SetDeleteScreen(40, 44, 280, 440);
			break;
		}
	}
}