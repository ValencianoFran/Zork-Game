#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <ctime>
#include <cmath>
#include <windows.h>
#include "World.h"
#include "Room.h"
#include "Exit.h"

#define NUM_EXITS 16

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
	player->pos = room;
	printf("%You are in %s\n", player->pos->name);
}



void World::CreateWorld()
{
	/*  -- Room name and description --   */
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


	/*  -- EXITS --    */
	//Shore - Palmtrees Island
	 exits[0].Init("Palmtrees Island\n", "There are a lot of trees, seems interesting\n", room, (room+3), north);

	//Palmtrees Island - Shore
	 exits[1].Init("Shore\n", "There is where I begin this adventure\n", (room + 3), (room), south);

	 //Palmtrees Island - Monkey
	 exits[2].Init("Palmtree\n", "Maybe there are something in the top of that palmtree\n", (room + 3), (room + 4), east);

	 //Monkey - Palmtrees Island
	 exits[3].Init("Palmtrees Island\n", "There are a lot of trees, seems interesting\n", (room + 4), (room + 3), west);

	 //Shore - Sea
	 exits[4].Init("Palmtree\n", "Maybe there are something in the top of that palmtree\n", (room + 3), (room + 4), east);

	 //Sea - Shore
	 exits[5].Init("Shore\n", "\n", (room + 2), (room), east);

	 //Shore - Depths
	 exits[6].Init("Depths\n", "\n", (room), (room + 1), down);

	 //Depths - Shore
	 exits[7].Init("Shore\n", "\n", (room + 1), (room), up);

	 //Shore - Outside House
	 exits[8].Init("Outside House\n", "\n", (room), (room + 5), east);

	 //Outside House - Shore
	 exits[9].Init("Shore\n", "\n", (room + 5), (room), west);

	 //Shore - Shop
	 exits[10].Init("Shop\n", "\n", (room), (room + 7), south);

	 //Shop - Shore
	 exits[11].Init("Shore\n", "\n", (room + 7), (room), north);

	 //Shop - Store
	 exits[12].Init("Store\n", "\n", (room + 7), (room + 8), down);

	 //Store - Shop
	 exits[13].Init("Shop\n", "\n", (room + 8), (room + 7), up);

	 //Outside House - House
	 exits[14].Init("House\n", "\n", (room + 5), (room + 6), south);

	 //House - Outside House
	 exits[15].Init("Outside House\n", "\n", (room + 6), (room + 5), north);


	 CreatePlayer();
}




void World::PrintScreen()
{
}

void World::Mayus(char str[]){
	char word1[10] = "";
	char word2[10] = "";
	int i = 0, spaces = 0;
	char *context;

	while (str[i] != '\0') {
		str[i] = (tolower(str[i]));
		if (str[i] == ' ') spaces++;
		i++;
	}
	if (spaces == 0){
		strcpy_s(word1, str);
		strcpy_s(word2, "\0");
	}
	else{
		strcpy_s(word1, strtok_s(str, " ", &context));
		strcpy_s(word2, strtok_s(NULL, " ", &context));
	}
	Action(word1, word2);
}



int World::Direction(char op[]){
	if ((0 == strcmp(op, "north")) || (0 == strcmp(op, "n"))){
		return 0;
	}
	if ((0 == strcmp(op, "south")) || (0 == strcmp(op, "s"))){
		return 1;
	}
	if ((0 == strcmp(op, "east")) || (0 == strcmp(op, "e"))){
		return 2;
	}
	if ((0 == strcmp(op, "west")) || (0 == strcmp(op, "w"))){
		return 3;
	}
	return false;
}


void World::HandleInput(char op[]){
	int direc = -1, i = 0;
	bool done = false;
	direc = Direction(op);
	if (direc == false){
		printf("I don't understand that direction\n");
		return;
	}
	else{
		for (i = 0; i < NUM_EXITS; i++){

			if (0 == strcmp(exits[i].origin->name, player->pos->name))
			{
				if (exits[i].direction == direc){
					if (exits[i].close == true){
						printf("the door is closed\n");
						done = true;
						break;
					}
					else{
						player->pos = exits[i].destination;
						printf("You are in %s, %s \n", player->pos->name, player->pos->description);

						done = true;
						break;
					}
				}
			}
		}
		if (done == false){
			printf("you can not pass\n");
		}
	}
}


