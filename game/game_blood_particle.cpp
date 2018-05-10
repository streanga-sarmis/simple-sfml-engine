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

#include "game_blood_particle.hpp"

BloodParticle::BloodParticle(float x, float y):
	BloodParticle(x, y, 0, 100) {

}

BloodParticle::BloodParticle(float x, float y, int lifetime) :
	BloodParticle(x, y, 0, lifetime) {
}

BloodParticle::BloodParticle(float x, float y, float angle, int lifetime) :
	Particle(x, y, angle, lifetime) {
	velocity.x = (std::rand() % 5) * (std::rand() % 2 ? -1 : 1);
	velocity.y = (std::rand() % 5) + 13;
}

BloodParticle::~BloodParticle() {

}

void BloodParticle::touchedEntity(Entity* e) {

}
void BloodParticle::update(sf::RenderWindow* window, Map& map) {
	--lifetime;
	if (lifetime <= 0) {
		EntityManager::removeEntity(this);
	}

	if (velocity.x < 0) {
		velocity.x += 0.2;
	}

	if (velocity.x > 0) {
		velocity.x -= 0.2;
	}

	if (lifetime >= 70) { // I hate this, the particle must be changed
		if (velocity.y > 12) {
			velocity.y *= -0.5;
		} else {
			velocity.y += 0.9;
		}
	} else {
		velocity.y = 0;
		velocity.x = 0;
	}

	position.x += velocity.x;
	position.y += velocity.y;
}

void BloodParticle::render(sf::RenderWindow* window, Textures& textures) {
	Screen::renderSprite(window, textures.BLOOD, position.x, position.y, position.z, 1, 1);
}