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

#include "game_projectile.hpp"

Projectile::Projectile(Entity* owner, int x, int y, float angle):
owner(owner), angle(angle){
	bounds.left = x;
	bounds.top = y;
	bounds.width = 48; // 16 scaled 3 times
	bounds.height = 48;
}

Projectile::~Projectile() {

}
