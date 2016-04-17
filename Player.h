#ifndef _PLAYER__
#define _PLAYER__

#include "world.h"
#include "Entity.h"
#include "items.h"

class Player :public Entity
{
public:
	Room* position;
	Player();
	Player(int&, int&, Room*);
	int hp = 10;
	int damage = 10;
};

#endif