#include "gameplay.h"
#include "entities/ship.h"
#include "entities/obstacle.h"
#include "entities/background.h"
#include "engine/physics.h"
#include "scene_manager.h"
#include "engine/sound.h"
#include "engine/fonts.h"
#include "engine/color.h"

namespace tesseract::scenes
{
	static entities::Ship P1;
	static entities::Ship P2;
	static entities::Obstacle Obs;
	static bool isGameOver;
	static bool twoPlayers = false;
	static bool isGameStarted = false;
	static const int fontSize = 30;
	static const char* loseMessage = "GAME OVER - Press enter to retry.\nPress ESC to go back to the menu.";
	static const char* playerOneWin = "Gano el jugador 1 - Press enter to retry.\nPress ESC to go back to the menu.\n";
	static const char* playerTwoWin = "Gano el jugador 2 - Press enter to retry.\nPress ESC to go back to the menu.\n";
	static const char* tieMessage = "EMPATE - Ambos jugadores perdieron.\nPress enter to retry.\nPress ESC to go back to the menu.";
	static const char* gameOverMessage;
	static const char* initGameMessageP1 = "Press SPACEBAR to start";
	static const char* initGameMessageP2 = "Press SPACEBAR or UP ARROW to start";


	void SetTwoPlayers(bool enable)
	{
		twoPlayers = enable;
	}


	void InitGameplay()
	{
		isGameOver = false;
		isGameStarted = false;
		float screenHeigth = static_cast<float>(GetScreenHeight());
		entities::InitShip(P1, screenHeigth * 0.3f, "res/shipP1.png");
		entities::InitObstacle(Obs);
		entities::InitBackground();
		if (twoPlayers)
		{
			entities::InitShip(P2, screenHeigth * 0.4f, "res/shipP2.png");
		}
	}

	void UpdateGameplay()
	{


		if (!isGameOver)
		{
			if (!isGameStarted)
			{
				if (IsKeyPressed(KEY_SPACE))
				{
					isGameStarted = true;
				}
				if (twoPlayers)
				{
					if (IsKeyPressed(KEY_UP))
					{
						isGameStarted = true;

					}
				}
			}
			else
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


				bool playerOneLost = engine::CollisionRecRec(P1.pos, P1.size, Obs.pos, Obs.size) || engine::CollisionRecRec(P1.pos, P1.size, Obs.topPos, Obs.size) || P1.pos.y - P1.size.y > GetScreenHeight();

				bool playerTwoLost = false;

				if (twoPlayers)
				{
					playerTwoLost = engine::CollisionRecRec(P2.pos, P2.size, Obs.pos, Obs.size) || engine::CollisionRecRec(P2.pos, P2.size, Obs.topPos, Obs.size) || P2.pos.y - P2.size.y > GetScreenHeight();
				}

				if (playerOneLost || playerTwoLost)
				{
					isGameOver = true;
					engine::PlaycollisionSound();

					if (twoPlayers)
					{
						if (playerOneLost && playerTwoLost)
						{
							gameOverMessage = tieMessage;
						}
						else if (playerOneLost)
						{
							gameOverMessage = playerTwoWin;
						}
						else
						{
							gameOverMessage = playerOneWin;
						}
					}
					else
					{
						gameOverMessage = loseMessage;
					}
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
			entities::UnloadObstacle(Obs);
			ChangeScene(Menu);
		}
	}

	void DrawGameplay()
	{
		entities::DrawBackground();
		entities::DrawShip(P1);
		if (twoPlayers)
		{
			entities::DrawShip(P2);
		}
		entities::DrawObstacle(Obs);
		DrawTextEx(engine::secondFont, TextFormat("POINTS: %i", P1.points), { 10, 10 }, 48, 0, mainStuffColor);

		if (!isGameStarted)
		{
			if (!twoPlayers)
			{
				static float initGameTextLength = MeasureTextEx(engine::secondFont, initGameMessageP1, static_cast<float>(fontSize), 0.0f).x;
				static float x = static_cast<float>(GetScreenWidth() - initGameTextLength) / 3;
				static float y = static_cast<float>(GetScreenHeight() - fontSize) / 2;
				DrawTextEx(engine::secondFont, initGameMessageP1, { x, y }, fontSize, 0, gameOverColor);
			}
			else if (twoPlayers)
			{
				static float initGameTextLength = MeasureTextEx(engine::secondFont, initGameMessageP2, static_cast<float>(fontSize), 0.0f).x;
				static float x = static_cast<float>(GetScreenWidth() - initGameTextLength) / 3;
				static float y = static_cast<float>(GetScreenHeight() - fontSize) / 2;
				DrawTextEx(engine::secondFont, initGameMessageP2, { x, y }, fontSize, 0, gameOverColor);
			}
		}

		if (isGameOver)
		{
			static float gameOverLength = MeasureTextEx(engine::secondFont, loseMessage, static_cast<float>(fontSize), 0.0f).x;
			static float x = static_cast<float>(GetScreenWidth() - gameOverLength) / 3;
			static float y = static_cast<float>(GetScreenHeight() - fontSize) / 2;

			DrawTextEx(engine::secondFont, gameOverMessage, { x, y }, fontSize, 0, gameOverColor);
		}
	}

}