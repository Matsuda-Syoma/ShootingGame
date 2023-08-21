#pragma once
class Sounds
{
public:
	static int BGM_Game;
	static int SE_Break;
	static int SE_Shoot;
	static int SE_Hit;
	static int SE_PlayerHit;

	static void LoadSounds();
	static void AllStop();
};

