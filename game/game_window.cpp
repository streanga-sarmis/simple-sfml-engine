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

#include "game_window.hpp"

Window::Window(unsigned width, unsigned height):
width(width), height(height) {
	window = new sf::RenderWindow(sf::VideoMode(width, height), "Game!");
	window->setFramerateLimit(60);
}

Window::~Window() {
	delete window;
}


sf::RenderWindow* Window::getWindow() const {
	return window;
}