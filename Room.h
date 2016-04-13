#ifndef _ROOMS__
#define _ROOMS__

#include "entity.h"
#include "vector.h"
#include "string.h"

class Room : public Entity
{
public:
	Room(const char* _name, const char* _description);
	~Room();
};

#endif