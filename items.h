#ifndef _ITEMS__
#define _ITEMS__

#include "Entity.h"
#include "string.h"
#include "vector.h"
#include "room.h"
#include "player.h"

class Items : public Entity
{
public:
	Room* place;
	int item_hp;
	int item_damage;
	Items(Room*, const char* _name, const char* _description, const int&, const int&);
};


#endif