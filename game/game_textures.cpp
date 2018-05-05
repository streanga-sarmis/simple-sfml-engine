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

	// first row
	loadTexture(TILES[0], "res/textures/basic_walls.png", sf::IntRect(16 * 0, 16 * 0, TILE_SIZE, TILE_SIZE));
	loadTexture(TILES[1], "res/textures/basic_walls.png", sf::IntRect(16 * 1, 16 * 0, 15, 15));
	loadTexture(TILES[2], "res/textures/basic_walls.png", sf::IntRect(16 * 2, 16 * 0, TILE_SIZE, TILE_SIZE));
	loadTexture(TILES[3], "res/textures/basic_walls.png", sf::IntRect(16 * 3, 16 * 0, TILE_SIZE, TILE_SIZE));
	loadTexture(TILES[4], "res/textures/basic_walls.png", sf::IntRect(16 * 4, 16 * 0, TILE_SIZE, TILE_SIZE));

	// second row
	loadTexture(TILES[5], "res/textures/basic_walls.png", sf::IntRect(16 * 0, 16 * 1, TILE_SIZE, TILE_SIZE));
	loadTexture(TILES[6], "res/textures/basic_walls.png", sf::IntRect(16 * 1, 16 * 1, TILE_SIZE, TILE_SIZE));
	loadTexture(TILES[7], "res/textures/basic_walls.png", sf::IntRect(16 * 2, 16 * 1, 15, 15));
	loadTexture(TILES[8], "res/textures/basic_walls.png", sf::IntRect(16 * 3, 16 * 1, TILE_SIZE, TILE_SIZE));
	loadTexture(TILES[9], "res/textures/basic_walls.png", sf::IntRect(16 * 4, 16 * 1, TILE_SIZE, TILE_SIZE));

	// third row
	loadTexture(TILES[10], "res/textures/basic_floor.png", sf::IntRect(16 * 0, 16 * 0, TILE_SIZE, TILE_SIZE));
	loadTexture(TILES[11], "res/textures/basic_floor.png", sf::IntRect(16 * 1, 16 * 0, TILE_SIZE, TILE_SIZE));
	loadTexture(TILES[12], "res/textures/basic_walls.png", sf::IntRect(16 * 2, 16 * 2, TILE_SIZE, TILE_SIZE));
	loadTexture(TILES[13], "res/textures/basic_walls.png", sf::IntRect(16 * 3, 16 * 2, TILE_SIZE, TILE_SIZE));
	loadTexture(TILES[14], "res/textures/basic_walls.png", sf::IntRect(16 * 4, 16 * 2, TILE_SIZE, TILE_SIZE));
}

Textures::~Textures() {

}

void Textures::loadTexture(sf::Texture& texture, const char* path, const sf::IntRect& rect) {
	if (!texture.loadFromFile(path, rect)) {
		Log::log("Could not load the texture!", "[ERROR]");
	}
}