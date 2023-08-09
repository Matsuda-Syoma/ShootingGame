#pragma once
class Boom
{
private:
	float x, y;
	static int Images[11];
	int ImageCnt;
	int ImageCntDelay;
	const int COUNTDELAY = 2;
public:
	Boom(float _x, float _y);
	~Boom();
	bool Update();
	void Draw()const;
	static void LoadImages();
};

