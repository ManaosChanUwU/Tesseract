#include "gameplay.h"
#include "entities/ship.h"
#include "entities/obstacle.h"
#include "entities/background.h"
#include "engine/physics.h"
#include "scene_manager.h"
#include "engine/sound.h"
#include "engine/fonts.h"

namespace tesseract::scenes
{
	static entities::Ship P1;
	static entities::Ship P2;
	static entities::Obstacle Obs;
	static bool isGameOver;
	static bool twoPlayers = false;
	static const int fontSize = 30;
	static const char* loseMessage = "GAME OVER - Press enter to retry.\nPress ESC to go back to the menu.";
	static const char* playerOneWin = "Gano el jugador 1 - Press enter to retry.\nPress ESC to go back to the menu.\n";
	static const char* playerTwoWin = "Gano el jugador 2 - Press enter to retry.\nPress ESC to go back to the menu.\n";


	void SetTwoPlayers(bool enable)
	{
		twoPlayers = enable;
	}


	void InitGameplay()
	{
		isGameOver = false;
		float screenHeigth = static_cast<float>(GetScreenHeight());
		entities::InitShip(P1, screenHeigth * 0.3f, "res/ship.png");
		entities::InitObstacle(Obs);
		entities::InitBackground();
		if (twoPlayers)
		{
			entities::InitShip(P2, screenHeigth * 0.4f, "res/ship2.png");
		}
	}

	void UpdateGameplay()
	{
		if (!isGameOver)
		{
			entities::UpdateShip(P1, KEY_SPACE);
			if (twoPlayers)
			{
				entities::UpdateShip(P2, KEY_UP);
			}
			entities::UpdateObstacle(Obs);
			entities::UpdateBackground();

			if ((P1.pos.x + P1.size.x) > Obs.pos.x + Obs.size.x && Obs.gotPoints == true)
			{
				Obs.gotPoints = false;
				P1.points++;
				engine::PlayObstaclePassSound();
			}



			if (engine::CollisionRecRec(P1.pos, P1.size, Obs.pos, Obs.size) || P1.pos.y - P1.size.y > GetScreenHeight())
			{
				isGameOver = true;
				engine::PlaycollisionSound();
			}
			if (engine::CollisionRecRec(P1.pos, P1.size, Obs.topPos, Obs.size) || P1.pos.y - P1.size.y > GetScreenHeight())
			{
				isGameOver = true;
				engine::PlaycollisionSound();
			}
			if (twoPlayers)
			{
				if (engine::CollisionRecRec(P2.pos, P2.size, Obs.pos, Obs.size) || P2.pos.y - P2.size.y > GetScreenHeight())
				{
					isGameOver = true;
					engine::PlaycollisionSound();
				}
				if (engine::CollisionRecRec(P2.pos, P2.size, Obs.topPos, Obs.size) || P2.pos.y - P2.size.y > GetScreenHeight())
				{
					isGameOver = true;
					engine::PlaycollisionSound();
				}
			}
		}
		else
		{
			if (IsKeyPressed(KEY_ENTER))
			{
				entities::UnloadShipTexture(P1);
				if (twoPlayers)
				{
					entities::UnloadShipTexture(P2);
				}
				InitGameplay();
			}
		}

		if (IsKeyDown(KEY_ESCAPE))
		{
			ChangeScene(Menu);
		}
	}

	void DrawGameplay()
	{
		entities::DrawBackground();//TODO borrar textura de la nave
		entities::DrawShip(P1);
		if (twoPlayers)
		{
			entities::DrawShip(P2);
		}
		entities::DrawObstacle(Obs);
		DrawTextEx(engine::secondFont, TextFormat("POINTS: %i", P1.points), { 10, 10 } , 48, 0, RED);

		if (isGameOver)
		{
			static float gameOverLength = MeasureTextEx(engine::secondFont,loseMessage, static_cast<float>(fontSize), 0.0f).x;
			static float x = static_cast<float>(GetScreenWidth() - gameOverLength) / 2;
			static float y = static_cast<float>(GetScreenHeight() - fontSize) / 2;

			DrawTextEx(engine::secondFont, loseMessage, { x, y }, fontSize,0, RED);
		}
	}

}