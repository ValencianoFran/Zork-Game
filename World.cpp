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
	exits = new Exit[16];
}

World::~World()
{
	delete[] room;
	delete player;
	delete[] exits;
}

void World::CreatePlayer()
{

}



void World::CreateWorld()
{
	const char *roomname[] =
	{ "Shore", "Depths", "Sea", "Palmtrees Island", "Palmtree", "Outside house", "House", "Shop", "Store"};

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

	room[0].Init("Shore", "You are in a shore, you can try to do snorquel, explore with your boat or walk\n");
	room[1].Init("Depths", "It seems to be a pearl inside the oyster\n");
	room[2].Init("Sea", "There are sharks!! I will try to come here later with something to kill them\n");
	room[3].Init("Palmtrees Island", "Wow there are a lot of palmtrees, it seems that there are something on that one\n");
	room[4].Init("Palmtree", "There are a monkey! what should i do now?");
	room[5].Init("Outside house", "I can see a cool house, but the door is closed\n");
	room[6].Init("House", "This house is so extravagant\nThere's a man\n");
	room[7].Init("Shop", "Maybe i should buy something to kill the sharks and leave this islands\n");
	room[8].Init("Store", "Here is the inventory of the shop, I could catch something borrowed");



	//exits[0].Init("Shore", "You are in a shore, you can try to do snorquel, explore with your boat or walk\n", , , , );





	CreatePlayer();
}




void World::PrintScreen()
{
	printf_s("%c\n", player->pos->name);
	printf_s("%c\n", player->pos->description);
}



/*bool World::HandleInput(char* input)
{
	bool ret = true;

	system("clr");


	switch (input)
	{
	case "go north":

	default: 
	}



	return ret;
}
*/










/*
//Palmtrees Island
strcpy_s((exits + 0)->name, "Palmtrees Island");
strcpy_s((exits + 0)->name, "Wow there are a lot of palmtrees, it seems that there are something on that one\n");
(exits + 0)->origin = (room + 0);
(exits + 0)->destination = (room + 3);
(exits + 0)->direction = north;

//Palmtrees Island
strcpy_s((exits + 0)->name, "Palmtrees Island");
strcpy_s((exits + 0)->name, "Wow there are a lot of palmtrees, it seems that there are something on that one\n");
(exits + 0)->origin = (room + 4);
(exits + 0)->destination = (room + 3);
(exits + 0)->direction = east;

//Shore
strcpy_s((exits + 1)->name, "Shore");
strcpy_s((exits + 1)->name, "You are in a shore, you can try to do snorquel, explore with your boat or walk\n");
(exits + 1)->origin = (room + 3);
(exits + 1)->destination = (room + 0);
(exits + 1)->direction = east;

printf("%i\n", (exits + 0)->open);

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



