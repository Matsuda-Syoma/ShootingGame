#pragma once
#include"SphereCollider.h"
class CharaBase : public SphereCollider
{
protected:
	float speed;
	int image;

public:
	virtual void Update() = 0;		// XVˆ—
	virtual void Draw()const = 0;	// •`‰æˆ—
	virtual void Hit() = 0;			// “–‚½‚Á‚½‚Ìˆ—
};

