#include "gameplay.h"
#include "entities/ship.h"
#include "entities/obstacle.h"
#include "entities/background.h"
#include "engine/physics.h"
#include "scene_manager.h"

namespace tesseract::scenes
{
	static entities::Ship P1;
	static entities::Ship P2;
	static entities::Obstacle Obs;
	static bool isGameOver;
	static bool twoPlayers = false;
	static const int fontSize = 30;
	static const char* loseMessage = "GAME OVER - Press enter to retry.\nPress ESC to go back to the menu.";

	void SetTwoPlayers(bool twoPlayers)
	{
		twoPlayers = true;
	}


	void InitGameplay()
	{
		isGameOver = false;

		entities::InitShip(P1);
		entities::InitObstacle(Obs);
		entities::InitBackground();
		if (twoPlayers)
		{
			entities::InitShip(P2);
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

			if (engine::CollisionRecRec(P1.pos, P1.size, Obs.pos, Obs.size) || engine::BottomScreenRecCol(P1.pos, static_cast<float>(GetScreenHeight())))
			{
				isGameOver = true;
			}
			if (engine::CollisionRecRec(P1.pos, P1.size, Obs.topPos, Obs.size) || engine::BottomScreenRecCol(P1.pos, static_cast<float>(GetScreenHeight())))
			{
				isGameOver = true;
			}
		}
		else
		{
			if (IsKeyPressed(KEY_ENTER))
				InitGameplay();
		}

		if (IsKeyDown(KEY_ESCAPE))
		{
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

		if (isGameOver)
		{
			static int gameOverLength = MeasureText(loseMessage, fontSize);
			static int x = (GetScreenWidth() - gameOverLength) / 2;
			static int y = (GetScreenHeight() - fontSize) / 2;

			DrawText(loseMessage, x, y, fontSize, RED);
		}
	}
	void SetTwoPlayers(bool twoPlayers)
	{
		twoPlayers = true;
	}
}