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

#include "game_camera.hpp"

int Camera::xs = 0;
int Camera::ys = 0;
int Camera::x0 = 0;
int Camera::y0 = 0;
int Camera::x1 = 0;
int Camera::y1 = 0;

void Camera::computeScreenBounds(int xc, int yc, unsigned wx, unsigned wy) {
	xs = xc - wx / 2;
	ys = yc - wy / 2;

	x0 = (xs - 64) >> 6;
	y0 = (ys - 64) >> 6;
	x1 = x0 + ((wx + 64 + 64) >> 6);
	y1 = y0 + ((wy + 64 + 64) >> 6);
}

void Camera::update() {
	Screen::offset(xs, ys);
}

void Camera::shake() {
	xs += std::rand() % 10;
	ys += std::rand() % 10;
	Screen::offset(xs, ys);
}