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
#include "game_screen.hpp"
#include "game_window.hpp"
#include "game_menu_state.hpp"
#include "game_state_machine.hpp"

class App {
public:
	App();
	~App();

	void run(sf::RenderWindow* window);
	void update(sf::RenderWindow* window, sf::Event& event);
	void render(sf::RenderWindow* window);

};