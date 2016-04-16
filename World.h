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
	Vector <Room*> room;
	Vector <Exit*> exit;
	Player* player;


	World();
	~World();
	void Tutorial() const;
	void CreatePlayer() const;
	void CreateWorld();

	void Mayus(String&) const;
	void Go(const String&);
	int Direction(const String&);
	void Action(const String&, const String&, const String&, const String&);
	void Look(const String&);
	void Close(const String&);
	void Open(const String&);

};

#endif