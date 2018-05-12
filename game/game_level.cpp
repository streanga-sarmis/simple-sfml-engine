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
#include "game_entity_blue_gem_enemy.hpp"//remove

Level::Level(Map* map):
map(map){
	player = new Player();

	AIManager::initializeAiManager(player);
	EntityManager::initializeEntityMapping(*map);
	ItemManager::initializeItemMapping(*map);

	EntityManager::addEntity(player);

	for (int y = 0; y < map->height; ++y) {
		for (int x = 0; x < map->width; ++x) {
			if (std::rand() % 10 == 2 && map->collisionTiles[x + y * map->width].type) {
				EntityManager::addEntity(new BlueGemEnemy((x << 6), (y << 6)));
			}
		}
	}
}

Level::~Level() {
	EntityManager::clearEntities();
	ItemManager::clearItems(); // don't forget about this when implementing multiple levels
}

void Level::update(sf::RenderWindow* window) {
	EntityManager::update(window, *map);
	ItemManager::updateOffHand(*map);
	ItemManager::updateOnHand(*map);
}

void Level::render(sf::RenderWindow* window, Textures& textures) {
	Camera::computeScreenBounds(player->position.x, player->position.y, window->getSize().x, window->getSize().y);

	map->render(window, textures, Camera::x0, Camera::y0, Camera::x1, Camera::y1);

	ItemManager::renderOffHand(window, textures, Camera::x0, Camera::y0, Camera::x1, Camera::y1);

	EntityManager::render(window, textures, Camera::x0, Camera::y0, Camera::x1, Camera::y1);

	ItemManager::renderOnHand(window, textures, Camera::x0, Camera::y0, Camera::x1, Camera::y1);

	map->renderOverlay(window, textures, Camera::x0, Camera::y0, Camera::x1, Camera::y1);
}