#include "ship.h"
#include "engine/physics.h"
#include "engine/sound.h"

namespace tesseract::entities
{
	static const float defaultJumpPower = 500.0f;
	static const float defaultGravity = 1300.0f;

	void InitShip(Ship& Player, float startY, const char* texturePath)
	{
		Player.size = { (GetScreenWidth() / 10.0f), (GetScreenHeight() / 15.0f) };
		Player.pos = { (Player.size.x + 30.0f), startY };
		Player.jumpPower = defaultJumpPower;
		Player.gravity = defaultGravity;
		Player.velocity = 0.0f;
		Player.points = 0;
		Player.shipImage = LoadImage(texturePath);
		Player.shipTexture = LoadTextureFromImage(Player.shipImage);
		UnloadImage(Player.shipImage);
	}

	void UnloadShipTexture(Ship& Player)
	{
		UnloadTexture(Player.shipTexture);
	}

	void UpdateShip(Ship& Player, KeyboardKey jumpKey)
	{
		Player.velocity += Player.gravity * GetFrameTime();

		if (IsKeyPressed(jumpKey))
		{
			Player.velocity = -Player.jumpPower;
			engine::PlayJumpP1Sound();
		}

		Player.pos.y += Player.velocity * GetFrameTime();

		if (engine::TopScreenRecCol(Player.pos))
		{
			Player.pos.y = 0.0f;
			Player.velocity = 0.0f;
		}
	}

	void DrawShip(Ship& Player)
	{
		Rectangle source = { 0,0,static_cast<float>(Player.shipTexture.width),static_cast<float>(Player.shipTexture.height) };
		Rectangle destiny = { Player.pos.x,Player.pos.y ,Player.size.x ,Player.size.y };
		Vector2 origin = { 0,0 };
		DrawTexturePro(Player.shipTexture, source, destiny, origin, 0, WHITE);

	}
}
