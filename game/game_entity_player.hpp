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
#include "game_screen.hpp"
#include "game_camera.hpp"
#include "game_animation.hpp"
#include "game_entity_fairy.hpp"
#include "game_item_manager.hpp"
#include "game_entity_manager.hpp"
#include "game_wearing_entity.hpp"

class Player : public WearingEntity {
private:
	Fairy* fairy;
	Animation IDLE;
	Animation WALK;
	bool mirrorX;
	bool walking;
	float gunAngle;
	int pickupInterval;

public:
	
	Player();
	~Player();

	void touchedItem(Item* item) override;
	void touchedEntity(Entity* other) override;
	void update(sf::RenderWindow* window, Map& map) override;
	void render(sf::RenderWindow* window, Textures& textures) override;
	void died() override;
};