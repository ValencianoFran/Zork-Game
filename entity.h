#ifndef _ENTITY_
#define _ENTITY_

#include "room.h"
#include "player.h"
#include "exit.h"

class Entity
{
public:

	Room* room;
	Exit* exits;

	Entity();
	void CreateDescriptions() const;
	void Look();
	void Remove();
	void Insert();
	~Entity();
};


#endif