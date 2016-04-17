#ifndef _ITEMS__
#define _ITEMS__

#include "Entity.h"
#include "string.h"
#include "vector.h"
#include "room.h"
#include "player.h"
#include "world.h"

enum equip
{
	Head,
	Hand,
	Cant_Equip
};

class Items : public Entity
{
public:

	Room* place;
	bool picked = false;
	bool equipped = false;
	equip slot;
	int bag;
	int item_hp;
	int item_damage;
	Items();
	~Items();
	Items(const char* _name, const char* _description, Room*, const int& hp, const int& dmg, const equip);
	void Look()const;
};


#endif