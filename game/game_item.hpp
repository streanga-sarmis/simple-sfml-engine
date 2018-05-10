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

#include "game_textures.hpp"

class Item {
public:
	// add the pickup interval here, not on the entity part
	sf::Vector2f oldBounds;
	sf::Vector2f velocity;
	sf::FloatRect bounds;
	float z;
	float gravity = 0.98;
	bool removed = false;
	bool mirrorX = false;
	bool onHand = false;
	int bonusReg;
	int bonusAmmo;
	int bonusHeath;
	int bonusSpeed;
	float angle;

	inline void setOnHand(bool onHand) {
		this->onHand = onHand;
	}

	virtual void use() = 0;

	inline void update() {
		oldBounds.x = bounds.left;
		oldBounds.y = bounds.top;

		if (!onHand) {
			if (velocity.x < 4) {
				if (velocity.y > 10) {
					velocity.y *= -0.9;
				} else {
					velocity.y += gravity;
				}
				velocity.x += 0.1;
				bounds.left += velocity.x;
				bounds.top += velocity.y;
			}
		}
	}

	virtual void update(const sf::Vector3f& position, float angle, bool mirrorX) = 0;
	virtual void render(sf::RenderWindow* window, Textures& textures) = 0;
};