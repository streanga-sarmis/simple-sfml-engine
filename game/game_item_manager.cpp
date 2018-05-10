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

#include "game_item_manager.hpp"

std::list<Item*> ItemManager::offHand;
std::list<Item*> ItemManager::onHand; // very good naming...
std::list<Item*>* ItemManager::itemsInTiles;


void ItemManager::initializeItemMapping(Map& map) {
	itemsInTiles = new std::list<Item*>[map.width * map.height];
}

void ItemManager::addItem(Item* item) {
	if (item->onHand) {
		onHand.emplace_back(item);
	} else {
		offHand.emplace_back(item);
	}
}

void ItemManager::checkCollisions(WearingEntity* th, Map& map) {
	int x = (int)(th->position.x) >> 6;
	int y = (int)(th->position.y) >> 6;
	if (x >= 0 && x < map.width && y >= 0 && y < map.height) {
		for (std::list<Item*>::iterator it = itemsInTiles[x + y * map.width].begin();
			it != itemsInTiles[x + y * map.width].end();) {
			// remember to make collision bounds
			if (!(*it)->onHand) {
				if (th->entityCollider.intersects((*it)->bounds)) {
					th->touchedItem(*it++);
				} else {
					*it++;
				}
			} else {
				*it++;
			}
		}
	}
}

void ItemManager::removeItem(Item* item) {
	item->removed = true;
}

void ItemManager::updateOffHand(Map& map) {
	for (std::list<Item*>::iterator it = offHand.begin(); it != offHand.end();) {
		if (*it != nullptr) {
			if ((*it)->removed) {
				float x = (*it)->bounds.left; 
				float y = (*it)->bounds.top;
				int xx = (int)(x) >> 6;// try not to store these things, just use them
				int yy = (int)(y) >> 6;
				itemsInTiles[xx + yy * map.width].remove((*it));
				offHand.remove(*it++);
				continue;
			}

			if ((*it)->onHand) {
				onHand.emplace_back(*it);
				offHand.remove(*it++);
				continue;
			}

			float x0 = (*it)->oldBounds.x; // a bit confusing and useless method to store change since I update both of them in the same time
			float y0 = (*it)->oldBounds.y;
			(*it)->update();
			float x1 = (*it)->bounds.left;
			float y1 = (*it)->bounds.top;

			int ox = (int)(x0) >> 6;
			int oy = (int)(y0) >> 6;
			int x = (int)(x1) >> 6;
			int y = (int)(y1) >> 6;

			if (ox < 0 || ox >= map.width || oy < 0 || oy >= map.height) {
				*it++;
				continue;
			}

			if (x < 0 || x >= map.width || y < 0 || y >= map.height) {
				*it++;
				continue;
			}

			if (ox != x || oy != y) {
				itemsInTiles[ox + oy * map.width].remove((*it));
				itemsInTiles[x + y * map.width].emplace_back((*it));
			}

			*it++;
		} else {
			*it++;
		}
	}
}

void ItemManager::updateOnHand(Map& map) {
	for (std::list<Item*>::iterator it = onHand.begin(); it != onHand.end();) {
		if (*it != nullptr) {
			if ((*it)->removed) {
				float x = (*it)->bounds.left;
				float y = (*it)->bounds.top;
				int xx = (int)(x) >> 6;// try not to store these things, just use them
				int yy = (int)(y) >> 6;
				itemsInTiles[xx + yy * map.width].remove((*it));
				onHand.remove(*it++);
				continue;
			}

			if (!(*it)->onHand) {
				offHand.emplace_back(*it);
				onHand.remove(*it++);
				continue;
			}

			float x0 = (*it)->oldBounds.x;
			float y0 = (*it)->oldBounds.y;
			(*it)->update();
			float x1 = (*it)->bounds.left;
			float y1 = (*it)->bounds.top;

			int ox = (int)(x0) >> 6;
			int oy = (int)(y0) >> 6;
			int x = (int)(x1) >> 6;
			int y = (int)(y1) >> 6;

			if (ox < 0 || ox >= map.width || oy < 0 || oy >= map.height) {
				*it++;
				continue;
			}

			if (x < 0 || x >= map.width || y < 0 || y >= map.height) {
				*it++;
				continue;
			}

			if (ox != x || oy != y) {
				itemsInTiles[ox + oy * map.width].remove((*it));
				itemsInTiles[x + y * map.width].emplace_back((*it));
			}

			*it++;
		}
		else {
			*it++;
		}
	}
}

void ItemManager::renderOffHand(sf::RenderWindow* window, Textures& textures, int x0, int y0, int x1, int y1) {
	for (std::list<Item*>::iterator it = offHand.begin(); it != offHand.end();) {
		if (*it != nullptr) {
			int ex0 = (int)((*it)->bounds.left) >> 6;
			int ey0 = (int)((*it)->bounds.top) >> 6;
			int ex1 = (int)((*it)->bounds.left + (*it)->bounds.width) >> 6;
			int ey1 = (int)((*it)->bounds.top + (*it)->bounds.height) >> 6;

			if (ex0 < x1 && ex1 > x0 && ey0 < y1 && ey1 > y0) {
				(*it++)->render(window, textures);
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

void ItemManager::renderOnHand(sf::RenderWindow* window, Textures& textures, int x0, int y0, int x1, int y1) {
	for (std::list<Item*>::iterator it = onHand.begin(); it != onHand.end();) {
		if (*it != nullptr) {
			int ex0 = (int)(*it)->bounds.left >> 6;
			int ey0 = (int)(*it)->bounds.top >> 6;
			int ex1 = (int)((*it)->bounds.left + (*it)->bounds.width) >> 6;
			int ey1 = (int)((*it)->bounds.top + (*it)->bounds.height) >> 6;

			if (ex0 < x1 && ex1 > x0 && ey0 < y1 && ey1 > y0) {
				(*it++)->render(window, textures);
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

void ItemManager::clearItems() {
	for (std::list<Item*>::iterator it = offHand.begin(); it != offHand.end();) {
		delete *it++;
	}

	for (std::list<Item*>::iterator it = onHand.begin(); it != onHand.end();) {
		delete *it++;
	}

	offHand.clear();
	onHand.clear();

	delete[] itemsInTiles;
}