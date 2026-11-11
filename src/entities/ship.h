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
	};

	void InitShip(Ship& Player);
	void UpdateShip(Ship& Player);
	void DrawShip(Ship& Player);
}
