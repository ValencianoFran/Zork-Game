#ifndef _ENTITY_
#define _ENTITY_

#include "room.h"
#include "player.h"
#include "exit.h"
#include "vector.h"
#include "string.h"

class Entity
{
public:

	String name;
	String description;
	

	Entity(const char*, const char*);
	void Look();
	void Remove();
	void Insert();
	~Entity();
};


#endif