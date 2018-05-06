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
#include <vector>

#include "game_map.hpp"
#include "game_state.hpp"
#include "game_utils.hpp"
#include "game_level.hpp"
#include "game_screen.hpp"
#include "game_button.hpp"
#include "game_textures.hpp"
#include "game_pause_state.hpp"
#include "game_state_machine.hpp"

class PlayState : public State{
private:
	Level* level;
	Textures textures;
	sf::Sprite cursor;

public:
	PlayState(Map* map);
	~PlayState();

	void checkMouseClicked(sf::RenderWindow* window, sf::Event& event) override;
	void update(sf::RenderWindow* window) override;
	void render(sf::RenderWindow* window) override;
};