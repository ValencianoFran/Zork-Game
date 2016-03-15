#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <ctime>
#include <cmath>
#include <windows.h>
#include "world.h"
#include "room.h"
#include "exit.h"

World::World()
{
	room = new Room[9];     // 9 rooms
	player = new Player; // 1 player and 4 npc
}

World::~World()
{
	delete[] room;
	delete player;
}

void World::CreatePlayer()
{
	player->pos = room;
	printf("%You are in %s\n", player->pos->name);
}



void World::CreateWorld()
{
	/*  -- Room name and description --   */
	const char *roomname[] =
	{ "Shore", "Depths", "Sea", "Palmtrees Island", "Palmtree", "Outside house", "House", "Shop", "Store" };

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

	/*Create rooms*/
	room[0].Init("Shore", "You are in a shore, you can try to do snorquel, explore with your boat or walk\n");
	room[1].Init("Depths", "It seems to be a pearl inside the oyster\n");
	room[2].Init("Sea", "There are sharks!! I will try to come here later with something to kill them\n");
	room[3].Init("Palmtrees Island", "Wow there are a lot of palmtrees, it seems that there are something on that one\n");
	room[4].Init("Palmtree", "There are a monkey! what should i do now?");
	room[5].Init("Outside house", "I can see a cool house, but the door is closed\n");
	room[6].Init("House", "This house is so extravagant\nThere's a man\n");
	room[7].Init("Shop", "Maybe i should buy something to kill the sharks and leave this islands\n");
	room[8].Init("Store", "Here is the inventory of the shop, I could catch something borrowed");
}


