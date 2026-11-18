#pragma once

namespace tesseract::engine
{
	void InitAudio();
	void UpdateAudio();

	void PlayMenuMusic();
	void PlayGameplayMusic();

	void PlayJumpP1Sound();
	void PlayEnterGameplaySound();
	void PlaycollisionSound();
	void PlayButtonSound();
	void PlayObstaclePassSound();

	void UnloadAudio();
}