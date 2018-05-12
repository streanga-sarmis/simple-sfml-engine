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

#include "game_item_ak.hpp"
#include <iostream>//remove

AK::AK(WearingEntity* owner) {
	this->owner = owner;
	onHand = true;
	bounds.width = 48;
	bounds.height = 48;
	shotInterval = 15; // move these in the Gun constructor
	shotIterator = shotInterval;
	SHOOT.initializeAnimation(3, shotInterval / 3);
}

AK::AK(float x, float y) {
	owner = nullptr;
	onHand = false;
	bounds.left = x;
	bounds.top = y;
	bounds.width = 48;
	bounds.height = 48;
	shotInterval = 15;
	shotIterator = shotInterval;
	SHOOT.initializeAnimation(3, shotInterval / 3);
}

AK::~AK() {

}

void AK::use(){
	if (shotIterator == shotInterval) {
		shotIterator = 0;
		Camera::shake();
		EntityManager::addEntity(new SmallBullet(this, bounds.left + 48 - (12 * (mirrorX ? 1 : 0)), bounds.top + 40, angle - (std::rand() % 4) *
			(std::rand() % 2 ? -1 : 1)));
		EntityManager::addEntity(new BulletShell(bounds.left + 48 - (12 * (mirrorX ? 1 : 0)), bounds.top + 40, angle, 360));
	}
}

void AK::update(const sf::Vector3f& position, float angle, bool mirrorX) {
	if (shotIterator < shotInterval) {
		++shotIterator;
		SHOOT.step();
	}
	this->angle = angle;
	this->mirrorX = mirrorX;
	this->bounds.left = position.x;
	this->bounds.top = position.y;
	z = position.z + 12;
}

void AK::render(sf::RenderWindow* window, Textures& textures) {
	if (onHand) {
		if (shotIterator != shotInterval) {
			SHOOT.renderOrig(window, textures.AK, bounds.left + 48 - (24 * (mirrorX ? 1 : 0)), bounds.top + 56, z, 2, 2, 24, 48, mirrorX, false, angle);
		} else {
			Screen::renderSpriteOrig(window, textures.AK[0], bounds.left + 48 - (24 * (mirrorX ? 1 : 0)), bounds.top + 56, z, 2, 2, 24, 48, mirrorX, false, angle);
		}
	} else {
		Screen::renderSprite(window, textures.AK[0], bounds.left + bounds.width / 2, bounds.top + bounds.height / 2, z, 2, 2, false, false, angle);
	}
}

void AK::renderIcon(sf::RenderWindow* window, Textures& textures, int x, int y, int z) {
	if (shotIterator != shotInterval) {
		SHOOT.renderOrig(window, textures.AK, x + 48, y + 40, z, 4, 4, 24, 48, false, true, 90);
	} else {
		Screen::renderSpriteOrig(window, textures.AK[0], x + 48, y + 40, z, 4, 4, 24, 48, false, true, 90);
	}
}