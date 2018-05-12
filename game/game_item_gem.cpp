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

#include "game_item_gem.hpp"

Gem::Gem(int x, int y) {
	bounds.left = x;
	bounds.top = y;
	bounds.width = 16;
	bounds.height = 16;

	velocity.x = (std::rand() % 10) * (std::rand() % 2 ? -1 : 1);
	velocity.y = (std::rand() % 10) * (std::rand() % 2 ? -1 : 1);

	frames.initializeAnimation(7, 5);
	currentIcon = std::rand() % 2;

	bonusCurrency = 1;
	bonusAmmo = 0;
	bonusHeath = 0;
	bonusReg = 0;
	bonusSpeed = 0;
}

Gem::~Gem() {
}

void Gem::updateOnGround() {
	if (frames.frames > 0) {
		frames.step();
	}

	oldBounds.x = bounds.left;
	oldBounds.y = bounds.top;

	if (!onHand) {
		if (!followPlayer) {
			if (velocity.x > 0) {
				--velocity.x;
			} else if (velocity.x < 0) {
				++velocity.x;
			}

			if (velocity.y > 0) {
				--velocity.y;
			} else if (velocity.y < 0) {
				++velocity.y;
			}

			if (velocity.x != 0 && velocity.y != 0) {
				bounds.left += velocity.x;
				bounds.top += velocity.y;
			} else {
				followPlayer = !followPlayer;
			}
		} else {
			if (bounds.left < AIManager::getTarget()->position.x) {
				velocity.x = 15;
			} else if (bounds.left > AIManager::getTarget()->position.x) {
				velocity.x = -15;
			}

			if (bounds.top < AIManager::getTarget()->position.y) {
				velocity.y = 15;
			} else if (bounds.top > AIManager::getTarget()->position.y) {
				velocity.y = -15;
			}
			bounds.left += velocity.x;
			bounds.top += velocity.y;
		}
	}
}


void Gem::render(sf::RenderWindow* window, Textures& textures) {
	frames.render(window, (textures.GEMS + currentIcon * 7), bounds.left, bounds.top, 0, 1, 1);
}