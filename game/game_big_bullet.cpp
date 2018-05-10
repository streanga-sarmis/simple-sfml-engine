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
#include "game_small_spark.hpp"//remove

BigBullet::BigBullet(Gun* owner, int x, int y, float angle):
Projectile(owner, x, y, angle){
	speed = 36;
	velocity.x = -std::cos((angle + 90) * 3.14159265359 / 180) * speed;
	velocity.y = -std::sin((angle + 90) * 3.14159265359 / 180) * speed;

	tileCollider.width = 32;
	tileCollider.height = 32;
	tileCollider.left = x;
	tileCollider.top = y;

	entityCollider.left = position.x;
	entityCollider.top = position.y;
	entityCollider.width = 32;
	entityCollider.height = 32;
}

BigBullet::~BigBullet() {

}

void BigBullet::touchedEntity(Entity* other) {
	if (other != owner->owner && !Util::isType<Entity, Particle>(other)
		&& !Util::isType<Entity, Projectile>(other) && Util::isType<Entity, Mob>(other)) {
		dynamic_cast<Mob*>(other)->hurt(10, angle);
		EntityManager::removeEntity(this);
	}
}

void BigBullet::update(sf::RenderWindow* window, Map& map) {
	// put the update method in the projectile not here
	if (!canStep(velocity.x, velocity.y, map)) {
		EntityManager::removeEntity(this);
	}

	position.x += velocity.x;
	position.y += velocity.y;
	entityCollider.left = position.x;
	entityCollider.top = position.y;
	tileCollider.left = position.x;
	tileCollider.top = position.y;


	EntityManager::checkCollisions(this, map);
}

void BigBullet::render(sf::RenderWindow* window, Textures& textures) {
	Screen::renderSpriteOrig(window, textures.BIG_BULLET, position.x, position.y, 3, 3, 16, 16, false, false, angle);
}