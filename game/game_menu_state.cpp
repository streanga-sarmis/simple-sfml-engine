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

#include "game_menu_state.hpp"

void startGame(){
	StateMachine::pushState(new MapLoaderState());
}

void about() {

}

void exitGame(sf::RenderWindow* window) {
	window->close();
}

MenuState::MenuState() {
	// add access to window width and height
	buttons.emplace_back(Button("Start Game", 500, 400, 200, 50, &startGame));
	buttons.emplace_back(Button("About", 500, 470, 200, 50, &about));
	buttons.emplace_back(Button("Exit", 500, 540, 200, 50, &exitGame));
}

MenuState::~MenuState() {
	buttons.clear();
}

void MenuState::checkMouseClicked(sf::RenderWindow* window, sf::Event& event) {
	for (int i = 0; i < buttons.size(); ++i) {
		if (buttons[i].checkBounds(event)){
			if (i == buttons.size() - 1) {
				buttons[i].exec(window);
			} else {
				buttons[i].exec();
			}
			break;
		}
	}
}

void MenuState::update(sf::RenderWindow* window) {

}

void MenuState::render(sf::RenderWindow* window) {
	for (int i = 0; i < buttons.size(); ++i) {
		buttons[i].render(window);
	}
	Screen::renderText(window, "Game!", 500, 20, 256);
}
