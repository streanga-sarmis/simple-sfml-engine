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

#include "game_button.hpp"

Button::Button(const char* text, int x, int y, int w, int h, void(*Function)()):
text(text), function(Function), functionWindow(nullptr){
	bounds.left = x;
	bounds.top = y;
	bounds.width = w;
	bounds.height = h;
	textBounds.width = this->text.getSize() * 24;
	textBounds.height = 24;
	textBounds.left = ((bounds.width / 2) + bounds.left) - (this->text.getSize() * 24) / 4;
	textBounds.top = (bounds.height / 2) + bounds.top - 24 / 2;
}

Button::Button(const char* text, int x, int y, int w, int h, void(*Function)(sf::RenderWindow*)) :
text(text), function(nullptr), functionWindow(Function) {
	bounds.left = x;
	bounds.top = y;
	bounds.width = w;
	bounds.height = h;
	textBounds.width = this->text.getSize() * 24;
	textBounds.height = 24;
	textBounds.left = ((bounds.width / 2) + bounds.left) - textBounds.width / 4;
	textBounds.top = (bounds.height / 2) + bounds.top - textBounds.height / 2;
}

Button::~Button() {

}

bool Button::checkBounds(sf::Event& event) {
	return (bounds.intersects(sf::IntRect(sf::Vector2i(event.mouseButton.x, event.mouseButton.y), sf::Vector2i(1, 1))));
}

void Button::render(sf::RenderWindow* window) {
	Screen::renderRectangle(window, sf::Color(100, 0, 100), bounds.left, bounds.top, bounds.width, bounds.height);
	Screen::renderText(window, text, textBounds.left, textBounds.top, 24);
}

void Button::exec(sf::RenderWindow* window) {
	(*functionWindow)(window);
}

void Button::exec() {
	(*function)();
}