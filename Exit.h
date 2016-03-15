#ifndef _EXIT__
#define _EXIT__

#include "Room.h"

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

	bool Init(const char* _name, const char* desc, Room* orig, Room* dest, const dir direc);

	Room* origin; // Comparar con el punto en el que estas
	Room* destination;
	bool open = true;
	dir direction;
};


#endif