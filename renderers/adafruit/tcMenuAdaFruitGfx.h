/*
 * Copyright (c) 2018 https://www.thecoderscorner.com (Nutricherry LTD).
 * This product is licensed under an Apache license, see the LICENSE file in the top-level directory.
 */

/**
 * @file tcMenuAdaFruitGfx.h
 * 
 * AdaFruit_GFX renderer that renders menus onto this type of display. This file is a plugin file and should not
 * be directly edited, it will be replaced each time the project is built. If you want to edit this file in place,
 * make sure to rename it first.
 * 
 * LIBRARY REQUIREMENT
 * This library requires the AdaGfx library along with a suitable driver.
 */

#ifndef _TCMENU_TCMENUADAFRUITGFX_H_
#define _TCMENU_TCMENUADAFRUITGFX_H_

#include <tcMenu.h>
#include <tcUtil.h>
#include <BaseRenderers.h>
#include <Adafruit_GFX.h>
#include <gfxfont.h>

extern const char applicationName[];

const uint8_t editingIcon[] PGM_TCM = {
		0b11111111,0b11111111,
		0b01111111,0b11111111,
		0b00011100,0b00000000,
		0b00000111,0b00000000,
		0b00000001,0b1100000,
		0b00000000,0b00111000,
		0b00000000,0b00111000,
		0b00000001,0b11000000,
		0b00000111,0b00000000,
		0b00011100,0b00000000,
		0b01111111,0b11111111,
		0b11111111,0b11111111
};

const uint8_t activeIcon[] PGM_TCM = {
		0b00000000,0b11100000,
		0b00000000,0b11110000,
		0b00000000,0b11111000,
		0b00000000,0b11111100,
		0b00000000,0b11111110,
		0b11111111,0b11111111,
		0b11111111,0b11111111,
		0b00000000,0b11111110,
		0b00000000,0b11111100,
		0b00000000,0b11111000,
		0b00000000,0b11110000,
		0b00000000,0b11100000
};

#define RGB(r, g, b) (uint16_t)( ((r>>3)<<11) | ((r>>2)<<5) | (b>>3) )

/**
 * Defines padding for menu rendering when using the standard AdaGfx renderer. Each
 * position can hold the value 0..15
 */
struct MenuPadding {
	uint16_t top: 4;
	uint16_t bottom: 4;
	uint16_t right: 4;
	uint16_t left: 4;
};

inline void makePadding(MenuPadding& padding, int top, int right, int bottom, int left) {
	padding.top = top; 
	padding.right = right; 
	padding.bottom = bottom; 
	padding.left = left;
}

/**
 * Holds the graphical configuration of how to render a menu based on AdaGfx.
 */
struct AdaColorGfxMenuConfig {
	uint32_t bgTitleColor;
	uint32_t fgTitleColor;
	MenuPadding titlePadding;
	const GFXfont* titleFont;

	uint32_t bgItemColor;
	uint32_t fgItemColor;
	MenuPadding itemPadding;
	const GFXfont* itemFont;

	uint32_t bgSelectColor;
	uint32_t fgSelectColor;

	uint32_t widgetColor;
	MenuPadding widgetPadding;

	uint8_t titleBottomMargin;
	uint8_t titleFontMagnification;
	uint8_t itemFontMagnification;
};

typedef uint32_t Coord;
#define MakeCoord(x, y) ((((long)x)<<16)|y)
#define CoordX(c) (c>>16)
#define CoordY(c) (c&0xffff)

/**
 * A basic renderer that can use the AdaFruit_GFX library to render information onto a suitable
 * display. It is your responsibility to fully initialise and prepare the display before passing
 * it to this renderer.
 */
class AdaFruitGfxMenuRenderer : public BaseMenuRenderer {
private:
	Adafruit_GFX* graphics;
	AdaColorGfxMenuConfig *gfxConfig;
	int16_t xSize, ySize;
	int16_t titleHeight;
public:
	AdaFruitGfxMenuRenderer(Adafruit_GFX* graphics, AdaColorGfxMenuConfig *gfxConfig, int xSize, int ySize, uint8_t bufferSize = 20);
	virtual ~AdaFruitGfxMenuRenderer();
	virtual void render();
private:
	void renderMenuItem(int yPos, int menuHeight, MenuItem* item);
	void renderTitleArea();
	void renderWidgets(bool forceDraw);
	Coord textExtents(const char* text, int16_t x, int16_t y);
};

#endif /* _TCMENU_TCMENUADAFRUITGFX_H_ */
