#ifndef _WORLD__
#define _WORLD__

#include "room.h"
#include "player.h"
#include "exit.h"
#include "entity.h"
#include "vector.h"
#include "string.h"


class World : public Entity
{
public:
	Vector <Room*> room;
	Vector <Exit*> exit;
	Player* player;
	

	World();
	~World();
	void Tutorial() const;
	void CreatePlayer() const;
	void CreateWorld();

	void Mayus(char[]);
	void Go(char[]);
	int Direction(char[]);
	void Action(char[], char[], char[], char[]);
	void Look(char[]);
	void Close(char[]);
	void Open(char[]);

};

#endif