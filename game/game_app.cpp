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

#include "game_app.hpp"

#include <iostream> // remove

App::App() {
	StateMachine::pushState(new MenuState());
}

App::~App() {
	StateMachine::clearStates();
}

void App::run(sf::RenderWindow* window) {
	Screen::initializeFont();
	sf::Event event;

	while (window->isOpen()) {
		update(window, event);
		render(window);
	}
}

void App::update(sf::RenderWindow* window, sf::Event& event) {
	while (window->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window->close();
			break;

		case sf::Event::MouseButtonPressed:
			StateMachine::getCurrentState()->checkMouseClicked(window, event);
			break;
		default:
			// Log::log("Unhandled event");
			break;
		}
	}
	
	if (StateMachine::getCurrentState() != nullptr) {
		StateMachine::getCurrentState()->update(window);
	}
}

void App::render(sf::RenderWindow* window) {
	if (StateMachine::getCurrentState() != nullptr) {
		StateMachine::getCurrentState()->render(window);
	}

	window->display();
}