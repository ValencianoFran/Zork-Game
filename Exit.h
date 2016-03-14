#ifndef _EXIT__
#define _EXIT__
#include "Room.h"


	enum dir
	{
		north,
		south,
		east,
		west,
		up,
		down
	};

class Exit{
public:
	char name[30];
	char description[300];
	Room *origin; // Comparar con el punto en el que estas
	Room *destination;
	bool open = true;


	dir direction;

};


#endif