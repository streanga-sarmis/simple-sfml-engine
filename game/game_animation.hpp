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

#pragma once

#include <SFML/Graphics.hpp>

#include "game_screen.hpp"

class Animation {

private:
	unsigned time;
	unsigned interval;

public:
	unsigned frames;

	Animation();
	~Animation();

	void initializeAnimation(unsigned frames, unsigned interval);
	void step();
	void render(sf::RenderWindow* window, sf::Texture* textures, int x, int y, float z, int xs, int ys, bool mx = false, bool my = false,
		const sf::Color& color = sf::Color::White);
};