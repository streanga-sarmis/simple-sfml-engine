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

#include <list>
#include <iostream>//remove
#include <SFML/Graphics.hpp>

#include "game_map.hpp"
#include "game_item.hpp"
#include "game_textures.hpp"
#include "game_wearing_entity.hpp"

class ItemManager {

private:
	static std::list<Item*>* itemsInTiles;

public:
	static std::list<Item*> onHand; // very good naming...
	static std::list<Item*> offHand;
	static void initializeItemMapping(Map& map);
	static void addItem(Item* item);
	static void checkCollisions(WearingEntity* th, Map& map);
	static void removeItem(Item* item);
	static void updateOffHand(Map& map);
	static void updateOnHand(Map& map);
	static void renderOffHand(sf::RenderWindow* window, Textures& textures, int x0, int y0, int x1, int y1);
	static void renderOnHand(sf::RenderWindow* window, Textures& textures, int x0, int y0, int x1, int y1);
	static void clearItems();
	
};