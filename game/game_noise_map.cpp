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

#include "game_noise_map.hpp"

NoiseMap::NoiseMap(unsigned width, unsigned height):
width(width), height(height){
	miniMap.create(width, height);

	std::srand(std::time(nullptr));
	groundData = new char[width * height];
	collisionData = new char[width * height];
	overlayData = new char[width * height];

	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < width; ++x) {
			groundData[x + y * width] = SOLID_SHADOW;
			collisionData[x + y * width] = 0;
			overlayData[x + y * width] = SOLID;
		}
	}
}

NoiseMap::~NoiseMap() {
	delete[] groundData;
	delete[] collisionData;
	delete[] overlayData;
}

void NoiseMap::randomizeData() {
	int goDirectionX = width / 2;
	int goDirectionY = height / 2;
	int steps = 4000;

	groundData[goDirectionX + goDirectionY * width] = GROUND;
	groundData[goDirectionX + 1 + goDirectionY * width] = GROUND;
	groundData[goDirectionX - 1 + goDirectionY * width] = GROUND;
	groundData[goDirectionX + (goDirectionY + 1) * width] = GROUND;
	groundData[goDirectionX + (goDirectionY - 1) * width] = GROUND;
	groundData[goDirectionX + 1 + (goDirectionY + 1) * width] = GROUND;
	groundData[goDirectionX - 1 + (goDirectionY - 1) * width] = GROUND;
	groundData[goDirectionX + 1 + (goDirectionY + 1) * width] = GROUND;
	groundData[goDirectionX - 1 + (goDirectionY - 1) * width] = GROUND;

	collisionData[goDirectionY + goDirectionY * width] = -1;
	collisionData[goDirectionX + 1 + goDirectionY * width] = -1;
	collisionData[goDirectionX - 1 + goDirectionY * width] = -1;
	collisionData[goDirectionX + (goDirectionY + 1) * width] = -1;
	collisionData[goDirectionX + (goDirectionY - 1) * width] = -1;
	collisionData[goDirectionX + 1 + (goDirectionY + 1) * width] = -1;
	collisionData[goDirectionX - 1 + (goDirectionY - 1) * width] = -1;
	collisionData[goDirectionX + 1 + (goDirectionY + 1) * width] = -1;
	collisionData[goDirectionX - 1 + (goDirectionY - 1) * width] = -1;

	overlayData[goDirectionX + goDirectionY * width] = -1;
	overlayData[goDirectionX + 1 + goDirectionY * width] = -1;
	overlayData[goDirectionX - 1 + goDirectionY * width] = -1;
	overlayData[goDirectionX + (goDirectionY + 1) * width] = -1;
	overlayData[goDirectionX + (goDirectionY - 1) * width] = -1;
	overlayData[goDirectionX + 1 + (goDirectionY + 1) * width] = -1;
	overlayData[goDirectionX - 1 + (goDirectionY - 1) * width] = -1;
	overlayData[goDirectionX + 1 + (goDirectionY + 1) * width] = -1;
	overlayData[goDirectionX - 1 + (goDirectionY - 1) * width] = -1;



	while (steps--) {
		checkDirection = std::rand() % 4;

		switch (checkDirection) {
		case UP:
			if (goDirectionY - 1 > 0) {
				--goDirectionY;
			}
			break;

		case DOWN:
			if (goDirectionY + 1 < height) {
				++goDirectionY;
			}
			break;

		case LEFT:
			if (goDirectionX - 1 > 0) {
				--goDirectionX;
			}
			break;

		case RIGHT:
			if (goDirectionX + 1 < width) {
				++goDirectionX;
			}
			break;

		default:
			break;
		}

		groundData[goDirectionX + goDirectionY * width] = GROUND;
		collisionData[goDirectionX + goDirectionY * width] = -1;
		overlayData[goDirectionX + goDirectionY * width] = -1;
	}




	/*
	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < width; ++x) {
			if (std::rand() % 10 == 0) {
				groundData[x + y * width] = SOLID;
				collisionData[x + y * width] = 0;
			} else {
				groundData[x + y * width] = GROUND;
			}
		}
	}
	*/
}

