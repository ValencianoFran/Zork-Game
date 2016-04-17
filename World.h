#ifndef _WORLD__
#define _WORLD__

#include "room.h"
#include "player.h"
#include "exit.h"
#include "Entity.h"
#include "string.h"
#include "vector.h"

class World : public Entity
{
public:
	Player* player;
	Vector <Room*> room;
	Vector <Exit*> exit;

	World();
	~World();
	void Tutorial() const;
	void CreatePlayer() const;
	void CreateWorld();

	void Mayus(String&);
	void Go(const String&);
	int Direction(const String&);
	void Action(Vector <String>&);
	void Look(const String&);
	void Close(const String&);
	void Open(const String&);

};

#endif