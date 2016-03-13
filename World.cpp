#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "World.h"
#include "Room.h"
#include "Exit.h"

World::World()
{
	room = new Room[9];     // 9 rooms
	player = new Player[5]; // 1 player and 4 npc
}

World::~World()
{
	delete[] room;
}

void World::CreatePlayer()
{
}



void World::CreateWorld()
{
	/* Print room's names and their descriptions */
	int  i;
	char *roomname[] = 
	{ "Shore", "Depths", "Sea", "Palmtrees Island", "Palmtree", "Outside house", "House", "Shop", "Store"
	};

	for (i = 0; i < 9; i++)
	{
		strcpy_s((room + i)->name, roomname[i]);
	}

	char *description[] =
	{
		"You are in a shore, you can try to do snorquel, explore with your boat or walk\n",
		"It seems to be a pearl inside the oyster\n",
		"There are sharks!! I will try to come here later with something to kill them\n",
		"Wow there are a lot of palmtrees, it seems that there are something on that one\n",
		"There are a monkey! what should i do now?",
		"I can see a cool house, but the door is closed\n",
		"This house is so extravagant\nThere's a man\n",
		"Maybe i should buy something to kill the sharks and leave this islands\n",
		"Here is the inventory of the shop, I could catch something borrowed",
	};

	for (i = 0; i < 9; i++)
	{
		strcpy_s((room + i)->description, description[i]);
	}

	for (i = 0; i < 9; i++)
	{
		printf("%i) %s\n", i, (room + i)->name);
	}

	for (i = 0; i < 9; i++)
	{
		printf("%i) %s\n\n", i, (room + i)->description);
	}


	/*-----------------------------------------------------*/




}

