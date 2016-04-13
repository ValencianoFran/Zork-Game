#include "room.h"
#include "player.h"
#include "exit.h"
#include "entity.h"
#include "string.h"
#include <stdio.h>

#define NUM_EXITS 16

Entity::Entity()
{}

Entity::Entity(const char* _name, const char* _description)
{
	name = _name;
	description = _description;
}

Entity::~Entity()
{
}

void Entity::Look()
{}

void Entity::Insert()
{}

void Entity::Remove()
{}