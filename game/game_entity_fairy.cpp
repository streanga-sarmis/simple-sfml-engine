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

#include "game_entity_fairy.hpp"

Fairy::Fairy(Mob* owner):
owner(owner){
	FLY.initializeAnimation(4, 5);
	position.x = owner->position.x + 72;
	position.y = owner->position.y - 72;

	entityCollider.left = position.x;
	entityCollider.top = position.y;
	entityCollider.width = 32;
	entityCollider.height = 32;

	tileCollider.left = position.x;
	tileCollider.top = position.y;
	tileCollider.width = 32;
	tileCollider.height = 32;

	position.z = 99999;
	canCollide = false;
}

Fairy::~Fairy() {

}

void Fairy::holdOn(Gun* gun) {
	this->gun = gun;
	gun->setOwner(this);
}

void Fairy::touchedItem(Item* item) {

}

void Fairy::touchedEntity(Entity* other) {

}

void Fairy::update(sf::RenderWindow* window, Map& map) {
	bounceTime++;
	bounceTime %= 360;
	FLY.step();

	if (std::rand() % 10 == 0) {
		
	}
	position.x = owner->position.x + 72;
	position.y = owner->position.y - 128;

	velocity.y = std::cos(bounceTime * 0.2) * 5;

	position.y += velocity.y;
	entityCollider.left = position.x;
	entityCollider.top = position.y;
	tileCollider.left = position.x;
	tileCollider.top = position.y;
	if (gun != nullptr) {
		gun->update(sf::Vector3f(position.x - 32, position.y - 16, position.z), 75, false);
	}
	//position.z = position.y + entityCollider.height / 2;
}

void Fairy::render(sf::RenderWindow* window, Textures& textures) {
	FLY.render(window, textures.FAIRY, position.x, position.y, position.z, 2, 2);
}

void Fairy::died() {

}