#include "raylib.h"
#include "sound.h"
//TODO ver - lista de tareas
void playMenuMusic()
{
	Music mainMenuMusic = LoadMusicStream("res/menuSong.mp3");
	PlayMusicStream(mainMenuMusic);
}