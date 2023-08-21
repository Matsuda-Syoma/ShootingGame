#include "LoadSounds.h"
#include "DxLib.h"
int Sounds::BGM_Game;
int Sounds::SE_Break;
int Sounds::SE_Shoot;
int Sounds::SE_Hit;
int Sounds::SE_PlayerHit;
void Sounds::LoadSounds() {
	BGM_Game = LoadSoundMem("Resources/sounds/BGM_Trip.wav");
	SE_Break = LoadSoundMem("Resources/sounds/SE_Break.mp3");
	SE_Shoot = LoadSoundMem("Resources/sounds/SE_Shoot.mp3");
	SE_Hit = LoadSoundMem("Resources/sounds/SE_Hit.mp3");
	SE_PlayerHit = LoadSoundMem("Resources/sounds/SE_PlayerHit.mp3");
}

void Sounds::AllStop() {

}