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

#include "game_small_spark.hpp"

SmallSpark::SmallSpark(float x, float y) :
	AnimationParticle(x, y, 0, 30) {
	frames.initializeAnimation(6, lifetime / 6);
}

SmallSpark::SmallSpark(float x, float y, int lifetime) :
	AnimationParticle(x, y, 0, lifetime) {
	frames.initializeAnimation(6, 5);
}

SmallSpark::SmallSpark(float x, float y, float angle, int lifetime):
	AnimationParticle(x, y, angle, lifetime){
}

SmallSpark::~SmallSpark() {

}


void SmallSpark::touchedEntity(Entity* other) {

}

void SmallSpark::render(sf::RenderWindow* window, Textures& textures) {
	frames.render(window, textures.SMALL_SPARK, position.x, position.y, position.z, 3, 3);
}