/*bool World::HandleInput(char input, int &position)
{
	bool ret = true;

	int i, j;
	//system("cls");
	fflush(stdin);





	switch (input)
	{
	case 'n':
		for (i = 0; i < 9; i++)
		{
			if ((exits + i)->origin == player->pos && (exits + i)->direction == north)
			{
				player->pos = (exits + i)->destination;
				for (j = 0; j < 9; j++)
				{
					if ((exits + i)->destination == (room + j))
					{
						position = j;
						printf("You are in %s\n", player->pos);
					}
				}
			}
		}
		break;

	case 's':
		for (i = 0; i < 9; i++)
		{
			if ((exits + i)->origin == player->pos && (exits + i)->direction == south)
			{
				player->pos = (exits + i)->destination;
				for (j = 0; j < 9; j++)
				{
					if ((exits + i)->destination == (room + j))
					{
						position = j;
						printf("You are in %s\n", player->pos);
					}
				}
			}
		}
		break;

	case 'w':
		for (i = 0; i < 9; i++)
		{
			if ((exits + i)->origin == player->pos && (exits + i)->direction == west)
			{
				player->pos = (exits + i)->destination;
				for (j = 0; j < 9; j++)
				{
					if ((exits + i)->destination == (room + j))
					{
						position = j;
						printf("You are in %s\n", player->pos);
					}
				}
			}
		}
		break;

	case 'e':
		for (i = 0; i < 9; i++)
		{
			if ((exits + i)->origin == player->pos && (exits + i)->direction == east)
			{
				player->pos = (exits + i)->destination;
				for (j = 0; j < 9; j++)
				{
					if ((exits + i)->destination == (room + j))
					{
						position = j;
						printf("You are in %s\n%s\n", player->pos->name, player->pos->description);
					}
				}
			}
		}
		break;
	case 'd':
		for (i = 0; i < 9; i++)
		{
			if ((exits + i)->origin == player->pos && (exits + i)->direction == down)
			{
				player->pos = (exits + i)->destination;
				for (j = 0; j < 9; j++)
				{
					if ((exits + i)->destination == (room + j))
					{
						position = j;
						printf("You are in %s\n", player->pos);
					}
				}
			}
		}
		break;

	case 'u':
		for (i = 0; i < 9; i++)
		{
			if ((exits + i)->origin == player->pos && (exits + i)->direction == up)
			{
				player->pos = (exits + i)->destination;
				for (j = 0; j < 9; j++)
				{
					if ((exits + i)->destination == (room + j))
					{
						position = j;
						printf("You are in %s\n", player->pos);
					}
				}
			}
		}

		break;
	default:
	{
			   printf("You can't go that way\n");
			   break;
	}


		return ret;
	}


}






*/

/*
//Palmtrees Island
strcpy_s((exits + 0)->name, "Palmtrees Island");
strcpy_s((exits + 0)->name, "Wow there are a lot of palmtrees, it seems that there are something on that one\n");
(exits + 0)->origin = (room + 0);
(exits + 0)->destination = (room + 3);
(exits + 0)->direction = north;
*/

/*void World::Action(char do1[], char do2[]){
	if (0 == strcmp(do1, "north") || 0 == strcmp(ope, "n")){
		Go(do1);
		return;
	}
	if (0 == strcmp(do1, "south") || 0 == strcmp(do1, "s")){
		Go(do1);
		return;
	}
	if (0 == strcmp(do1, "east") || 0 == strcmp(do1, "e")){
		Go(do1);
		return;
	}
	if (0 == strcmp(do1, "west") || 0 == strcmp(do1, "w")){
		Go(do1);
		return;
	}
	else if (0 == strcmp(do1, "go") || 0 == strcmp(do1, "g")){
		Go(do2);
		return;
	}
	else if (0 == strcmp(do1, "look") || 0 == strcmp(do1, "l")){
		Look(do2);
		return;
	}
	else if (0 == strcmp(do1, "open") || 0 == strcmp(do1, "o")){
		Open(do2);
		return;
	}
	else if (0 == strcmp(do1, "close") || 0 == strcmp(do1, "c")){
		Open(do2);
		return;
	}
	else if (0 == strcmp(do1, "help") || 0 == strcmp(do1, "h")){
		Help(do2);
		return;
	}
	else if (0 == strcmp(do1, "quit") || 0 == strcmp(do1, "q")){
		return;
	}
	else{
		printf("wrong operation\n");
	}
	}*/