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

#include "game_textures.hpp"

Textures::Textures() { // add another way to initialize, from a text file or smth

	for (int y = 0; y < 16; ++y) {
		for (int x = 0; x < 16; ++x) {
			loadTexture(TILES[x + y * 16], "res/textures/tileset.png", sf::IntRect(16 * x, 16 * y, TILE_SIZE, TILE_SIZE));
		}
	}
	loadTexture(AK, "res/textures/ak.png");
	loadTexture(SHOTGUN, "res/textures/shotgun.png");

	loadTexture(CURSOR, "res/textures/cursor.png");
	loadTexture(SHADOW, "res/textures/shadow_1.png");
	loadTexture(BLOOD, "res/textures/tileset.png", sf::IntRect(16 * 0, 16 * 12, TILE_SIZE, TILE_SIZE));
	loadTexture(BIG_BULLET, "res/textures/tileset.png", sf::IntRect(16* 0, 16 * 15, TILE_SIZE, TILE_SIZE));
	loadTexture(SMALL_BULLET, "res/textures/tileset.png", sf::IntRect(16 * 1, 16 * 15, TILE_SIZE, TILE_SIZE));
	loadTexture(BULLET_SHELL, "res/textures/tileset.png", sf::IntRect(16 * 2, 16 * 15, TILE_SIZE, TILE_SIZE));

	loadTexture(FAIRY[0], "res/textures/fairy.png", sf::IntRect(16 * 0, 16* 0, 16, 16));
	loadTexture(FAIRY[1], "res/textures/fairy.png", sf::IntRect(16 * 1, 16* 0, 16, 16));
	loadTexture(FAIRY[2], "res/textures/fairy.png", sf::IntRect(16 * 2, 16* 0, 16, 16));
	loadTexture(FAIRY[3], "res/textures/fairy.png", sf::IntRect(16 * 3, 16* 0, 16, 16));

	loadTexture(HEART[0], "res/textures/heart_pumping.png", sf::IntRect(16 * 0, 16 * 0, 16, 16));
	loadTexture(HEART[1], "res/textures/heart_pumping.png", sf::IntRect(16 * 1, 16 * 0, 16, 16));
	loadTexture(HEART[2], "res/textures/heart_pumping.png", sf::IntRect(16 * 2, 16 * 0, 16, 16));
	loadTexture(HEART[3], "res/textures/heart_pumping.png", sf::IntRect(16 * 3, 16 * 0, 16, 16));
	loadTexture(HEART[4], "res/textures/heart_pumping.png", sf::IntRect(16 * 4, 16 * 0, 16, 16));

	loadTexture(A_GUY_WALKING[1], "res/textures/a_guy_walking.png", sf::IntRect(16 * 1, 32 * 0, 16, 32));

	loadTexture(A_GUY_WALKING[0], "res/textures/a_guy_walking.png", sf::IntRect(16 * 0, 32 * 0, 16, 32));
	loadTexture(A_GUY_WALKING[1], "res/textures/a_guy_walking.png", sf::IntRect(16 * 1, 32 * 0, 16, 32));

	loadTexture(BANNANA_WALKING[0], "res/textures/bannana_walking.png", sf::IntRect(24 * 0, 32 * 0, 24, 32));
	loadTexture(BANNANA_WALKING[1], "res/textures/bannana_walking.png", sf::IntRect(24 * 1, 32 * 0, 24, 32));
	loadTexture(BANNANA_WALKING[2], "res/textures/bannana_walking.png", sf::IntRect(24 * 2, 32 * 0, 24, 32));


	// automate this shit VV

	loadTexture(SLIME_WALK[0], "res/textures/slime_walk.png", sf::IntRect(16 * 0, 16 * 0, TILE_SIZE, TILE_SIZE));
	loadTexture(SLIME_WALK[1], "res/textures/slime_walk.png", sf::IntRect(16 * 1, 16 * 0, TILE_SIZE, TILE_SIZE));
	loadTexture(SLIME_WALK[2], "res/textures/slime_walk.png", sf::IntRect(16 * 2, 16 * 0, TILE_SIZE, TILE_SIZE));
	loadTexture(SLIME_WALK[3], "res/textures/slime_walk.png", sf::IntRect(16 * 3, 16 * 0, TILE_SIZE, TILE_SIZE));

	loadTexture(SMALL_SPARK[0], "res/textures/tileset.png", sf::IntRect(16 * 0, 16 * 13, TILE_SIZE, TILE_SIZE));
	loadTexture(SMALL_SPARK[1], "res/textures/tileset.png", sf::IntRect(16 * 1, 16 * 13, TILE_SIZE, TILE_SIZE));
	loadTexture(SMALL_SPARK[2], "res/textures/tileset.png", sf::IntRect(16 * 2, 16 * 13, TILE_SIZE, TILE_SIZE));
	loadTexture(SMALL_SPARK[3], "res/textures/tileset.png", sf::IntRect(16 * 3, 16 * 13, TILE_SIZE, TILE_SIZE));
	loadTexture(SMALL_SPARK[4], "res/textures/tileset.png", sf::IntRect(16 * 4, 16 * 13, TILE_SIZE, TILE_SIZE));
	loadTexture(SMALL_SPARK[5], "res/textures/tileset.png", sf::IntRect(16 * 5, 16 * 13, TILE_SIZE, TILE_SIZE));

	loadTexture(MOB_IDLE[0], "res/textures/dino.png", sf::IntRect(24 * 0, 24 * 3, 24, 24));
	loadTexture(MOB_IDLE[1], "res/textures/dino.png", sf::IntRect(24 * 1, 24 * 3, 24, 24));
	loadTexture(MOB_IDLE[2], "res/textures/dino.png", sf::IntRect(24 * 2, 24 * 3, 24, 24));
	loadTexture(MOB_IDLE[3], "res/textures/dino.png", sf::IntRect(24 * 1, 24 * 3, 24, 24));

	loadTexture(MOB_WALK[0], "res/textures/dino.png", sf::IntRect(24 * 0, 24 * 3, 24, 24));
	loadTexture(MOB_WALK[1], "res/textures/dino.png", sf::IntRect(24 * 4, 24 * 3, 24, 24));
	loadTexture(MOB_WALK[2], "res/textures/dino.png", sf::IntRect(24 * 5, 24 * 3, 24, 24));
	loadTexture(MOB_WALK[3], "res/textures/dino.png", sf::IntRect(24 * 6, 24 * 3, 24, 24));
	loadTexture(MOB_WALK[4], "res/textures/dino.png", sf::IntRect(24 * 7, 24 * 3, 24, 24));
	loadTexture(MOB_WALK[5], "res/textures/dino.png", sf::IntRect(24 * 8, 24 * 3, 24, 24));
	loadTexture(MOB_WALK[6], "res/textures/dino.png", sf::IntRect(24 * 9, 24 * 3, 24, 24));

	loadTexture(PLAYER_IDLE[0], "res/textures/player_idle.png", sf::IntRect(24 * 0, 24 * 0, 24, 24));
	loadTexture(PLAYER_IDLE[1], "res/textures/player_idle.png", sf::IntRect(24 * 1, 24 * 0, 24, 24));
	loadTexture(PLAYER_IDLE[2], "res/textures/player_idle.png", sf::IntRect(24 * 2, 24 * 0, 24, 24));
	loadTexture(PLAYER_IDLE[3], "res/textures/player_idle.png", sf::IntRect(24 * 1, 24 * 0, 24, 24));

	loadTexture(PLAYER_WALK[0], "res/textures/player_walking.png", sf::IntRect(24 * 0, 24 * 0, 24, 24));
	loadTexture(PLAYER_WALK[1], "res/textures/player_walking.png", sf::IntRect(24 * 1, 24 * 0, 24, 24));
	loadTexture(PLAYER_WALK[2], "res/textures/player_walking.png", sf::IntRect(24 * 2, 24 * 0, 24, 24));
	loadTexture(PLAYER_WALK[3], "res/textures/player_walking.png", sf::IntRect(24 * 3, 24 * 0, 24, 24));
	loadTexture(PLAYER_WALK[4], "res/textures/player_walking.png", sf::IntRect(24 * 4, 24 * 0, 24, 24));
	loadTexture(PLAYER_WALK[5], "res/textures/player_walking.png", sf::IntRect(24 * 5, 24 * 0, 24, 24));
	
}

Textures::~Textures() {

}

void Textures::loadTexture(sf::Texture& texture, const char* path) {
	if (!texture.loadFromFile(path)) {
		Util::log("Could not load the texture!", "[ERROR]");
	}
}

void Textures::loadTexture(sf::Texture& texture, const char* path, const sf::IntRect& rect) {
	if (!texture.loadFromFile(path, rect)) {
		Util::log("Could not load the texture!", "[ERROR]");
	}
}