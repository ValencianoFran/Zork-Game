#include "items.h"

Items::Items()
{}

Items::Items(const char* _name, const char* _description, Room* _place, const int& _hp, const int& _dmg, const equip _slot)
: place(_place), Entity(_name, _description), item_hp(_hp), item_damage(_dmg), slot(_slot)
{}


void Items::Look()const
{
	printf("%s\n%s\n", name.c_str(), description.c_str());
}

Items::~Items()
{}