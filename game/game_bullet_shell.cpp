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

#include "game_bullet_shell.hpp"

BulletShell::BulletShell(float x, float y) :
	BulletShell(x, y, 0, 100) {

}

BulletShell::BulletShell(float x, float y, int lifetime) :
	BulletShell(x, y, 0, lifetime) {
}

BulletShell::BulletShell(float x, float y, float angle, int lifetime) :
	Particle(x, y, angle, lifetime) {
	velocity.x = std::round(velocity.y * (std::rand() % 12 + 5));
	velocity.y = std::round(velocity.y * (std::rand() % 12 + 5));

	velocity.y *= -1;
	this->angle = angle + std::rand() % 180;
	tileCollider.left = position.x - 16;
	tileCollider.top = position.y - 16;
	tileCollider.width = 32;
	tileCollider.height = 32;
}

BulletShell::~BulletShell() {

}

void BulletShell::touchedEntity(Entity* e) {

}
void BulletShell::update(sf::RenderWindow* window, Map& map) {
	--lifetime;
	if (lifetime <= 0) {
		EntityManager::removeEntity(this);
	}

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
	tileCollider.left = position.x - 16;
	tileCollider.top = position.y - 16;
	move(velocity.x, velocity.y, map);
}

void BulletShell::render(sf::RenderWindow* window, Textures& textures) {
	Screen::renderSpriteOrig(window, textures.BULLET_SHELL, position.x, position.y, position.z, 2, 2, 16, 16, false, false, angle);
}