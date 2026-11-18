#pragma once

namespace tesseract::engine
{
	void InitAudio();
	void UpdateAudio();

	void PlayMenuMusic();
	void PlayGameplayMusic();

	void PlayJumpP1Sound();
	void PlayEnterGameplaySound();
	void PlaycolitionSound();
	void PlayButtonSound();
	void PlayObstaclePassSound();

	void UnloadAudio();
}