#ifndef _PLAYER__
#define _PLAYER__
#include "room.h"
#include "vector.h"
#include "entity.h"

class Player : public Entity
{
public:
	Room* position;
	Player(int, int, Room*);
	int hp;
	int damage;
};

#endif