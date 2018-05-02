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

Map::Map(){

}

Map::Map(unsigned w, unsigned h):
width(w), height(h) {
	if (!texture[0].loadFromFile("res/textures/dirt.png")) {
	}

	if (!texture[1].loadFromFile("res/textures/water.png")) {
	}

	tiles = new Tile[width * height];
	loaded = false;
}

Map::~Map() {
	delete[] tiles;
}

void Map::generateTerrain() {
	if (tiles != nullptr) {
		for (int i = 0; i < width * height; ++i) {
			if (i % 3 == 0) {
				tiles[i].type = 1;
			}
			else {
				tiles[i].type = 0;
			}
		}
	}
	loaded = true;
}

void Map::setTile(Tile tile, int position) {
	tiles[position] = tile;
}


Tile Map::getTile(Tile tile, int position) {
	return tiles[position];
}

void Map::renderTile(sf::RenderWindow* window, unsigned char type, int x, int y) {
	Screen::renderSprite(window, texture[type], x * 30, y * 30, 2, 2);
}

void Map::render(sf::RenderWindow* window, int xOffset, int yOffset) {
	// compute the culling
	for (int y = 0; y < 100; ++y) {
		for (int x = 0; x < 100; ++x) {
			renderTile(window, tiles[x + y * width].type, x, y);
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