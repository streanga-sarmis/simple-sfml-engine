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

#include "game_item.hpp"
#include "game_stats.hpp"
#include "game_item_manager.hpp"

class ConsumableItem : public Item {
protected:
	bool followPlayer = false;
	Animation frames;

public:
	Stats::Synergies synergies;

	inline void picked() {
		ItemManager::removeItem(this);
		// generate some kind of nice particle
	}

	inline void use() override {
	}

	inline void update(const sf::Vector3f& position, float angle, bool mirrorX) override {
	}

	inline void renderIcon(sf::RenderWindow* window, Textures& textures, int x, int y, int z) override {
	}
};