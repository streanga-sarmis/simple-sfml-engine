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
#include <iostream>//remove
#include "game_item_ak.hpp"//remove
#include "game_item_shotgun.hpp"//remove

Player::Player() {
	health = 4;

	IDLE.initializeAnimation(4, 10);
	WALK.initializeAnimation(6, 5);

	position.x = 64 * 32;
	position.y = 64 * 32;
	
	velocity.x = 0;
	velocity.y = 0;

	tileCollider.left = position.x + 12;
	tileCollider.top  = position.y + 28;
	tileCollider.width = 72 - 24;
	tileCollider.height = 72 - 22;

	entityCollider.left = position.x;
	entityCollider.top = position.y;
	entityCollider.width = 72;
	entityCollider.height = 72;

	mirrorX = false;
	walking = false;
	pickupInterval = 0;


	gun = new AK(this);
	ItemManager::addItem(gun);
	//ItemManager::addItem(new Shotgun(300, 300));

	fairy = new Fairy(this);
	EntityManager::addEntity(fairy);

	Shotgun* shotgun = new Shotgun(fairy);
	ItemManager::addItem(shotgun);
	fairy->holdOn(shotgun);
}

Player::~Player() {
}

void Player::touchedItem(Item* item) {
	if (Util::isType<Item, Gun>(item) && pickupInterval == 0) {
		pickupInterval = 60;
		gun->setOwner(nullptr);
		gun = dynamic_cast<Gun*>(item);
		gun->setOwner(this);
	}
}

void Player::touchedEntity(Entity* other) {
}

void Player::update(sf::RenderWindow* window, Map& map) {
	iterateHurt();
	Stats::playerHealth = health;
	--pickupInterval;
	if (pickupInterval < 0) {
		pickupInterval = 0;
	}

	gunAngle = -((std::atan2(position.x + 48 - (12) - (sf::Mouse::getPosition(*window).x + Screen::xOff),
		position.y + 40 - 16 - (sf::Mouse::getPosition(*window).y + Screen::yOff)) * 180 / 3.14159265359));

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
		gun->use();
	}

	if (velocity.x != 0 || velocity.y != 0) {
		tileCollider.left = position.x + 12;
		tileCollider.top = position.y + 28;
		entityCollider.left = position.x;
		entityCollider.top = position.y;
		move(velocity.x, velocity.y, map);
		walking = true;
	} else {
		walking = false;
	}

	if (gunAngle < 0) {
		mirrorX = true;
	} else if (gunAngle > 0) {
		mirrorX = false;
	}

	gun->update(position, gunAngle, mirrorX);
	//position.z = -position.y;
	EntityManager::checkCollisions(this, map);
	ItemManager::checkCollisions(this, map);
}

void Player::render(sf::RenderWindow* window, Textures& textures) {
	Screen::renderSprite(window, textures.SHADOW, position.x, position.y + 10, position.z, 3, 3);
	if (!walking) {
		IDLE.render(window, textures.PLAYER_IDLE, position.x + (mirrorX ? entityCollider.width : 0), position.y, position.z, 3, 3, mirrorX);
	} else {
		WALK.render(window, textures.PLAYER_WALK, position.x + (mirrorX ? entityCollider.width : 0), position.y, position.z, 3, 3, mirrorX);
	}
}

void Player::died() {

}