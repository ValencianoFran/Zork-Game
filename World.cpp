#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "World.h"
#include "Room.h"
#include "Exit.h"

World::World()
{
	room = new Room[9];     // 9 rooms
	player = new Player; // 1 player and 4 npc
	exits = new Exit[9];
}

World::~World()
{
	delete[] room;
	delete player;
}

void World::CreatePlayer()
{
}



void World::CreateWorld()
{
	/* Print room's names and their descriptions */
	/*int  i;
	const char *roomname[] =
	{ "Shore", "Depths", "Sea", "Palmtrees Island", "Palmtree", "Outside house", "House", "Shop", "Store"
	};

	for (i = 0; i < 9; i++)
	{
		strcpy_s((room + i)->name, roomname[i]);
	}

	const char *description[] =
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
	/*-----------------------------------------------------*/

	/* Access to rooms from the actual room */    // a == allowed  n == not allowed


	//Palmtrees Island
	strcpy((exits + 0)->name, "Palmtrees Island");
	strcpy((exits + 0)->name, "Wow there are a lot of palmtrees, it seems that there are something on that one\n");
	(exits + 0)->origin = (room + 0);
	(exits + 0)->destination = (room + 3);
	(exits + 0)->direction = north;

	//Palmtrees Island
	strcpy((exits + 0)->name, "Palmtrees Island");
	strcpy((exits + 0)->name, "Wow there are a lot of palmtrees, it seems that there are something on that one\n");
	(exits + 0)->origin = (room + 4);
	(exits + 0)->destination = (room + 3);
	(exits + 0)->direction = east;

	//Shore
	strcpy((exits + 1)->name, "Shore");
	strcpy((exits + 1)->name, "You are in a shore, you can try to do snorquel, explore with your boat or walk\n");
	(exits + 1)->origin = (room + 4);
	(exits + 1)->destination = (room + 3);
	(exits + 1)->direction = east;

	printf("%i\n", (exits + 0)->open);
	
	
	
	
	
	/*
	//Shore
	room[0]->north = "a";
	room[0]->south = "a";
	room[0]->east = "a";
	room[0]->weast = "a";
	room[0]->up = "n";
	room[0]->down = "a";

	//Depths
	room[1]->north = "n";
	room[1]->south = "n";
	room[1]->east = "n";
	room[1]->weast = "n";
	room[1]->up = "a";
	room[1]->down = "n";

	//Sea
	room[2]->north = "a";
	room[2]->south = "a";
	room[2]->east = "a";
	room[2]->weast = "a";
	room[2]->up = "n";
	room[2]->down = "a";

	//Palmtrees Island
	room[3]->north = "n";
	room[3]->south = "a";
	room[3]->east = "n";
	room[3]->weast = "n";
	room[3]->up = "a";
	room[3]->down = "n";

	//Palmtree
	room[4]->north = "n";
	room[4]->south = "n";
	room[4]->east = "n";
	room[4]->weast = "n";
	room[4]->down = "a";

	//Outside house
	room[5]->north = "n";
	room[5]->south = "n";
	room[5]->east = "a";
	room[5]->weast = "a";
	room[5]->up = "n";
	room[5]->down = "n";

	//House
	room[6]->north = "n";
	room[6]->south = "a";
	room[6]->east = "n";
	room[6]->weast = "n";
	room[6]->up = "n";
	room[6]->down = "n";

	//Shop
	room[7]->north = "a";
	room[7]->south = "a";
	room[7]->east = "n";
	room[7]->weast = "n";
	room[7]->up = "n";
	room[7]->down = "n";

	//Store
	room[8]->north = "a";
	room[8]->south = "n";
	room[8]->east = "n";
	room[8]->weast = "n";
	room[8]->up = "n";
	room[8]->down = "n";
	*/
}

