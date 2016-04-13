#ifndef _EXIT__
#define _EXIT__

#include <stdio.h>
#include <stdlib.h>
#include "room.h"
#include "entity.h"
#include "vector.h"
#include "string.h"

enum dir
{
	north = 0,
	south,
	east,
	west,
	up,
	down
};

class Exit : public Entity
{
public:

	Room* origin;
	Room* destination;
	dir direction;
	bool close = false;
	Exit(const char* _name, const char* _desc, Room* orig, Room* dest, const dir direc);
	~Exit();
};


#endif
