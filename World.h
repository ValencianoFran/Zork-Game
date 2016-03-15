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

	World();
	~World();

	void CreatePlayer();
	void CreateWorld();

	void PrintScreen();
	bool HandleInput(char* input);
};

#endif