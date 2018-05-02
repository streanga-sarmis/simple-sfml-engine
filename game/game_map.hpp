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

#include "game_tile.hpp"
#include "game_screen.hpp"

class Map {
private:
	sf::Texture texture[2];
	unsigned width;
	unsigned height;
	Tile* tiles;

public:
	bool loaded;

	Map();
	Map(unsigned w, unsigned h);
	~Map();

	void generateTerrain();
	void setTile(Tile tile, int position);
	Tile getTile(Tile tile, int position);
	void renderTile(sf::RenderWindow* window, unsigned char type, int x, int y);
	void render(sf::RenderWindow* window, int xOffset, int yOffset);
};