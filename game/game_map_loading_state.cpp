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

#include "game_map_loading_state.hpp"

MapLoaderState::MapLoaderState() {
	map = new Map();

	Util::log("Generatig terrain");
	displayed = false;
}

MapLoaderState::~MapLoaderState() {
	delete map;
}

void MapLoaderState::checkMouseClicked(sf::RenderWindow* window, sf::Event& event) {

}

void MapLoaderState::update(sf::RenderWindow* window) {
	if (map->loaded) {
		window->setMouseCursorVisible(false);
		StateMachine::pushState(new PlayState(map));
	}
}

void MapLoaderState::render(sf::RenderWindow* window) {
	if (!displayed) {
		Screen::renderText(window, "Loading map...", 100, 100, 50);
		displayed = !displayed;
		//map->generateTerrain();
		map->mapRolesToTiles();
	}
}