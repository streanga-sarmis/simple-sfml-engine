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

#include "game_map.hpp"
#include "game_camera.hpp"
#include "game_entity.hpp"
#include "game_textures.hpp"
#include "game_ai_manager.hpp"
#include "game_item_manager.hpp"
#include "game_entity_player.hpp"
#include "game_entity_manager.hpp"


class Level {
private:
	Map* map;
	Player* player;

public:
	Level(Map* map);
	~Level();
	
	void update(sf::RenderWindow* window);
	void render(sf::RenderWindow* window, Textures& textures);
};
