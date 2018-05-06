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
#include "game_textures.hpp"

#include <iostream>//remove

class Entity {
protected:
	unsigned index; // unique accross entities
	sf::FloatRect bounds;
	sf::Vector2f velocity;

public:
	virtual void touchedEntity(Entity* other) = 0;
	virtual void update(sf::RenderWindow* window, Map& map) = 0;
	virtual void render(sf::RenderWindow* window, Textures& textures) = 0;
	inline void move(int xa, int ya, Map& map) {
		if (xa != 0 && ya != 0) {
			move(xa, 0, map);
			move(0, ya, map);
			return;
		}

		if (canStep(xa, ya, map)) {
			bounds.left += xa;
			bounds.top += ya;
		}
	}

	inline bool bmove(int xa, int ya, Map& map) {
		if (xa != 0 && ya != 0) {
			bmove(xa, 0, map);
			bmove(0, ya, map);
			return true;
		}

		bounds.left += xa;
		bounds.top += ya;
		return canStep(xa, ya, map);
	}

	inline bool canStep(int xa, int ya, Map& map) {
		int x0 = (int)(bounds.left + xa + 10) >> 6;
		int y0 = (int)(bounds.top + ya + 48) >> 6;
		int x1 = (int)((int)(xa + bounds.left + bounds.width - 10) >> 6);
		int y1 = (int)((int)(ya + bounds.top + bounds.height - 10) >> 6);

		for (int y = y0; y <= y1; ++y) {
			for (int x = x0; x <= x1; ++x) {
				if (x < 0 || x >= map.width || y < 0 || y >= map.height) {
					continue;
				}

				if (!map.collisionTiles[x + y * map.width].type) {
					return false;
				}
			}
		}
		return true;
	}

	friend class EntityManager;
	friend class Level;
};