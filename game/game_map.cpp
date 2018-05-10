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

#include "game_map.hpp"

Map::Map():
width(64), height(64){

	NoiseMap noiseMap(width, height);

	noiseMap.randomizeData();
	noiseMap.organizeData();

	tiles = new Tile[width * height];
	overlayTiles = new Tile[width * height];
	collisionTiles = new Tile[width * height];

	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			tiles[x + y * width].type = noiseMap.groundData[x + y * width];
			collisionTiles[x + y * width].type = noiseMap.collisionData[x + y * width];
			overlayTiles[x + y * width].type = noiseMap.overlayData[x + y * width];
		}
	}

	loaded = false;
}

Map::~Map() {
	delete[] tiles;
	delete[] overlayTiles;
	delete[] collisionTiles;
}

void Map::mapRolesToTiles() {
	/*
	CSVParser::Data gTiles = CSVParser::parseFileToData("res/maps/map_ground.csv");
	CSVParser::Data oTiles = CSVParser::parseFileToData("res/maps/map_overlay.csv");
	CSVParser::Data cTiles = CSVParser::parseFileToData("res/maps/map_collision.csv");
	unsigned w = gTiles.width;
	unsigned h = gTiles.height;

	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			tiles[x + y * w].type = gTiles.values[x + y * w];
			overlayTiles[x + y * w].type = oTiles.values[x + y * w];
			collisionTiles[x + y * w].type = cTiles.values[x + y * w];
		}
	}
	CSVParser::clearData(gTiles);
	CSVParser::clearData(oTiles);
	CSVParser::clearData(cTiles);
	*/
	loaded = true;
}

void Map::generateTerrain() {
}

void Map::setTile(Tile tile, int position) {
	tiles[position] = tile;
}


Tile Map::getTile(Tile tile, int position) {
	return tiles[position];
}

void Map::renderTileNoSort(sf::RenderWindow* window, Textures& textures, unsigned char type, int x, int y) {
	Screen::renderSpriteNoSort(window, textures.TILES[type], x * 64, y * 64, 4, 4);
}

void Map::renderTile(sf::RenderWindow* window, Textures& textures, unsigned char type, int x, int y) {
	Screen::renderSprite(window, textures.TILES[type], x * 64, y * 64, 0, 4, 4);
}

void Map::render(sf::RenderWindow* window, Textures& textures, int x0, int y0, int x1, int y1) {
	for (int y = y0; y <= y1; ++y) {
		for (int x = x0; x <= x1; ++x) {
			if (x < 0 || x >= width || y < 0 || y >= height) {
				continue;
			}
			if (tiles[x + y * width].type != -1) {
				renderTileNoSort(window, textures, tiles[x + y * width].type, x, y);
			}
		}
	}
}

void Map::renderOverlay(sf::RenderWindow* window, Textures& textures, int x0, int y0, int x1, int y1) {
	for (int y = y0; y <= y1; ++y) {
		for (int x = x0; x <= x1; ++x) {
			if (x < 0 || x >= width || y < 0 || y >= height) {
				continue;
			}
			if (overlayTiles[x + y * width].type != -1) {
				renderTile(window, textures, overlayTiles[x + y * width].type, x, y);
			}
		}
	}
}
/*
Map::Map():
width(512), height(512){
	if (!texture.loadFromFile("res/textures/dirt.png")) {
	}

	tiles = new unsigned char[width * height];
	array = sf::VertexArray(sf::PrimitiveType::Quads, width * height * 4);
	generateTerrain();
	createTerrainMesh();
}

Map::~Map() {
	delete[] tiles;
}

void Map::generateTerrain() {
	for (int i = 0; i < width * height; ++i) {
		tiles[i] = 0;
	}
}

void Map::createTerrainMesh() {
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			if (x == 0 && y == 0) {
				addVertices(x, y, tiles[x + y * width], 0, 16);
			} else {
				addVertices(x, y, tiles[x + y * width], -1, 16);
			}
		}
	}
}

void Map::addVertices(float x, float y, unsigned char type, unsigned offset, unsigned size) {
	array.append(sf::Vertex(sf::Vector2f((0 + x) * (size) + offset, (0 + y) * (size) + offset), sf::Vector2f(0, 0)));
	array.append(sf::Vertex(sf::Vector2f((1 + x) * (size) + offset, (0 + y) * (size) + offset), sf::Vector2f(size, 0)));
	array.append(sf::Vertex(sf::Vector2f((1 + x) * (size) + offset, (1 + y) * (size) + offset), sf::Vector2f(size, size)));
	array.append(sf::Vertex(sf::Vector2f((0 + x) * (size) + offset, (1 + y) * (size) + offset), sf::Vector2f(0, size)));
}

void Map::setTile(Tile tile, int position) {

}

Tile Map::getTile(Tile tile, int position) {
	return Tile();
}

const sf::Texture* Map::getTexture() const{
	return (const_cast<const sf::Texture*>(&texture));
}

void Map::render(sf::RenderWindow* window) {
	sf::RenderStates states(getTexture());
	window->draw(array, states);
}
*/