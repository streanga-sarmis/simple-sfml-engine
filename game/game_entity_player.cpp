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

#include "game_entity_player.hpp"

Player::Player() {
	bounds.height = 32;
	bounds.width = 32;
	bounds.left = 500;
	bounds.top = 500;
	velocity.x = 0;
	velocity.y = 0;
}

Player::~Player() {

}

void Player::touchedEntity(Entity* other) {

}

void Player::update(sf::RenderWindow* window, Map& map) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		velocity.x -= 1;
		if (velocity.x < -6) {
			velocity.x = -6;
		}
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		velocity.x += 1;
		if (velocity.x > 6) {
			velocity.x = 6;
		}
	} else {
		if (velocity.x < 0) {
			++velocity.x;
		} else if (velocity.x > 0) {
			--velocity.x;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		velocity.y -= 1;
		if (velocity.y < -6) {
			velocity.y = -6;
		}
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		velocity.y += 1;
		if (velocity.y > 6) {
			velocity.y = 6;
		}
	} else {
		if (velocity.y < 0) {
			++velocity.y;
		} else if (velocity.y > 0) {
			--velocity.y;
		}
	}

	bounds.left += velocity.x;
	bounds.top += velocity.y;
}

void Player::render(sf::RenderWindow* window, Textures& textures) {
	Screen::renderSprite(window, textures.TILES[5], bounds.left, bounds.top, 2, 2);
}