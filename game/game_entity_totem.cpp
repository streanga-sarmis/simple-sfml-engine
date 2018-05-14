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

#include "game_entity_totem.hpp"

Totem::Totem(float x, float y) {
	position.x = x;
	position.y = y;

	tileCollider.left = position.x;
	tileCollider.top = position.y;
	tileCollider.width = 128;
	tileCollider.height = 128;

	entityCollider.left = position.x;
	entityCollider.top = position.y;
	entityCollider.width = 128;
	entityCollider.height = 128;
}

Totem::~Totem() {

}

void Totem::touchedItem(Item* item) {
}

void Totem::touchedEntity(Entity* other) {
}

void Totem::update(sf::RenderWindow* window, Map& map) {

}
void Totem::render(sf::RenderWindow* window, Textures& textures) {
}