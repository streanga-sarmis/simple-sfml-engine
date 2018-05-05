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

#include "game_pause_state.hpp"

void returnBack() {
	StateMachine::popState();
}

void returnToMenu() {
	// implement this
}

PauseState::PauseState() {
	// add access to window width and height
	buttons.emplace_back(Button("Return", 500, 400, 200, 50, &returnBack));
	buttons.emplace_back(Button("Go to main menu", 500, 540, 200, 50, &returnToMenu));
}

PauseState::~PauseState() {
	buttons.clear();
}

void PauseState::checkMouseClicked(sf::RenderWindow* window, sf::Event& event) {
	for (int i = 0; i < buttons.size(); ++i) {
		if (buttons[i].checkBounds(event)) {
			buttons[i].exec();
			break;
		}
	}
}

void PauseState::update(sf::RenderWindow* window) {

}

void PauseState::render(sf::RenderWindow* window) {
	for (int i = 0; i < buttons.size(); ++i) {
		buttons[i].render(window);
	}
	Screen::renderText(window, "PAUSE!", 500, 20, 256);
}
