#ifndef _WORLD__
#define _WORLD__

#include "room.h"
#include "player.h"
#include "exit.h"

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

	void Mayus(char[]);
	void Go(char[]);
	int Direction(char[]);
	void Action(char[], char[]);
	void Look(char[]);
	void Close(char[]);
	void Open(char[]);
};

#endif