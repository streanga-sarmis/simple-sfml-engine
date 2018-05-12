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

#include "game_item_shotgun.hpp"

Shotgun::Shotgun(WearingEntity* owner) {
	this->owner = owner;
	onHand = true;
	bounds.width = 48;
	bounds.height = 48;
	shotInterval = 60;
	shotIterator = shotInterval;
}

Shotgun::Shotgun(float x, float y) {
	owner = nullptr;
	bounds.left = x;
	bounds.top = y;
	bounds.width = 48;
	bounds.height = 48;
	onHand = false;
	shotInterval = 60;
	shotIterator = shotInterval;
}

Shotgun::~Shotgun() {

}

void Shotgun::use() {
	if (shotIterator == shotInterval) {
		shotIterator = 0;
		Camera::shake();
		for (int i = 0; i < 2; ++i) {
			EntityManager::addEntity(new BigBullet(this, bounds.left + 48 - (12 * (mirrorX ? 1 : 0)), bounds.top + 48, angle - (std::rand() % 4) *
				(std::rand() % 2 ? -1 : 1)));
		}
	}
}

void Shotgun::update(const sf::Vector3f& position, float angle, bool mirrorX) {
	if (shotIterator < shotInterval) {
		++shotIterator;
	}
	this->angle = angle;
	this->mirrorX = mirrorX;
	this->bounds.left = position.x;
	this->bounds.top = position.y;
	z = position.z;
}

void Shotgun::render(sf::RenderWindow* window, Textures& textures) {
	if (onHand) {
		Screen::renderSpriteOrig(window, textures.SHOTGUN, bounds.left + 48 - (24 * (mirrorX ? 1 : 0)), bounds.top + 48, z, 2, 2, 12, 32, mirrorX, false, angle);
	}
	else {
		Screen::renderSprite(window, textures.SHOTGUN, bounds.left + bounds.width / 2, bounds.top + bounds.height / 2, z, 2, 2, false, false, angle);
	}
}

void Shotgun::renderIcon(sf::RenderWindow* window, Textures& textures, int x, int y, int z) {

}