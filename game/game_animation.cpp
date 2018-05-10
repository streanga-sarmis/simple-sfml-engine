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

#include "game_animation.hpp"

Animation::Animation() {
	time = 0;
	frames = 0;
	interval = 0;
}

Animation::~Animation() {
}

void Animation::initializeAnimation(unsigned frames, unsigned interval) {
	this->frames = frames;
	this->interval = interval;
}

void Animation::step() {
	++time;
}

void Animation::render(sf::RenderWindow* window, sf::Texture* texture, int x, int y, float z, int xs, int ys, bool mx, bool my, const sf::Color& color) {
	Screen::renderSprite(window, texture[(time / interval) % frames], x, y, z, xs, ys, mx, my, 0, color);
}
