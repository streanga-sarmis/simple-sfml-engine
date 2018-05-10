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

#include "game_camera.hpp"
#include "game_item_gun.hpp"
#include "game_big_bullet.hpp"
#include "game_wearing_entity.hpp"
#include "game_entity_manager.hpp"

class Shotgun : public Gun {
public:
	Shotgun(WearingEntity* owner);
	Shotgun(float x, float y);
	~Shotgun();

	void use() override;
	void update(const sf::Vector3f& position, float angle, bool mirrorX) override;
	void render(sf::RenderWindow* window, Textures& textures) override;

	friend class Projectile;
};