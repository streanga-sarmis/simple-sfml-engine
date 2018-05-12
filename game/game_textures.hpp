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

#define TILE_SIZE 16

#include <SFML/Graphics.hpp>

#include "game_utils.hpp"

class Textures {
public:
	sf::Texture SHOTGUN;

	sf::Texture CURSOR;
	sf::Texture SHADOW;
	sf::Texture BULLET_HUD;
	sf::Texture GUN_FRAME;
	sf::Texture BIG_BULLET;
	sf::Texture SMALL_BULLET;
	sf::Texture BULLET_SHELL;

	sf::Texture GEMS[7 * 2];

	sf::Texture BOOM_PARTICLE[9];
	sf::Texture IMPACT_PARTICLE[5];

	sf::Texture BLUE_GEM_ENEMY_IDLE[7];
	sf::Texture BLUE_GEM_ENEMY_WALK[5];

	sf::Texture AK[3];

	sf::Texture FAIRY[4];

	sf::Texture BLOOD;
	sf::Texture SMALL_SPARK[6];

	sf::Texture MOB_IDLE[4];
	sf::Texture MOB_WALK[7];

	sf::Texture PLAYER_IDLE[4];
	sf::Texture PLAYER_WALK[8];

	sf::Texture HEART[5];

	sf::Texture TILES[16 * 16];

	Textures();
	~Textures();

	void loadTexture(sf::Texture& texture, const char* path);
	void loadTexture(sf::Texture& texture, const char* path, const sf::IntRect& rect);
};