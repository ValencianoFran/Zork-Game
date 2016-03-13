#ifndef _WORLD__
#define _WORLD__
#include "Room.h"
#include "Player.h"
#include "Exit.h"

class World
{
public:
	Room* room;
	World();
	~World();
	Player* player;
	void CreatePlayer();
	void CreateWorld();
};






#endif