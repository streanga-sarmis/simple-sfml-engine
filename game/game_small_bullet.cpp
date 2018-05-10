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

#include "game_small_bullet.hpp"

SmallBullet::SmallBullet(Gun* owner, int x, int y, float angle):
Projectile(owner, x, y, angle){
	speed = 24;
	velocity.x = -std::cos((angle + 90) * 3.14159265359 / 180) * speed;
	velocity.y = -std::sin((angle + 90) * 3.14159265359 / 180) * speed;

	position.x = x;
	position.y = y;

	tileCollider.width = 16 * 1;
	tileCollider.height = 16 * 1;
	tileCollider.left = x - 8;
	tileCollider.top = y - 8;

	entityCollider.width = 16 * 3;
	entityCollider.height = 16 * 3;
	entityCollider.left = x - 24;
	entityCollider.top = y - 24;
}

SmallBullet::~SmallBullet() {

}

void SmallBullet::touchedEntity(Entity* other) {
	if (other != owner->owner && !Util::isType<Entity, Particle>(other)
		&& !Util::isType<Entity, Projectile>(other) && Util::isType<Entity, Mob>(other)) {
		dynamic_cast<Mob*>(other)->hurt(2, angle);
		EntityManager::removeEntity(this);
	}
}

void SmallBullet::update(sf::RenderWindow* window, Map& map) {
	// put the update method in the projectile not here
	if (!canStep(velocity.x, velocity.y, map)) {
		EntityManager::removeEntity(this);
	}

	position.x += velocity.x;
	position.y += velocity.y;

	tileCollider.left = position.x - 8;
	tileCollider.top = position.y - 8;
	entityCollider.left = position.x - 24;
	entityCollider.top = position.y - 24;

	EntityManager::checkCollisions(this, map);
}

void SmallBullet::render(sf::RenderWindow* window, Textures& textures) {
	Screen::renderSpriteOrig(window, textures.SMALL_BULLET, position.x, position.y, position.z, 4, 4, 16, 16, false, false, angle);
}