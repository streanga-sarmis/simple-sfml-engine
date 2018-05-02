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

#include <SFML/Graphics.hpp>

#include "game_utils.hpp"

class Screen {

private:
	static int xOff;
	static int yOff;
	static sf::Font font;

public:
	void static initializeFont();
	void static offset(int xo, int yo);
	void static renderSprite(sf::RenderWindow* window, sf::Texture& texture, int x, int y, int sx, int sy);
	void static renderRectangle(sf::RenderWindow* window, const sf::Color& color, int x, int y, int w, int h);
	void static renderText(sf::RenderWindow* window, const sf::String& text, int x, int y, int size);
};