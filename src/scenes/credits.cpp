#include <raylib.h>
#include "credits.h"
#include "engine/button.h"
#include "scenes/scene_manager.h"
#include "engine/sound.h"
#include "engine/fonts.h"
#include "engine/color.h"

namespace tesseract::scenes
{
	static const float buttonWidthRatio = 5.0f;
	static const float buttonHeightRatio = 12.0f;
	static const float buttonSpacingRatio = 36.0f;
	static const float buttonFontRatio = 24.0f;
	static const Color buttonColor = buttonsColor;
	static const Color buttonTextColor = normalTextColor;
	static const char* creditsText = "Game created by: Ivan Abraham\n\nForked by ManaosChan\n\nMusic by Google Flow Music";
	//TODO agregar la ia que hizo la musica, google flow creo que era
	static const char* verText = "v1.0";
	static const float verFontSize = 20;
	static const float verPadding = 10;

	static engine::Button backButton;

	void InitCredits()
	{
		float screenWidth = static_cast<float>(GetScreenWidth());
		float screenHeight = static_cast<float>(GetScreenHeight());

		Vector2 size = { screenWidth / buttonWidthRatio, screenHeight / buttonHeightRatio };
		float spacing = screenHeight / buttonSpacingRatio;
		float fontSize = (screenHeight / buttonFontRatio);

		Vector2 pos = { screenWidth - size.x - spacing, screenHeight - size.y - spacing };
		engine::InitButton(backButton, pos, size, "BACK", fontSize, buttonColor, buttonTextColor);
	}

	void UpdateCredits()
	{
		if (engine::IsButtonClicked(backButton))
		{
			engine::PlayButtonSound();
			ChangeScene(Menu);
		}
	}

	void DrawCredits()
	{
		engine::DrawButton(backButton);

		static const float verWidth = MeasureTextEx(engine::secondFont, verText, verFontSize, 0).x;

		static const float creditsFontSize = static_cast<float>(GetScreenHeight() / buttonFontRatio);

		static const float creditsWidth = MeasureTextEx(engine::secondFont ,creditsText, static_cast<float>(creditsFontSize),0).x;

		float creditsX = (GetScreenWidth() - creditsWidth) / 2;
		float creditsY = (GetScreenHeight() - creditsFontSize) / 2;

		DrawTextEx(engine::secondFont, creditsText,{creditsX,creditsY},creditsFontSize,0, normalTextColor);
		DrawTextEx(engine::secondFont, verText, { verPadding, verPadding }, verFontSize, 0, normalTextColor);

	}
}
