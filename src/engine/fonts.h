#pragma once
#include "raylib.h"

namespace tesseract::engine
{
	extern Font mainFont;
	extern Font secondFont;

	void initFonts();
	void unloadFonts();
}