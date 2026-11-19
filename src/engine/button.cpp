#include "button.h"
#include "engine/physics.h"
#include "engine/fonts.h"
namespace tesseract::engine
{
	void InitButton(Button& button, Vector2 pos, Vector2 size, const char* text, float fontSize, Color color, Color textColor)
	{
		button.pos = pos;
		button.size = size;
		button.text = text;
		button.fontSize = fontSize;
		button.color = color;
		button.textColor = textColor;
	}

	bool IsButtonClicked(const Button& button)
	{
		return CollisionPointRec(GetMousePosition(), button.pos, button.size) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
	}

	void DrawButton(const Button& button)
	{
		DrawRectangleV(button.pos, button.size, button.color);



		float textWidth = MeasureTextEx(engine::secondFont, button.text, button.fontSize, 0).x;

		float textX = button.pos.x + (button.size.x - textWidth) / 2.0f;
		float textY = button.pos.y + (button.size.y - button.fontSize) / 2.0f;

		//DrawText(button.text, textX, textY, button.fontSize, button.textColor);
		DrawTextEx(engine::secondFont, button.text, { textX,textY }, button.fontSize, 0, button.textColor);
	}
}