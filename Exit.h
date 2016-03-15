#ifndef _EXIT__
#define _EXIT__


#include "room.h"

enum dir
{
	north = 0,
	south,
	east,
	west,
	up,
	down
};

class Exit
{
public:
	char name[30];
	char description[300];
	bool close = false;
	bool gate = false;
	Exit();
	Exit(const char* _name, const char* desc, Room* orig, Room* dest, const dir direc);
	~Exit();

	void Init(const char* _name, const char* desc, Room* orig, Room* dest, const dir direc);

	Room* origin; // Comparar con el punto en el que estas
	Room* destination;
	dir direction;
};


#endif
