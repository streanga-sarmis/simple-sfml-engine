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

#include "game_screen.hpp"

int Screen::xOff = 0;
int Screen::yOff = 0;
sf::Font Screen::font;

void Screen::initializeFont() { // make a font class for fonts
	if (!font.loadFromFile("res/font/Sansation-Light.ttf")) {
		Log::log("Something went wrong");
	}
}

void Screen::renderSprite(sf::RenderWindow* window, sf::Texture& texture, int x, int y, int sx, int sy) {
	sf::Sprite sprite;
	int x1 = x - xOff;
	int y1 = y - yOff;
	sprite.setScale(sx, sy);
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(x1, y1));
	window->draw(sprite);
}

void Screen::renderRectangle(sf::RenderWindow* window, const sf::Color& color, int x, int y, int w, int h) {
	sf::RectangleShape rectangle;
	int x1 = x - xOff;
	int y1 = y - yOff;
	rectangle.setSize(sf::Vector2f(w, h));
	rectangle.setFillColor(color);
	rectangle.setPosition(x1, y1);
	window->draw(rectangle);
}

void Screen::renderText(sf::RenderWindow* window, const sf::String& text, int x, int y, int size, const sf::Color& color) {
	sf::Text render(text, font);
	int x1 = x - xOff;
	int y1 = y - yOff;
	render.setPosition(sf::Vector2f(x1, y1));
	render.setCharacterSize(size);
	render.setFillColor(color);
	window->draw(render);
}

void Screen::offset(int xo, int yo) {
	xOff = xo;
	yOff = yo;
}