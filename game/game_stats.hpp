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

#include "game_item_gun.hpp"

class Stats{
public:
	struct Synergies {
		int bonusAmmo;
		int bonusShootingRate; // inceases the fire rate on any weapon
		int bonusBulletDamage; // add damage to all the bullets
		int bonusBulletSpeed; // increases bullet velocity/speed
		bool poisonousBullet;
		bool poisonousBody;
		bool burningBullet; // ...I think you got the idea
		bool burningBody; // body refers to the player..duh
		float bonusSpeed;
		float regeneration;
		float bulletScale; // decrease the scale of the bullet

		Synergies() :
		bonusAmmo(0), bonusShootingRate(0), bonusBulletDamage(0), bonusBulletSpeed(0), poisonousBullet(false), poisonousBody(false), burningBullet(false),
		burningBody(false), bonusSpeed(0), regeneration(0), bulletScale(0){
		}

		void addStats(const Synergies& other) {
			bonusAmmo += other.bonusAmmo;
			bonusShootingRate += other.bonusShootingRate;
			bonusBulletDamage += other.bonusBulletDamage;
			bonusBulletSpeed += other.bonusBulletSpeed;
			if (!poisonousBullet) {
				poisonousBullet = other.poisonousBullet;
			}

			if (!poisonousBody) {
				poisonousBody = other.poisonousBody;
			}

			if (!burningBullet) {
				burningBullet = other.burningBullet;
			}

			if (!burningBody) {
				burningBody = other.burningBody;
			}
			bonusSpeed += other.bonusSpeed;
			regeneration += other.regeneration;
			bulletScale += other.bulletScale;
		}
		// make alse a remove stats, like, for armour and stuff
	};

	static int playerHealth;
	static Gun* playerGun;
};