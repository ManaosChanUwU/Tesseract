#include "raylib.h"
#include "sound.h"


namespace tesseract::engine
{
	Music menuMusic;
	Music gameplayMusic;

	Sound jumpP1Fx;
	Sound jumpP2Fx;
	Sound colitionFx;
	Sound buttonFx;
	Sound obstaclePassFx;

	void InitAudio()
	{
		menuMusic = LoadMusicStream("res/menuSong.mp3");
		SetMusicVolume(menuMusic, 0.5);
		gameplayMusic = LoadMusicStream("res/inGameSong.wav");
		SetMusicVolume(gameplayMusic, 0.5);

		jumpP1Fx = LoadSound("res/jump.wav");
		SetSoundVolume(jumpP1Fx, 0.5);
		jumpP2Fx = LoadSound("res/playerTwoJump.wav");
		SetSoundVolume(jumpP2Fx, 0.5);
		colitionFx = LoadSound("res/colition.wav");
		SetSoundVolume(colitionFx, 0.5);
		buttonFx = LoadSound("res/button.wav");
		SetSoundVolume(buttonFx, 0.5);
		obstaclePassFx = LoadSound("res/obstaclePass.wav");
		SetSoundVolume(obstaclePassFx, 0.5);

		menuMusic.looping = true;
		gameplayMusic.looping = true;
	}

	void UpdateAudio()
	{
		UpdateMusicStream(menuMusic);
		UpdateMusicStream(gameplayMusic);
	}

	void PlayMenuMusic()
	{
		StopMusicStream(gameplayMusic);
		PlayMusicStream(menuMusic);
	}

	void PlayGameplayMusic()
	{
		StopMusicStream(menuMusic);
		PlayMusicStream(gameplayMusic);
	}

	void PlayJumpP1Sound()
	{
		PlaySound(jumpP1Fx);
	}

	void PlayJumpP2Sound()
	{
		PlaySound(jumpP2Fx);
	}

	void PlaycolitionSound()
	{
		PlaySound(colitionFx);
	}

	void PlayButtonSound()
	{
		PlaySound(buttonFx);
	}

	void PlayObstaclePassSound()
	{
		PlaySound(obstaclePassFx);
	}

	void UnloadAudio()
	{
		StopMusicStream(menuMusic);
		StopMusicStream(gameplayMusic);

		UnloadMusicStream(menuMusic);
		UnloadMusicStream(gameplayMusic);

		UnloadSound(jumpP1Fx);
		UnloadSound(jumpP2Fx);
		UnloadSound(colitionFx);
		UnloadSound(buttonFx);
		UnloadSound(obstaclePassFx);
	}

}


//Ver libro jacked, es de gta


