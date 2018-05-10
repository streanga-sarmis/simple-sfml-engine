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

#include "game_entity_aguy.hpp"
#include "game_item_shotgun.hpp"//remove

AGuy::AGuy(float x, float y) {
	health = 15;

	IDLE.initializeAnimation(1, 1); // one frame animation make a workaround
	WALK.initializeAnimation(2, 10);

	position.x = x;
	position.y = y;

	velocity.x = 0;
	velocity.y = 0;

	tileCollider.left = position.x + 10;
	tileCollider.top = position.y + 48;
	tileCollider.width = 72 - 10;
	tileCollider.height = 96 - 35;

	entityCollider.left = position.x;
	entityCollider.top = position.y;
	entityCollider.width = 72;
	entityCollider.height = 96;

	mirrorX = false;
	walking = false;
	pickupInterval = 0;


	gun = new Shotgun(this);
	ItemManager::addItem(gun);
}

AGuy::~AGuy() {
}

void AGuy::touchedItem(Item* item) {
	if (Util::isType<Item, Gun>(item) && pickupInterval == 0) {
		pickupInterval = 60;
		gun->setOwner(nullptr);
		gun = dynamic_cast<Gun*>(item);
		gun->setOwner(this);
	}
}

void AGuy::touchedEntity(Entity* other) {
}

void AGuy::update(sf::RenderWindow* window, Map& map) {
	iterateHurt();
	--pickupInterval;
	if (pickupInterval < 0) {
		pickupInterval = 0;
	}

	gunAngle = -((std::atan2(position.x + 48 - (sf::Mouse::getPosition(*window).x + Screen::xOff),
		position.y + 48 - 16 - (sf::Mouse::getPosition(*window).y + Screen::yOff)) * 180 / 3.14159265359));

	if (!walking) {
		IDLE.step();
	}
	else {
		WALK.step();
	}

	if (std::rand() % 10 == 2) {
		velocity.x = 1 * (std::rand() % 2 ? -1 : 1);
		velocity.y = 1 * (std::rand() % 2 ? -1 : 1);
	}

	if (velocity.x != 0 || velocity.y != 0) {
		tileCollider.left = position.x + 10;
		tileCollider.top = position.y + 48;
		entityCollider.left = position.x;
		entityCollider.top = position.y;
		move(velocity.x, velocity.y, map);
		walking = true;
	}
	else {
		walking = false;
	}


	if (velocity.x < 0) {
		mirrorX = true;
	}

	if (velocity.x > 0) {
		mirrorX = false;
	}

	if (gunAngle < 0) {
		mirrorX = true;
	}

	if (gunAngle > 0) {
		mirrorX = false;
	}

	gun->update(position, gunAngle, mirrorX);
	EntityManager::checkCollisions(this, map);
	ItemManager::checkCollisions(this, map);
}

void AGuy::render(sf::RenderWindow* window, Textures& textures) {
	if (!walking) {
		IDLE.render(window, textures.A_GUY_WALKING, position.x + (mirrorX ? entityCollider.width : 0), position.y, position.z, 3, 3, mirrorX, false, ((hurtIterator != hurtDelay) ?
			sf::Color::Blue : sf::Color::White));
	}
	else {
		WALK.render(window, textures.A_GUY_WALKING, position.x + (mirrorX ? entityCollider.width : 0), position.y, position.z, 3, 3, mirrorX, false, ((hurtIterator != hurtDelay) ?
			sf::Color::Blue : sf::Color::White));
	}
}

void AGuy::died() {
	ItemManager::removeItem(gun);
	EntityManager::removeEntity(this);
}