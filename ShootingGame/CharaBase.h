#pragma once
#include"SphereCollider.h"
class GameMain;
class CharaBase : public SphereCollider
{
protected:
	float speed;
	int image;

public:
	virtual void Update(GameMain* gamemain);		// XVˆ—
	virtual void Draw()const;	// •`‰æˆ—
	virtual void Hit();			// “–‚½‚Á‚½‚Ìˆ—
};

