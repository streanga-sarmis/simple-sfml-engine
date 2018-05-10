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

#include "game_hud.hpp"

float HUD::z = 999;
int HUD::heartsPadding = 32;
Animation HUD::HEART_PUMP;

void HUD::initializeAnimations() {
	HEART_PUMP.initializeAnimation(5, 5);
}

void HUD::update() {
	HEART_PUMP.step();
}

void HUD::render(sf::RenderWindow* window, Textures& textures) {

	Screen::offset(0, 0);

	for (int i = 1; i <= Stats::playerHealth; ++i) {
		HEART_PUMP.render(window, textures.HEART, window->getSize().x - i * 54 - heartsPadding, window->getSize().y - 48 - heartsPadding, z, 3, 3);
	}
}