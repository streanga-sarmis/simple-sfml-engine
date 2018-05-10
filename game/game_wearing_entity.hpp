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

#include "game_mob.hpp"
#include "game_item.hpp"
#include "game_item_gun.hpp"
#include "game_item_helmet.hpp"
#include "game_item_shoes.hpp"
#include "game_item_chestplate.hpp"

class WearingEntity : public Mob{
protected:
	//stats
	float regeneration;
	float speedbonus;
	float ammobonus;
	// maybe put them in a equipable list??
	Gun* gun = nullptr;
	Shoes* shoes = nullptr;
	Helmet* helmet = nullptr;
	ChestPlate* chestplate = nullptr;

public:
	virtual void touchedItem(Item* item) = 0;
};