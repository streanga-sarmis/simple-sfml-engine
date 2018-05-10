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

#include "game_entity.hpp"
#include "game_entity_manager.hpp"

class Mob : public Entity {
protected:
	int health;
	int hurtDelay = 20;
	int hurtIterator = hurtDelay;

public:

	inline void iterateHurt() {
		if (health <= 0) {
			died();
		}
		if (hurtIterator < hurtDelay) {
			++hurtIterator;
		}
	}

	inline void hurt(int damage, float angle) {
		if (hurtIterator == hurtDelay) {
			hurtIterator = 0;
			this->knock(angle);
			health -= damage;
		}
	}

	virtual void died() = 0;

};