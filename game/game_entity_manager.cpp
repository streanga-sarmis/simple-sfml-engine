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

#include "game_entity_manager.hpp"

//Entity** EntityManager::entities;
std::list<Entity*> EntityManager::entities;
std::list<Entity*>* EntityManager::entitiesInTiles;

void EntityManager::addEntity(Entity* e) {
	entities.emplace_front(e);
}

void EntityManager::removeEntity(Entity* e) {
	e->removed = true;
}

void EntityManager::checkCollisions(Entity* th, Map& map) {
	int x = (int)(th->position.x) >> 6;
	int y = (int)(th->position.y) >> 6;
	if (x >= 0 && x < map.width && y >= 0 && y < map.height) {
		for (std::list<Entity*>::iterator it = entitiesInTiles[x + y * map.width].begin();
			it != entitiesInTiles[x + y * map.width].end();) {
			// remember to make collision bounds
			if ((*it) != th) {
				if (th->entityCollider.intersects((*it)->entityCollider)) {
					th->touchedEntity(*it++);
				}
				else {
					*it++;
				}
			}
			else {
				*it++;
			}
		}
	}
}

void EntityManager::clearEntities() {
	for (std::list<Entity*>::iterator it = entities.begin(); it != entities.end();){
		delete *it++;
	}

	entities.clear();

	delete[] entitiesInTiles;
}

void EntityManager::initializeEntityMapping(Map& map) {
	entitiesInTiles = new std::list<Entity*>[map.width * map.height];
}

void EntityManager::update(sf::RenderWindow* window, Map& map) {
	for (std::list<Entity*>::iterator it = entities.begin(); it != entities.end();) {
		if (*it != nullptr) {
			float x0 = (*it)->position.x;
			float y0 = (*it)->position.y;
			(*it)->update(window, map);
			if ((*it)->removed) {
				int ox = (int)(x0) >> 6;
				int oy = (int)(y0) >> 6;
				if ((*it)->canCollide) {
					entitiesInTiles[ox + oy * map.width].remove((*it));
				}
				entities.remove(*it++);
				continue;
			}
			if ((*it)->canCollide) {

				float x1 = (*it)->position.x;
				float y1 = (*it)->position.y;
				if (x0 != x1 || y0 != y1) {
					int ox = (int)(x0) >> 6;
					int oy = (int)(y0) >> 6;
					int x = (int)(x1) >> 6;
					int y = (int)(y1) >> 6;

					if (x < 0 || x >= map.width || y < 0 || y >= map.height) {
						*it++;
						continue;
					}

					if (ox < 0 || ox >= map.width || oy < 0 || oy >= map.height) {
						*it++;
						continue;
					}

					entitiesInTiles[ox + oy * map.width].remove((*it)); // implement a better data structure here
					entitiesInTiles[x + y * map.width].emplace_back((*it));
				}
			}
			*it++;
		} else {
			*it++;
		}
	}
}

void EntityManager::render(sf::RenderWindow* window, Textures& textures, int x0, int y0, int x1, int y1) {
	for (std::list<Entity*>::iterator it = entities.begin(); it != entities.end();) {
		if (*it != nullptr) {
			int ex0 = (int)((*it)->tileCollider.left) >> 6;
			int ey0 = (int)((*it)->tileCollider.top) >> 6;
			int ex1 = (int)((*it)->tileCollider.left + (*it)->tileCollider.width) >> 6;
			int ey1 = (int)((*it)->tileCollider.top + (*it)->tileCollider.height) >> 6;

			if (ex0 < x1 && ex1 > x0 && ey0 < y1 && ey1 > y0) {
				(*it++)->render(window, textures);
			}
			else {
				*it++;
			}
		} else {
			*it++;
		}

	}
}