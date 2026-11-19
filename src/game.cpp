#include "game.h"
#include <raylib.h>
#include "scenes/scene_manager.h"
#include "engine/sound.h"
#include "engine/fonts.h"
#include "engine/color.h"
#include "entities/obstacle.h"


namespace tesseract
{
	static void InitGame();
	static void UpdateGame();
	static void DrawGame();

	void Run()
	{		
		InitGame();
		while (!WindowShouldClose() && !scenes::ShouldExit())
		{
			UpdateGame();

			DrawGame();
		}
		engine::unloadFonts();
		engine::UnloadAudio();
		CloseAudioDevice();
		CloseWindow();
	}

	void InitGame()
	{
		static Vector2 screenSize = { 1280, 720 };
		InitWindow(static_cast<int>(screenSize.x), static_cast<int>(screenSize.y), "TESSERACT");
		InitAudioDevice();
		engine::InitAudio();
		engine::initFonts();
		//Primero crea la ventana, despues inicia el dispositivo de audio y despues carga los sonidoslmao
		SetExitKey(KEY_NULL);

		scenes::ChangeScene(scenes::Menu);
	}

	void UpdateGame()
	{
		scenes::UpdateScene();
		engine::UpdateAudio();
	}

	void DrawGame()
	{
		BeginDrawing();
		
		ClearBackground(mainBackgroundColor);

		scenes::DrawScene();

		EndDrawing();
	}
}
