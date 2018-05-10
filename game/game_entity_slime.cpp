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

#include "game_entity_slime.hpp"

Slime::Slime(float x, float y) {
	health = 10;
	IDLE.initializeAnimation(2, 20);
	WALK.initializeAnimation(4, 10);

	position.x = x;
	position.y = y;

	tileCollider.left = x + 10;
	tileCollider.top = y + 48;
	tileCollider.width = 64 - 10;
	tileCollider.height = 64 - 48;

	entityCollider.width = 72;
	entityCollider.height = 72;
	entityCollider.left = x;
	entityCollider.top = y;

	velocity.x = 0;
	velocity.y = 0;
	mirrorX = false;
	walking = false;

}

Slime::~Slime() {

}

void Slime::touchedEntity(Entity* other) {

}

void Slime::update(sf::RenderWindow* window, Map& map) {
	iterateHurt();
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
		entityCollider.left = position.x;
		entityCollider.top = position.y;
		tileCollider.left = position.x + 10;
		tileCollider.top = position.y + 48;
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

}
void Slime::render(sf::RenderWindow* window, Textures& textures) {
	if (!walking) {
		IDLE.render(window, textures.SLIME_WALK, position.x + (mirrorX ? entityCollider.width : 0), position.y, position.z, 4, 4, mirrorX, false, ((hurtIterator != hurtDelay) ?
			sf::Color::Blue : sf::Color::White));
	} else {
		WALK.render(window, textures.SLIME_WALK, position.x + (mirrorX ? entityCollider.width : 0), position.y, position.z, 4, 4, mirrorX, false, (hurtIterator != hurtDelay ?
			sf::Color::Blue : sf::Color::White));
	}
}

void Slime::died() {
	EntityManager::removeEntity(this);
}