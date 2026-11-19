#include <raylib.h>
#include "main_menu.h"
#include "engine/button.h"
#include "scenes/scene_manager.h"
#include "gameplay.h"
#include "engine/sound.h"
#include "entities/background.h"
#include "engine/fonts.h"

namespace tesseract::scenes
{
	static const float buttonWidthRatio = 3.0f;
	static const float buttonHeightRatio = 12.0f;
	static const float buttonSpacingRatio = 36.0f;
	static const float buttonFontRatio = 24.0f;
	static const Color buttonColor = DARKGRAY;
	static const Color buttonTextColor = WHITE;

	static const char* verText = "v0.4";
	static const int verFontSize = 20;
	static const int verPadding = 10;

	static const char* title = "tesseract";
	static const int titleFontSize = 100;

	static engine::Button playButton;
	static engine::Button twoPlayersButton;
	static engine::Button tutorial;
	static engine::Button creditsButton;
	static engine::Button exitButton;

	void InitMainMenu()
	{
		
		engine::PlayMenuMusic();
		entities::InitBackground();
		float screenWidth = static_cast<float>(GetScreenWidth());
		float screenHeight = static_cast<float>(GetScreenHeight());

		

		Vector2 size = { screenWidth / buttonWidthRatio, screenHeight / buttonHeightRatio };
		float spacing = screenHeight / buttonSpacingRatio;
		float fontSize = (screenHeight / buttonFontRatio);

		Vector2 pos = { (screenWidth - size.x) / 2, screenHeight / 3 };
		engine::InitButton(playButton, pos, size, "1 PLAYER", fontSize, buttonColor, buttonTextColor);
		
		pos.y += size.y + spacing;
		engine::InitButton(twoPlayersButton, pos, size, "2 PLAYERS", fontSize, buttonColor, buttonTextColor);

		pos.y += size.y + spacing;
		engine::InitButton(tutorial, pos, size, "HOW TO PLAY", fontSize, buttonColor, buttonTextColor);

		pos.y += size.y + spacing;
		engine::InitButton(creditsButton, pos, size, "CREDITS", fontSize, buttonColor, buttonTextColor);

		pos.y += size.y + spacing;
		engine::InitButton(exitButton, pos, size, "EXIT", fontSize, buttonColor, buttonTextColor);
	}

	void UpdateMainMenu()
	{
		
		//TODO agregar fondo al menu, usar las torres de el gameplay original, no las cambiadas
		//TODO cambiar la estetica de los botones
		//TODO cambiar tipografia
		entities::UpdateBackground();
		if (engine::IsButtonClicked(playButton))
		{
			engine::PlayEnterGameplaySound();
			engine::PlayGameplayMusic();
			SetTwoPlayers(false);
			ChangeScene(Game);
		}
		else if (engine::IsButtonClicked(twoPlayersButton))
		{
			engine::PlayEnterGameplaySound();
			engine::PlayGameplayMusic();
			SetTwoPlayers(true);
			ChangeScene(Game);
		}
		else if (engine::IsButtonClicked(tutorial))
		{
			engine::PlayButtonSound();
			ChangeScene(Tutorial);
		}
		else if (engine::IsButtonClicked(creditsButton))
		{
			engine::PlayButtonSound();
			ChangeScene(Credits);
		}
		else if (engine::IsButtonClicked(exitButton))
		{
			engine::PlayButtonSound();
			ChangeScene(Exit);
		}
	}

	void DrawMainMenu()
	{
		float titleWidth = MeasureTextEx(engine::mainFont ,title, titleFontSize, 5).x;
		float titleX = (GetScreenWidth() - titleWidth) / 2.0f;
		float titleY = (GetScreenHeight() * 0.1f);
		Vector2 titleXY = { titleX,titleY };
		DrawTextEx(engine::mainFont, title, titleXY, titleFontSize, 5, PURPLE);
		

		entities::DrawBackground();
		engine::DrawButton(playButton);
		engine::DrawButton(twoPlayersButton);
		engine::DrawButton(tutorial);
		engine::DrawButton(creditsButton);
		engine::DrawButton(exitButton);

		static const int verWidth = MeasureText(verText, verFontSize);

		DrawText(verText, GetScreenWidth() - verWidth - verPadding, verPadding, verFontSize, RED);
	}
}
