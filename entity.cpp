#include "room.h"
#include "player.h"
#include "exit.h"
#include "entity.h"
#include "string.h"
#include <stdio.h>

#define NUM_EXITS 16

Entity::Entity(const char* _name, const char* _desc)
{
	name = _name;
	description = _desc;
}

Entity::~Entity()
{

}
