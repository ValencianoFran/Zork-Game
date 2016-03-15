#ifndef _PLAYER__
#define _PLAYER__
#include "room.h"

class Player
{
public:
	Room* pos;
	int hp;
	int damage;
};

#endif