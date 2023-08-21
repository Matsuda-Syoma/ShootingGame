#include "LoadSounds.h"
#include "DxLib.h"
int Sounds::BGM_Game;
int Sounds::SE_Break;

void Sounds::LoadSounds() {
	BGM_Game = LoadSoundMem("Resources/sounds/BGM_Trip.wav");
	SE_Break = LoadSoundMem("Resources/sounds/SE_Break.mp3");
}

void Sounds::AllStop() {

}