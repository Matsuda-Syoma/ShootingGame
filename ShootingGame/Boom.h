#pragma once
class Boom
{
private:
	float x, y;					// 描画する座標
	static int Images[11];
	int ImageCnt;
	int ImageCntDelay;
	const int COUNTDELAY = 2;	// 待機するフレーム
public:
	Boom(float _x, float _y);	// コンストラクタ
	~Boom();					// デストラクタ
	bool Update();				// 処理の更新
	void Draw()const;			// 描画の更新
	static void LoadImages();	// 画像の読み込み
};

