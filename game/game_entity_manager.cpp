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

Entity** EntityManager::entities;
unsigned EntityManager::entityIndex;
unsigned EntityManager::currentSize;
unsigned EntityManager::removeFlag;

void EntityManager::initializeEntityArray() {
	entities = new Entity*[MAXIMUM_SIZE](); // 256 * 256 is the maximum amount of possible entities
	entityIndex = 0;
	currentSize = 0;
	removeFlag = 0;
}

void EntityManager::addEntity(Entity* e) {
	if (currentSize < MAXIMUM_SIZE - 1) {
		entities[entityIndex] = e;
		e->index = entityIndex;
		++currentSize;
		if (removeFlag) {
			entityIndex = checkRemoved();
		} else {
			++entityIndex;
		}
	} else {
		Log::log("Maximum amount of entities was exceeded!", "[ERROR]");
	}
}

unsigned EntityManager::checkRemoved() {
	for (unsigned i = 0; i < currentSize; ++i) {
		if (entities[i] == nullptr) {
			--removeFlag;
			return i;
		}
	}
}

void EntityManager::removeEntity(unsigned index) {
	delete entities[index];
	entities[index] = nullptr;
	++removeFlag;
	--currentSize;
}

void EntityManager::checkCollisions() {

}

void EntityManager::clearEntities() {
	for (int i = 0; i < currentSize; ++i){
		delete entities[i];
	}

	delete[] entities;
}

void EntityManager::update(sf::RenderWindow* window, Map& map) {
	for (int i = 0; i < currentSize; ++i) {
		if (entities[i] != nullptr) {
			entities[i]->update(window, map);
		}
	}
}

void EntityManager::render(sf::RenderWindow* window, Textures& textures, int x0, int y0, int x1, int y1) {
	for (int i = 0; i < currentSize; ++i) {
		if (entities[i] != nullptr) {
			int ex0 = (int)entities[i]->bounds.left >> 6;
			int ey0 = (int)entities[i]->bounds.top >> 6;
			int ex1 = (int)(entities[i]->bounds.left + entities[i]->bounds.width) >> 6;
			int ey1 = (int)(entities[i]->bounds.top + entities[i]->bounds.height) >> 6;

			if (ex0 < x1 && ex1 > x0 && ey0 < y1 && ey1 > y0) {
				entities[i]->render(window, textures);
			}
		}
	}
}