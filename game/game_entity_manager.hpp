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

#define MAXIMUM_SIZE 65536 // 256 * 256

#include <list>

#include "game_map.hpp"
#include "game_utils.hpp"
#include "game_entity.hpp"
#include "game_textures.hpp"

class EntityManager {
public:
	static std::list<Entity*> entities;
	static std::list<Entity*>* entitiesInTiles;

	static void addEntity(Entity* e);
	static void removeEntity(Entity* e);
	static void checkCollisions(Entity* th, Map& map);
	static void clearEntities();
	static void initializeEntityMapping(Map& map);
	static void update(sf::RenderWindow* windowm, Map& map);
	static void render(sf::RenderWindow* window, Textures& textures, int x0, int y0, int x1, int y1);
};