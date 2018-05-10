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

#include <SFML/Graphics.hpp>

#include "game_map.hpp"
#include "game_entity.hpp"
#include "game_animation.hpp"
#include "game_entity_manager.hpp"

class AnimationParticle : public Entity {

protected:
	float speed = 4;
	Animation frames;
	int lifetime = 0;

public:
	AnimationParticle(float x, float y, int lifetime);
	AnimationParticle(float x, float y, float angle, int lifetime);
	~AnimationParticle();

	void update(sf::RenderWindow* window, Map& map) override;

};