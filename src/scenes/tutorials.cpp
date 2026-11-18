#include <raylib.h>
#include "tutorials.h"
#include "engine/button.h"
#include "scenes/scene_manager.h"
#include "engine/sound.h"

namespace tesseract::scenes
{
	static const float buttonWidthRatio = 5.0f;
	static const float buttonHeightRatio = 12.0f;
	static const float buttonSpacingRatio = 36.0f;
	static const float buttonFontRatio = 24.0f;
	static const Color buttonColor = DARKGRAY;
	static const Color buttonTextColor = WHITE;
	static const char* tutorialTextOnePlayer = "Player one = SPACEBAR to jump";
	static const char* tutorialTextTwoPlayers = "Player two = UP ARROW to jump";
	static const char* verText = "v0.4";
	static const int verFontSize = 20;
	static const int verPadding = 10;

	static engine::Button backButton;

	void InitTutorial()
	{
		float screenWidth = static_cast<float>(GetScreenWidth());
		float screenHeight = static_cast<float>(GetScreenHeight());

		Vector2 size = { screenWidth / buttonWidthRatio, screenHeight / buttonHeightRatio };
		float spacing = screenHeight / buttonSpacingRatio;
		int fontSize = static_cast<int>(screenHeight / buttonFontRatio);

		Vector2 pos = { screenWidth - size.x - spacing, screenHeight - size.y - spacing };
		engine::InitButton(backButton, pos, size, "BACK", fontSize, buttonColor, buttonTextColor);
	}

	void UpdateTutorial()
	{
		if (engine::IsButtonClicked(backButton))
		{
			engine::PlayButtonSound();
			ChangeScene(Menu);
		}
	}

	void DrawTutorial()
	{
		engine::DrawButton(backButton);

		static const int verWidth = MeasureText(verText, verFontSize);
		static const int tutorialFontSize = static_cast<int>(GetScreenHeight() / buttonFontRatio);
		static const int tutorialWidth = MeasureText(tutorialTextOnePlayer, tutorialFontSize);

		int creditsX = (GetScreenWidth() - tutorialWidth) / 2;
		int creditsY = (GetScreenHeight() - tutorialFontSize) / 2;

		DrawText(tutorialTextOnePlayer, creditsX, creditsY, tutorialFontSize, WHITE);
		creditsY += (tutorialFontSize);
		DrawText(tutorialTextTwoPlayers, creditsX, creditsY, tutorialFontSize, WHITE);

		DrawText(verText, GetScreenWidth() - verWidth - verPadding, verPadding, verFontSize, RED);
	}
}