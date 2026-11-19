#include "obstacle.h"
#include "engine/color.h"
namespace tesseract::entities
{
	static const float obstWidthRatio = 16.0f;
	static const float obstHeightRatio = 1.5f;
	static const float obstSpeed = 300.0f;
	static const float biggerGapRatio = 3.0f;
	static const float smallestGapRatio = 5.0f;

	static void ResetPos(Obstacle& obstacle);

	void InitObstacle(Obstacle& obstacle)
	{
		obstacle.size = { static_cast<float>(GetScreenWidth()) / obstWidthRatio, static_cast<float>(GetScreenHeight()) / obstHeightRatio };
		obstacle.speed = obstSpeed;
		ResetPos(obstacle);

		obstacle.obstacleTexture = LoadTexture("res/obstacle.png");
		obstacle.obstacleTopTexture = LoadTexture("res/obstacleTop.png");
	}

	void UpdateObstacle(Obstacle& obstacle)
	{
		obstacle.pos.x -= obstacle.speed * GetFrameTime();
		obstacle.topPos.x = obstacle.pos.x;

		if (obstacle.pos.x + obstacle.size.x <= 0)
			ResetPos(obstacle);
	}

	void DrawObstacle(Obstacle& obstacle)
	{


		DrawTexturePro(obstacle.obstacleTexture, { 0, 0, static_cast<float>(obstacle.obstacleTexture.width), static_cast<float>(obstacle.obstacleTexture.height) }, { obstacle.pos.x, obstacle.pos.y, obstacle.size.x, obstacle.size.y }, { 0, 0 }, 0.0f, WHITE);
		DrawTexturePro(obstacle.obstacleTopTexture, { 0, 0, static_cast<float>(obstacle.obstacleTopTexture.width), static_cast<float>(obstacle.obstacleTopTexture.height) }, { obstacle.topPos.x, obstacle.topPos.y, obstacle.size.x, obstacle.size.y }, { 0, 0 }, 0.0f, WHITE);
	}

	void ResetPos(Obstacle& obstacle)
	{
		int minY = static_cast<int>(GetScreenHeight() - obstacle.size.y);
		int maxY = static_cast<int>(GetScreenHeight());

		obstacle.pos.y = static_cast<float>(GetRandomValue(minY, maxY));
		obstacle.pos.x = static_cast<float>(GetScreenWidth());

		float minMargin = static_cast<float>(GetScreenHeight()) / biggerGapRatio;
		float maxMargin = static_cast<float>(GetScreenHeight()) / smallestGapRatio;

		obstacle.topPos.y = obstacle.pos.y - obstacle.size.y - GetRandomValue(static_cast<int>(minMargin), static_cast<int>(maxMargin));
		obstacle.topPos.x = obstacle.pos.x;
		obstacle.gotPoints = true;
	}

	void UnloadObstacle(Obstacle& obstacle)
	{
		UnloadTexture(obstacle.obstacleTexture);
		UnloadTexture(obstacle.obstacleTopTexture);
	}


}