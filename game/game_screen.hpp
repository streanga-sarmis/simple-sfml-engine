//	Copyright (C) 2018 Streanga Sarmis-Stefan<streangasarmis@gmail.com>
//
//	This program is free software : you can redistribute it and / or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation, either version 3 of the License, or
//	(at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with this program, if not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <list>
#include <SFML/Graphics.hpp>

#include "game_utils.hpp"

class Screen {

private:
	static struct sprite {
		sf::Sprite sprt;
		float z;
	};

	static sf::Font font;
	static std::list<sprite> sprites;

public:
	static int xOff;
	static int yOff;

	static void initializeFont();
	static void offset(int xo, int yo);
	static void renderSprite(sf::RenderWindow* window, sf::Texture& texture, float x, float y, float z, int sx, int sy, bool mx = false, bool my = false,
		float rotate = 0, const sf::Color& color = sf::Color::White);
	static void renderSpriteOrig(sf::RenderWindow* window, sf::Texture& texture, float x, float y, float z, int sx, int sy, int width, int height, bool mx = false, bool my = false,
		float rotate = 0, const sf::Color& color = sf::Color::White);
	static void renderRectangle(sf::RenderWindow* window, const sf::Color& color, float x, float y, int w, int h);
	static void renderText(sf::RenderWindow* window, const sf::String& text, int x, int y, int size, const sf::Color& color = sf::Color::White);
	static void sortAndRender(sf::RenderWindow* window);
	static bool depthCompare(const sprite& first, const sprite& second);
	static void renderSpriteNoSort(sf::RenderWindow* window, sf::Texture& texture, float x, float y, int sx, int sy, bool mx = false, bool my = false,
		float rotate = 0, const sf::Color& color = sf::Color::White);
};