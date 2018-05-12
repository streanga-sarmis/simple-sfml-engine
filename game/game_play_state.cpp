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

#include "game_play_state.hpp"

PlayState::PlayState(Map* map):
level(new Level(map)){
	cursor.setTexture(textures.CURSOR);
	cursor.setScale(0.75, 0.75);
	HUD::initializeAnimations();
}

PlayState::~PlayState() {
	delete level;
}

void PlayState::checkMouseClicked(sf::RenderWindow* window, sf::Event& event) {

}

void PlayState::update(sf::RenderWindow* window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		StateMachine::pushState(new PauseState());
	}
	Camera::update();
	level->update(window);
	HUD::update();
}

void PlayState::render(sf::RenderWindow* window) {
	window->clear(sf::Color::Black);
	
	cursor.setPosition((sf::Vector2f)sf::Mouse::getPosition(*window));

	level->render(window, textures);


	Screen::sortAndRender(window);
	HUD::render(window, textures);
	window->draw(cursor);
}