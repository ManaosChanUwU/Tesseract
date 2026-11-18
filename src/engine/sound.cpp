#include "raylib.h"
#include "sound.h"


namespace tesseract::engine
{
	Music menuMusic;
	Music gameplayMusic;

	Sound jumpP1Fx;
	Sound EnterGameplayFx;
	Sound collisionFx;
	Sound buttonFx;
	Sound obstaclePassFx;

	void InitAudio()
	{
		menuMusic = LoadMusicStream("res/menuSong.mp3");
		SetMusicVolume(menuMusic, 1.0);
		gameplayMusic = LoadMusicStream("res/inGameSong.ogg");
		SetMusicVolume(gameplayMusic, 0.5);

		jumpP1Fx = LoadSound("res/jump.wav");
		SetSoundVolume(jumpP1Fx, 0.2f);
		EnterGameplayFx = LoadSound("res/enterGameplay.wav");
		SetSoundVolume(EnterGameplayFx, 0.5);
		collisionFx = LoadSound("res/collision.wav");
		SetSoundVolume(collisionFx, 0.5);
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

	void PlayEnterGameplaySound()
	{

		PlaySound(EnterGameplayFx);
	}

	void PlaycollisionSound()
	{
		PlaySound(collisionFx);
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
		UnloadSound(EnterGameplayFx);
		UnloadSound(collisionFx);
		UnloadSound(buttonFx);
		UnloadSound(obstaclePassFx);
	}

}


//Ver libro jacked, es de gta


