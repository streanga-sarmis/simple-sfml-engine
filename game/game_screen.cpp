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

std::list<Screen::sprite> Screen::sprites;
int Screen::xOff = 0;
int Screen::yOff = 0;
sf::Font Screen::font;

void Screen::initializeFont() { // make a font class for fonts
	if (!font.loadFromFile("res/font/Sansation-Light.ttf")) {
		Util::log("Something went wrong");
	}
}

void Screen::renderSpriteOrig(sf::RenderWindow* window, sf::Texture& texture, float x, float y, float z, int sx, int sy, int width, int height, bool mx, bool my,
	float rotate, const sf::Color& color) {
	sf::Sprite sprite;
	int x1 = x - xOff;
	int y1 = y - yOff;
	int scalex = sx;
	int scaley = sy;

	if (mx) {
		scalex *= -1;
	}

	if (my) {
		scaley *= -1;
	}

	sprite.setTexture(texture);
	sprite.setOrigin(sf::Vector2f(width / 2, height / 2));
	sprite.setPosition(sf::Vector2f(x1, y1));
	sprite.setRotation(rotate);
	sprite.setScale(scalex, scaley);
	sprite.setColor(color);
	Screen::sprite s = {sprite, z};
	sprites.emplace_back(s);
	//window->draw(sprite);
}

void Screen::renderSprite(sf::RenderWindow* window, sf::Texture& texture, float x, float y, float z, int sx, int sy, bool mx, bool my,
	float rotate, const sf::Color& color) {
	sf::Sprite sprite;
	float x1 = x - xOff;
	float y1 = y - yOff;
	int scalex = sx;
	int scaley = sy;

	if (mx) {
		scalex *= -1;
	}

	if (my) {
		scaley *= -1;
	}

	sprite.setScale(scalex, scaley);
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(x1, y1));
	sprite.setRotation(rotate);
	sprite.setColor(color);
	Screen::sprite s = { sprite, z };
	sprites.emplace_back(s);
	//window->draw(sprite);
}

void Screen::renderRectangle(sf::RenderWindow* window, const sf::Color& color, float x, float y, int w, int h) {
	sf::RectangleShape rectangle;
	float x1 = x - xOff;
	float y1 = y - yOff;
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

void Screen::renderSpriteNoSort(sf::RenderWindow* window, sf::Texture& texture, float x, float y, int sx, int sy, bool mx, bool my,
	float rotate, const sf::Color& color) {
	sf::Sprite sprite;
	float x1 = x - xOff;
	float y1 = y - yOff;
	int scalex = sx;
	int scaley = sy;

	if (mx) {
		scalex *= -1;
	}

	if (my) {
		scaley *= -1;
	}

	sprite.setScale(scalex, scaley);
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(x1, y1));
	sprite.setRotation(rotate);
	sprite.setColor(color);
	window->draw(sprite);
}

void Screen::offset(int xo, int yo) {
	xOff = xo;
	yOff = yo;
}

bool Screen::depthCompare(const Screen::sprite& first, const Screen::sprite& second){
	return ((first.z) < (second.z));
}

void Screen::sortAndRender(sf::RenderWindow* window) {
	sprites.sort(depthCompare);

	for (std::list<Screen::sprite>::iterator it = sprites.begin(); it != sprites.end();) {
		window->draw((*it++).sprt);
	}

	sprites.clear();
}