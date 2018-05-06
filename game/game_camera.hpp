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

#include "game_screen.hpp"

class Camera {
public:
	static int xs;
	static int ys;
	static int x0;
	static int y0;
	static int x1;
	static int y1;

	static void computeScreenBounds(int xc, int yc, unsigned wx, unsigned wy);
	static void update();
	static void shake();
};