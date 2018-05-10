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
	bool removed = false;
	sf::Vector2f velocity;

public:
	bool canCollide = true;
	unsigned index; // unique accross entities, remove this
	sf::Vector3f position;
	sf::FloatRect tileCollider;
	sf::FloatRect entityCollider;

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
			position.x += xa;
			position.y += ya;
		}
	}

	inline bool canStep(int xa, int ya, Map& map) {
		int x0 = (int)(tileCollider.left + xa) >> 6; // these things might cause the bullets not getting destroyed in the walls
		int y0 = (int)(tileCollider.top + ya) >> 6; // the bounds might benegative in some cases so its not iterating correctly
		int x1 = (int)((int)(xa + tileCollider.left + tileCollider.width) >> 6);
		int y1 = (int)((int)(ya + tileCollider.top + tileCollider.height) >> 6);

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

	inline void knock(float angle) {
		velocity.x += -std::cos((angle + 90) * 3.14159265359 / 180) * 3;
		velocity.y += -std::sin((angle + 90) * 3.14159265359 / 180) * 3;
	}

	friend class EntityManager;
	friend class Level;
};