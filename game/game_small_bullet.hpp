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

#pragma once

#include "game_mob.hpp"
#include "game_particle.hpp"
#include "game_projectile.hpp"
#include "game_entity_manager.hpp" // remove
#include "game_impact_particle.hpp"

class SmallBullet : public Projectile {
public:
	SmallBullet(Gun* owner, int x, int y, float angle);
	~SmallBullet();

	void touchedEntity(Entity* other) override;
	void update(sf::RenderWindow* window, Map& map) override; // remove
	void render(sf::RenderWindow* window, Textures& textures) override;
};