#include "raylib.h"
#include "sound.h"
#include <iostream>
using namespace std;//TODO quitar

void playMainMenuMusic()
{

	Music mainMenuMusic = LoadMusicStream("res/inGameSong.wav");
	PlayMusicStream(mainMenuMusic);
}

//updatemusicstream

//Ver libro jacked


void playColitionSound()
{
	Sound colitionFx = LoadSound("res/colition.wav");
	PlaySound(colitionFx);
	UnloadSound(colitionFx);
	cout << "audio de colision";
}