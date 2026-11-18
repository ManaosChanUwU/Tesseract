#pragma once
#include <raylib.h>

namespace tesseract::entities
{
	struct Ship
	{
		Vector2 size;
		Vector2 pos;
		float velocity;
		float gravity;
		float jumpPower;
		Image shipImage;
		Texture2D shipTexture;
		int points;
	};

	void InitShip(Ship& Player, float startY, const char* texturePath);
	void UnloadShipTexture(Ship& Player);
	void UpdateShip(Ship& Player, KeyboardKey jumpKey);
	void DrawShip(Ship& Player);
}
