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

#include "game_animation_particle.hpp"

AnimationParticle::AnimationParticle(float x, float y, int lifetime) :
	AnimationParticle(x, y, 0, lifetime) {
}

AnimationParticle::AnimationParticle(float x, float y, float angle, int lifetime) :
	angle(angle), lifetime(lifetime) {
	position.x = x;
	position.y = y;

	tileCollider.left = position.x;
	tileCollider.top = position.y;
	tileCollider.width = 32;
	tileCollider.height = 32;

	position.z = 0;
	/*
	if (angle) {
		velocity.x = std::cos(angle * 3.14159265359 / 180) * speed;
		velocity.y = std::sin(angle * 3.14159265359 / 180) * speed;
	}
	*/
	canCollide = false;
}

AnimationParticle::~AnimationParticle() {

}

void AnimationParticle::touchedEntity(Entity* other) {

}

void AnimationParticle::update(sf::RenderWindow* window, Map& map) {
	--lifetime;
	if (lifetime <= 0) {
		EntityManager::removeEntity(this);
	}
	/*
	position.x += velocity.x;
	position.x += velocity.y;
	*/
	tileCollider.left = position.x;
	tileCollider.top = position.y;

	frames.step();
}