void NoiseMap::organizeData(){
	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < width; ++x) {
			if ((groundData[(x + 1) + (y + 0) * width] == GROUND || groundData[(x + 1) + (y + 0) * width] == SHADOW_GROUND) &&
				(groundData[(x - 1) + (y + 0) * width] == GROUND || groundData[(x - 1) + (y + 0) * width] == SHADOW_GROUND) &&
				(groundData[(x + 0) + (y + 1) * width] == GROUND || groundData[(x + 0) + (y + 1) * width] == SHADOW_GROUND) &&
				(groundData[(x + 0) + (y - 1) * width] == GROUND) || groundData[(x + 0) + (y - 1) * width] == SHADOW_GROUND){
				groundData[x + y * width] = GROUND;
				overlayData[x + y * width] = -1;
				collisionData[x + y * width] = -1;
			}
		}
	}


	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < width; ++x) {
			if (groundData[x + y * width] == SOLID_SHADOW) {
				if (y + 1 < height) {
					if (groundData[x + (y + 1) * width] != SOLID_SHADOW) {
						overlayData[x + y * width] = -1; // if there is a solid block somewhere up for another solid block, don't overwrite the overlay
					}
				}
			}
		}
	}

	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < width; ++x) {
			if (groundData[x + y * width] != SOLID_SHADOW) {
				if (y - 1 > 0) {
					if (groundData[x + (y - 1) * width] == SOLID_SHADOW) {
						groundData[x + y * width] = SHADOW_GROUND;
						overlayData[x + y * width] = -1; // no overlay over shadows
					}
				}
			}
		}
	}

	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < width; ++x) {
			if (groundData[x + y * width] != SOLID_SHADOW) {
				if (y + 1 < height) {
					if (groundData[x + (y + 1) * width] == SOLID_SHADOW) {
						overlayData[x + y * width] = SOLID;// overlay on non-solid blocks if there are solid blocks below them
					}
				}
			}
		}
	}

	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < width; ++x) {
			if (overlayData[x + y * width] != -1) {
				groundData[x + y * width] = -1;// don't render something that is under another tile
			}
		}
	}

	for (unsigned y = 0; y < height; ++y) {
		groundData[0 + y * width] = SOLID_SHADOW;
		overlayData[0 + y * width] = SOLID;
		collisionData[0 + y * width] = 0;
	}
	
	for (unsigned y = 0; y < height; ++y) {
		groundData[width - 1 + y * width] = SOLID_SHADOW;
		overlayData[width - 1 + y * width] = SOLID;
		collisionData[width - 1 + y * width] = 0;
	}
	
	for (unsigned x = 0; x < width; ++x) {
		groundData[x + 0 * width] = SOLID_SHADOW;
		if (groundData[x + (1) * width] != SOLID_SHADOW) {
			groundData[x + (1) * width] = SOLID_SHADOW;
			collisionData[x + (1) * width] = 0;
		}
		overlayData[x + 0 * width] = SOLID;
		collisionData[x + 0 * width] = 0;
	}

	for (unsigned x = 0; x < width; ++x) {
		groundData[x + (height - 1) * width] = SOLID_SHADOW;
		overlayData[x + (height - 1) * width] = SOLID;
		collisionData[x + (height - 1) * width] = 0;
	}

	for (unsigned y = 0; y < height; y += 2) {
		for (unsigned x = 0; x < width; x += 2) {
			// move the tiles that cannot be reached to the gound tiles so they are not sorted
			// thus there is no overhead for sorting tiles that don't matter
			int x0 = x - 1;
			int y0 = y - 1;
			int x1 = x + 1;
			int y1 = y + 1;

			bool u = overlayData[x + y1 * width] != -1;
			bool d = overlayData[x + y0 * width] != -1;
			bool l = overlayData[x0 + y * width] != -1;
			bool r = overlayData[x1 + y * width] != -1;

			bool ul = u && l;
			bool ur = u && r;
			bool dl = d && l;
			bool dr = d && r;

			if (x0 < 0 || x1 >= width || y0 < 0 || y1 >= width) {
				continue;
			}

			if (overlayData[x + y * width] != -1) {
				if (ul && ur && dl && dr) {
					groundData[x + y * width] = overlayData[x + y * width];
					overlayData[x + y * width] = -1;
				}
			}
		}
	}
	// making the minimap
	//unsigned char* pixels = new unsigned char[width * height * 4];
	/*
	for (int i = 0; i < width * height * 4; i += 4) {
		pixels[i + 0] = 255;//(groundData[i] << 24) & 0xff;
		pixels[i + 1] = 255;//(groundData[i] << 16) & 0xff;
		pixels[i + 2] = 255;//(groundData[i] << 8) & 0xff;
		pixels[i + 3] = 255;//(groundData[i]) & 0xff;
	}
	*/
	//miniMap.update((sf::Uint8*)pixels);

	//miniMap.loadFromMemory(pixels, width * height);
	//delete[] pixels;
}