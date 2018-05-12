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

	loadTexture(SHOTGUN, "res/textures/shotgun.png");

	loadTexture(BLUE_GEM_ENEMY_IDLE[0], "res/textures/blue_gem_enemy_idle.png", sf::IntRect(64 * 0, 96 * 0, 64, 96));
	loadTexture(BLUE_GEM_ENEMY_IDLE[1], "res/textures/blue_gem_enemy_idle.png", sf::IntRect(64 * 1, 96 * 0, 64, 96));
	loadTexture(BLUE_GEM_ENEMY_IDLE[2], "res/textures/blue_gem_enemy_idle.png", sf::IntRect(64 * 2, 96 * 0, 64, 96));
	loadTexture(BLUE_GEM_ENEMY_IDLE[3], "res/textures/blue_gem_enemy_idle.png", sf::IntRect(64 * 3, 96 * 0, 64, 96));
	loadTexture(BLUE_GEM_ENEMY_IDLE[4], "res/textures/blue_gem_enemy_idle.png", sf::IntRect(64 * 4, 96 * 0, 64, 96));
	loadTexture(BLUE_GEM_ENEMY_IDLE[5], "res/textures/blue_gem_enemy_idle.png", sf::IntRect(64 * 5, 96 * 0, 64, 96));
	loadTexture(BLUE_GEM_ENEMY_IDLE[6], "res/textures/blue_gem_enemy_idle.png", sf::IntRect(64 * 6, 96 * 0, 64, 96));
	
	loadTexture(BLUE_GEM_ENEMY_WALK[0], "res/textures/blue_gem_enemy.png", sf::IntRect(64 * 0, 96 * 0, 64, 96));
	loadTexture(BLUE_GEM_ENEMY_WALK[1], "res/textures/blue_gem_enemy.png", sf::IntRect(64 * 1, 96 * 0, 64, 96));
	loadTexture(BLUE_GEM_ENEMY_WALK[2], "res/textures/blue_gem_enemy.png", sf::IntRect(64 * 2, 96 * 0, 64, 96));
	loadTexture(BLUE_GEM_ENEMY_WALK[3], "res/textures/blue_gem_enemy.png", sf::IntRect(64 * 3, 96 * 0, 64, 96));
	loadTexture(BLUE_GEM_ENEMY_WALK[4], "res/textures/blue_gem_enemy.png", sf::IntRect(64 * 4, 96 * 0, 64, 96));

	loadTexture(GEMS[0], "res/textures/blue_gem.png", sf::IntRect(16 * 0, 16 * 0, 16, 16));
	loadTexture(GEMS[1], "res/textures/blue_gem.png", sf::IntRect(16 * 1, 16 * 0, 16, 16));
	loadTexture(GEMS[2], "res/textures/blue_gem.png", sf::IntRect(16 * 2, 16 * 0, 16, 16));
	loadTexture(GEMS[3], "res/textures/blue_gem.png", sf::IntRect(16 * 3, 16 * 0, 16, 16));
	loadTexture(GEMS[4], "res/textures/blue_gem.png", sf::IntRect(16 * 4, 16 * 0, 16, 16));
	loadTexture(GEMS[5], "res/textures/blue_gem.png", sf::IntRect(16 * 5, 16 * 0, 16, 16));
	loadTexture(GEMS[6], "res/textures/blue_gem.png", sf::IntRect(16 * 6, 16 * 0, 16, 16));

	loadTexture(GEMS[7], "res/textures/green_gem.png", sf::IntRect(16 * 0, 16 * 0, 16, 16));
	loadTexture(GEMS[8], "res/textures/green_gem.png", sf::IntRect(16 * 1, 16 * 0, 16, 16));
	loadTexture(GEMS[9], "res/textures/green_gem.png", sf::IntRect(16 * 2, 16 * 0, 16, 16));
	loadTexture(GEMS[10], "res/textures/green_gem.png", sf::IntRect(16 * 3, 16 * 0, 16, 16));
	loadTexture(GEMS[11], "res/textures/green_gem.png", sf::IntRect(16 * 4, 16 * 0, 16, 16));
	loadTexture(GEMS[12], "res/textures/green_gem.png", sf::IntRect(16 * 5, 16 * 0, 16, 16));
	loadTexture(GEMS[13], "res/textures/green_gem.png", sf::IntRect(16 * 6, 16 * 0, 16, 16));

	loadTexture(BOOM_PARTICLE[0], "res/textures/boom.png", sf::IntRect(32 * 0, 32 * 0, 32, 32));
	loadTexture(BOOM_PARTICLE[1], "res/textures/boom.png", sf::IntRect(32 * 1, 32 * 0, 32, 32));
	loadTexture(BOOM_PARTICLE[2], "res/textures/boom.png", sf::IntRect(32 * 2, 32 * 0, 32, 32));
	loadTexture(BOOM_PARTICLE[3], "res/textures/boom.png", sf::IntRect(32 * 3, 32 * 0, 32, 32));
	loadTexture(BOOM_PARTICLE[4], "res/textures/boom.png", sf::IntRect(32 * 4, 32 * 0, 32, 32));
	loadTexture(BOOM_PARTICLE[5], "res/textures/boom.png", sf::IntRect(32 * 5, 32 * 0, 32, 32));
	loadTexture(BOOM_PARTICLE[6], "res/textures/boom.png", sf::IntRect(32 * 6, 32 * 0, 32, 32));
	loadTexture(BOOM_PARTICLE[7], "res/textures/boom.png", sf::IntRect(32 * 7, 32 * 0, 32, 32));
	loadTexture(BOOM_PARTICLE[8], "res/textures/boom.png", sf::IntRect(32 * 8, 32 * 0, 32, 32));

	loadTexture(IMPACT_PARTICLE[0], "res/textures/impact_particle.png", sf::IntRect(24 * 0, 24 * 0, 24, 24));
	loadTexture(IMPACT_PARTICLE[1], "res/textures/impact_particle.png", sf::IntRect(24 * 1, 24 * 0, 24, 24));
	loadTexture(IMPACT_PARTICLE[2], "res/textures/impact_particle.png", sf::IntRect(24 * 2, 24 * 0, 24, 24));
	loadTexture(IMPACT_PARTICLE[3], "res/textures/impact_particle.png", sf::IntRect(24 * 3, 24 * 0, 24, 24));
	loadTexture(IMPACT_PARTICLE[4], "res/textures/impact_particle.png", sf::IntRect(24 * 4, 24 * 0, 24, 24));

	loadTexture(CURSOR, "res/textures/cursor.png");
	loadTexture(SHADOW, "res/textures/shadow_1.png");
	loadTexture(BLOOD, "res/textures/tileset.png", sf::IntRect(16 * 0, 16 * 12, TILE_SIZE, TILE_SIZE));
	loadTexture(BULLET_HUD, "res/textures/bullet_hud.png");
	loadTexture(GUN_FRAME, "res/textures/gun_frame.png");
	loadTexture(BIG_BULLET, "res/textures/tileset.png", sf::IntRect(16* 0, 16 * 15, TILE_SIZE, TILE_SIZE));
	loadTexture(SMALL_BULLET, "res/textures/tileset.png", sf::IntRect(16 * 1, 16 * 15, TILE_SIZE, TILE_SIZE));
	loadTexture(BULLET_SHELL, "res/textures/tileset.png", sf::IntRect(16 * 2, 16 * 15, TILE_SIZE, TILE_SIZE));

	loadTexture(AK[0], "res/textures/ak.png", sf::IntRect(24 * 0, 48 * 0, 24, 48));
	loadTexture(AK[1], "res/textures/ak.png", sf::IntRect(24 * 1, 48 * 0, 24, 48));
	loadTexture(AK[2], "res/textures/ak.png", sf::IntRect(24 * 2, 48 * 0, 24, 48));

	loadTexture(FAIRY[0], "res/textures/fairy.png", sf::IntRect(16 * 0, 16* 0, 16, 16));
	loadTexture(FAIRY[1], "res/textures/fairy.png", sf::IntRect(16 * 1, 16* 0, 16, 16));
	loadTexture(FAIRY[2], "res/textures/fairy.png", sf::IntRect(16 * 2, 16* 0, 16, 16));
	loadTexture(FAIRY[3], "res/textures/fairy.png", sf::IntRect(16 * 3, 16* 0, 16, 16));

	loadTexture(HEART[0], "res/textures/heart_pumping.png", sf::IntRect(16 * 0, 16 * 0, 16, 16));
	loadTexture(HEART[1], "res/textures/heart_pumping.png", sf::IntRect(16 * 1, 16 * 0, 16, 16));
	loadTexture(HEART[2], "res/textures/heart_pumping.png", sf::IntRect(16 * 2, 16 * 0, 16, 16));
	loadTexture(HEART[3], "res/textures/heart_pumping.png", sf::IntRect(16 * 3, 16 * 0, 16, 16));
	loadTexture(HEART[4], "res/textures/heart_pumping.png", sf::IntRect(16 * 4, 16 * 0, 16, 16));

	loadTexture(PLAYER_IDLE[0], "res/textures/cat_idle.png", sf::IntRect(24 * 0, 24 * 0, 24, 24));
	loadTexture(PLAYER_IDLE[1], "res/textures/cat_idle.png", sf::IntRect(24 * 1, 24 * 0, 24, 24));
	loadTexture(PLAYER_IDLE[2], "res/textures/cat_idle.png", sf::IntRect(24 * 2, 24 * 0, 24, 24));
	loadTexture(PLAYER_IDLE[3], "res/textures/cat_idle.png", sf::IntRect(24 * 1, 24 * 0, 24, 24));

	loadTexture(PLAYER_WALK[0], "res/textures/cat_walk.png", sf::IntRect(24 * 0, 24 * 0, 24, 24));
	loadTexture(PLAYER_WALK[1], "res/textures/cat_walk.png", sf::IntRect(24 * 1, 24 * 0, 24, 24));
	loadTexture(PLAYER_WALK[2], "res/textures/cat_walk.png", sf::IntRect(24 * 2, 24 * 0, 24, 24));
	loadTexture(PLAYER_WALK[3], "res/textures/cat_walk.png", sf::IntRect(24 * 3, 24 * 0, 24, 24));
	loadTexture(PLAYER_WALK[4], "res/textures/cat_walk.png", sf::IntRect(24 * 4, 24 * 0, 24, 24));
	loadTexture(PLAYER_WALK[5], "res/textures/cat_walk.png", sf::IntRect(24 * 5, 24 * 0, 24, 24));
	loadTexture(PLAYER_WALK[6], "res/textures/cat_walk.png", sf::IntRect(24 * 6, 24 * 0, 24, 24));
	loadTexture(PLAYER_WALK[7], "res/textures/cat_walk.png", sf::IntRect(24 * 7, 24 * 0, 24, 24));
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