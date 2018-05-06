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
float x, y, angle;
Player::Player() {
	IDLE.initializeAnimation(4, 10);
	WALK.initializeAnimation(7, 5);
	bounds.height = 72;
	bounds.width = 72;
	bounds.left = 500;
	bounds.top = 500;
	velocity.x = 0;
	velocity.y = 0;
	mirrorX = false;
	walking = false;
}

Player::~Player() {

}

void Player::touchedEntity(Entity* other) {

}

void Player::update(sf::RenderWindow* window, Map& map) {
	x = sf::Mouse::getPosition(*window).x + Screen::xOff;
	y = sf::Mouse::getPosition(*window).y + Screen::yOff;

	angle = -((std::atan2(bounds.left + 48 - x, bounds.top + 48 - 16 - y) * 180 / 3.14159265359));

	if (!walking) {
		IDLE.step();
	} else {
		WALK.step();
	}

	velocity.x = 0;
	velocity.y = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		velocity.x = -6;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		velocity.x = +6;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		velocity.y = -6;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		velocity.y = +6;
	}


	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		Camera::shake();
		EntityManager::addEntity(new BigBullet(this, bounds.left + 48 - (24 * (mirrorX ? 1 : 0)), bounds.top + 48, angle));
	}

	if (velocity.x != 0 || velocity.y != 0) {
		move(velocity.x, velocity.y, map);
		walking = true;
	} else {
		walking = false;
	}
	

	if (velocity.x < 0) {
		mirrorX = true;
	}

	if (velocity.x > 0) {
		mirrorX = false;
	}

	if (angle < 0) {
		mirrorX = true;
	}

	if (angle > 0) {
		mirrorX = false;
	}
}

void Player::render(sf::RenderWindow* window, Textures& textures) {
	Screen::renderSprite(window, textures.SHADOW, bounds.left, bounds.top, 3, 3);
	if (!walking) {
		IDLE.render(window, textures.PLAYER_IDLE, bounds.left + (mirrorX ? bounds.width : 0), bounds.top, 3, 3, mirrorX);
	} else {
		WALK.render(window, textures.PLAYER_WALK, bounds.left + (mirrorX ? bounds.width : 0), bounds.top, 3, 3, mirrorX);
	}
	Screen::renderSpriteOrig(window, textures.GUN, bounds.left + 48 - (24 * (mirrorX ? 1 : 0)), bounds.top + 48, 2, 2, 12, 32, mirrorX, false, angle);
}