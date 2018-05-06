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
	Camera::computeScreenBounds(player->bounds.left, player->bounds.top, window->getSize().x, window->getSize().y);

	map->render(window, textures, Camera::x0, Camera::y0, Camera::x1, Camera::y1);

	EntityManager::render(window, textures, Camera::x0, Camera::y0, Camera::x1, Camera::y1);

	map->renderOverlay(window, textures, Camera::x0, Camera::y0, Camera::x1, Camera::y1);
}