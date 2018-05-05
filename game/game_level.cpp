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

#include "game_level.hpp"

Level::Level(Map* map):
map(map){
	player = new Player();
	EntityManager::initializeEntityArray();
	EntityManager::addEntity(player);
}

Level::~Level() {
	EntityManager::clearEntities();
}

void Level::update(sf::RenderWindow* window) {
	EntityManager::update(window, *map);
}

void Level::render(sf::RenderWindow* window, Textures& textures) {
	int xs = player->bounds.left - window->getSize().x / 2;
	int ys = player->bounds.top - window->getSize().y / 2;

	int x0 = xs / 45; // 45 because thats the offset for the tiles
	int y0 = ys / 45;
	int x1 = x0 + ((window->getSize().x + 47) / 45);
	int y1 = y0 + ((window->getSize().y + 47) / 45);

	Screen::offset(xs, ys);

	map->render(window, textures, x0, y0, x1, y1);
	EntityManager::render(window, textures, x0, y0, x1, y1);
	map->renderOverlay(window, textures, x0, y0, x1, y1);
}