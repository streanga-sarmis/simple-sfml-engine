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

#include "game_big_bullet.hpp"

BigBullet::BigBullet(Entity* owner, int x, int y, float angle):
Projectile(owner, x, y, angle){
	speed = 36;
	velocity.x = -std::cos((angle + 90) * 3.14159265359 / 180) * speed;
	velocity.y += -std::sin((angle + 90) * 3.14159265359 / 180) * speed;
}

BigBullet::~BigBullet() {

}

void BigBullet::touchedEntity(Entity* other) {
}

void BigBullet::update(sf::RenderWindow* window, Map& map) {
	// put the update method in the projectile not here
	if (!canStep(velocity.x, velocity.y, map)) {
		std::cout << "hit ?\n";
		EntityManager::removeEntity(index);
	}

	bounds.left += velocity.x;
	bounds.top += velocity.y;
}

void BigBullet::render(sf::RenderWindow* window, Textures& textures) {
	Screen::renderSpriteOrig(window, textures.BIG_BULLET, bounds.left, bounds.top, 3, 3, 16, 16, false, false, angle);
}