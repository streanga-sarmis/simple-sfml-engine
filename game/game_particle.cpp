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

#include "game_particle.hpp"

Particle::Particle(float x, float y, int lifetime):
Particle(x, y, 0, lifetime){
}

Particle::Particle(float x, float y, float angle, int lifetime):
lifetime(lifetime), angle(angle){
	position.x = x;
	position.y = y;

	tileCollider.left = position.x;
	tileCollider.top = position.y;
	tileCollider.width = 32;
	tileCollider.height = 32;
	if (angle) {
		velocity.x = std::cos(angle * 3.14159265359 / 180);
		velocity.y = std::sin(angle * 3.14159265359 / 180);
	}
	canCollide = false;
}

Particle::~Particle() {

}
