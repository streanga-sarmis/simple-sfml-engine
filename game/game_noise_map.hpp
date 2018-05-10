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

#pragma once

#include <iostream> // remove
#include <ctime>

#define SOLID 48
#define SOLID_SHADOW 49
#define GROUND 37
#define SHADOW_GROUND 53

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

class NoiseMap {
public:
	int checkDirection;
	unsigned width;
	unsigned height;
	char* groundData;
	char* collisionData;
	char* overlayData;

	NoiseMap(unsigned width, unsigned height);
	~NoiseMap();

	void randomizeData();
	void organizeData();
};