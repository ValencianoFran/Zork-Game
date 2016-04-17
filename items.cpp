#include "items.h"

Items::Items(Room* _place, const char* _name, const char* _description, const int& _hp, const int& _dmg)
: place(_place), Entity(_name, _description), item_hp(_hp), item_damage(_dmg)
{
	
}