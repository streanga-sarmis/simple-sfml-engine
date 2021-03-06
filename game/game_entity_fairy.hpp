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

#pragma once

#include "game_item_gun.hpp"
#include "game_animation.hpp"
#include "game_wearing_entity.hpp"

class Fairy : public WearingEntity {
private:
	Animation FLY;
	Mob* owner;
	int bounceTime = 0;

public:
	Fairy(Mob* owner);
	~Fairy();

	void holdOn(Gun* gun);

	void touchedItem(Item* item) override;
	void touchedEntity(Entity* other) override;
	void update(sf::RenderWindow* window, Map& map) override;
	void render(sf::RenderWindow* window, Textures& textures) override;
	void died() override;

};