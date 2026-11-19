#include "raylib.h"
#include "engine/fonts.h"

namespace tesseract::engine
{
	Font mainFont;
	Font secondFont;

	void initFonts()
	{
		mainFont = LoadFontEx("res/fonts/METALG.TTF", 150, 0, 0);
		//SetTextureFilter(mainFont.texture, TEXTURE_FILTER_TRILINEAR);
		secondFont = LoadFont("res/fonts/Inter.ttf");
	}

	void unloadFonts()
	{
		UnloadFont(mainFont);
		UnloadFont(secondFont);
	}
}