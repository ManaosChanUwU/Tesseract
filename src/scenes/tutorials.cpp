#include <raylib.h>
#include "tutorials.h"
#include "engine/button.h"
#include "scenes/scene_manager.h"
#include "engine/sound.h"
#include "engine/fonts.h"

namespace tesseract::scenes
{
	static const float buttonWidthRatio = 5.0f;
	static const float buttonHeightRatio = 12.0f;
	static const float buttonSpacingRatio = 36.0f;
	static const float buttonFontRatio = 24.0f;
	static const Color buttonColor = DARKGRAY;
	static const Color buttonTextColor = WHITE;
	static const char* tutorialTextOnePlayer = "Player one = SPACEBAR to jump\n\nPlayer two = UP ARROW to jump";
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
		float fontSize = (screenHeight / buttonFontRatio);

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

		static const float verWidth = MeasureTextEx(engine::secondFont ,verText, verFontSize, 5).x;
		static const float tutorialFontSize = static_cast<float>(GetScreenHeight() / buttonFontRatio);
		static const float tutorialWidth = MeasureTextEx(engine::secondFont,tutorialTextOnePlayer, tutorialFontSize,5).x;

		float creditsX = (GetScreenWidth() - tutorialWidth) / 2;
		float creditsY = (GetScreenHeight() - tutorialFontSize) / 2;

		DrawTextEx(engine::secondFont, tutorialTextOnePlayer, { creditsX,creditsY }, tutorialFontSize, 5, SKYBLUE);
		creditsY += (tutorialFontSize);
		DrawTextEx(engine::secondFont, verText, { static_cast<float>(GetScreenWidth() - verWidth - verPadding),verPadding }, verFontSize, 5, SKYBLUE);

	}
}