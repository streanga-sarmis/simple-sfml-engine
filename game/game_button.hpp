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

#include "game_screen.hpp"

typedef void(*Callback)();
typedef void(*CallbackWindow)(sf::RenderWindow*);

class Button {
private:
	sf::String text;
	Callback function;
	CallbackWindow functionWindow;

public:
	sf::IntRect bounds;
	sf::IntRect textBounds;

	Button(const char* text, int x, int y, int w, int h, void(*Function)());
	Button(const char* text, int x, int y, int w, int h, void(*Function)(sf::RenderWindow*));
	// add button with icons, not text, or both
	~Button();

	bool checkBounds(sf::Event& event);
	void render(sf::RenderWindow* window);
	void exec(sf::RenderWindow* window);
	void exec();

};