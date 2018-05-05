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
#include "game_textures.hpp"

class Entity {
protected:
	unsigned index; // unique accross entities
	sf::IntRect bounds;
	sf::Vector2i velocity;

public:
	virtual void touchedEntity(Entity* other) = 0;
	virtual void update(sf::RenderWindow* window, Map& map) = 0;
	virtual void render(sf::RenderWindow* window, Textures& textures) = 0;

	friend class EntityManager;
	friend class Level;
};