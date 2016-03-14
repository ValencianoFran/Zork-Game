#ifndef _WORLD__
#define _WORLD__
#include "Room.h"
#include "Player.h"
#include "Exit.h"

class World
{
public:
	Room* room;
	Player* player;
	Exit* exits;
	void CreatePlayer();
	void CreateWorld();
	World();
	~World();
};






#endif