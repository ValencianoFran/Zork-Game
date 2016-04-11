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

#define NUM_EXITS 16
#define INVALID -1

World::World()
{
	room = new Room[9];     // 9 rooms
	player = new Player; // 1 player
	exits = new Exit[NUM_EXITS];
}

World::~World()
{
	delete[] room;
	delete player;
	delete[] exits;
}

void World::CreatePlayer() const
{
	player->pos = room;
}



void World::CreateWorld() const
{
	/*  -- Room name and description --   */

	/*Create rooms*/
	room[0].Init("Shore", "You are in a shore, you can try to do snorquel going down, or explore others directions\n");
	room[1].Init("Depths", "It seems to be a pearl inside the oyster\n");
	room[2].Init("Sea", "There are sharks!! I will try to come here later with something to kill them\n");
	room[3].Init("Palmtrees Island", "Wow there are a lot of palmtrees, it seems that there are something on that one on the east\n");
	room[4].Init("Palmtree", "There are a monkey! what should i do now?");
	room[5].Init("Outside house", "I can see a cool house in south, but the door is closed\n");
	room[6].Init("House", "This house is so extravagant\nThere's a man\n");
	room[7].Init("Shop", "Maybe i should buy something to kill the sharks and leave this islands.\nThere are something down stairs\n");
	room[8].Init("Store", "Here is the inventory of the shop, I could catch something borrowed");

	/*  -- EXITS --    */
	//Shore - Palmtrees Island
	exits[0].Init("Palmtrees Island\n", "There are a lot of trees, seems interesting\n", room, (room + 3), north);

	//Palmtrees Island - Shore
	exits[1].Init("Shore\n", "There is where I begin this adventure, i should try to do snorquel\n", (room + 3), (room), south);

	//Palmtrees Island - Monkey
	exits[2].Init("Palmtree\n", "Maybe there are something in the top of that palmtree\n", (room + 3), (room + 4), east);

	//Monkey - Palmtrees Island
	exits[3].Init("Palmtrees Island\n", "There are a lot of trees, seems interesting\n", (room + 4), (room + 3), west);

	//Shore - Sea
	exits[4].Init("Sea\n", "There are a sea, seems dangerous\n", (room), (room + 2), west);

	//Sea - Shore
	exits[5].Init("Shore\n", "There is where I begin this adventure, i should try to do snorquel\n", (room + 2), (room), east);

	//Shore - Depths
	exits[6].Init("Depths\n", "It seems deep\n", (room), (room + 1), down);

	//Depths - Shore
	exits[7].Init("Shore\n", "There is where I begin this adventure, i should try to do snorquel\n", (room + 1), (room), up);

	//Shore - Outside House
	exits[8].Init("Outside House\n", "There are a pretty garden, i should take a look\n", (room), (room + 5), east);

	//Outside House - Shore
	exits[9].Init("Shore\n", "There is where I begin this adventure, i should try to do snorquel\n", (room + 5), (room), west);

	//Shore - Shop
	exits[10].Init("Shop\n", "There must be interesting things to buy\n", (room), (room + 7), south);

	//Shop - Shore
	exits[11].Init("Shore\n", "There is where I begin this adventure, i should try to do snorquel\n", (room + 7), (room), north);

	//Shop - Store
	exits[12].Init("Store\n", "What would be down stairs?\n", (room + 7), (room + 8), down);

	//Store - Shop
	exits[13].Init("Shop\n", "There must be interesting things to buy\n", (room + 8), (room + 7), up);

	//Outside House - House
	exits[14].Init("House\n", "There is a pretty garden!\n", (room + 5), (room + 6), south);
	exits[14].gate = true;
	exits[14].close = true;

	//House - Outside House
	exits[15].Init("Outside House\n", "\n", (room + 6), (room + 5), north);

	CreatePlayer();
}


void World::Mayus(char str[])//Transform capital letters to lowercase and iniciate the loop with Action
{
	char word1[20] = "";
	char word2[20] = "";
	int i = 0, spaces = 0;
	char *context; // Necessary to do strtok

	while (str[i] != '\0') 
	{
		str[i] = (tolower(str[i]));
		if (str[i] == ' ') spaces++;
		i++;
	}
	if (spaces == 0)
	{   //Check if there are spaces to write a second word
		strcpy_s(word1, str);
		strcpy_s(word2, "\0");
	}
	else
	{
		strcpy_s(word1, strtok_s(str, " ", &context));
		strcpy_s(word2, strtok_s(NULL, " ", &context));
	}
	Action(word1, word2); // Future method witch will send the information to go, look, open or close
}

int World::Direction(char op[]) //Check the direction is valid
{
	if ((strcmp(op, "north")) == 0 || (strcmp(op, "n") == 0))
	{
		return 0;
	}
	if ((strcmp(op, "south") == 0) || (strcmp(op, "s") == 0))
	{
		return 1;
	}
	if ((strcmp(op, "east") == 0) || (strcmp(op, "e") == 0))
	{
		return 2;
	}
	if ((strcmp(op, "west") == 0) || (strcmp(op, "w") == 0))
	{
		return 3;
	}
	if ((strcmp(op, "up") == 0) || (strcmp(op, "u") == 0))
	{
		return 4;
	}
	if ((strcmp(op, "down") == 0) || (strcmp(op, "d") == 0))
	{
		return 5;
	}
	return INVALID;
}


void World::Go(char op[]) //Move player
{
	int direc = INVALID;
	int  i = 0;
	bool finish = false;   //Check if go action is completed
	direc = Direction(op); //Check the direction is valid

	if (direc == INVALID)
	{
		printf("Invalid direction\n\n");
		return;
	}

	else
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i].origin->name == player->pos->name)
			{
				if (exits[i].direction == direc)
				{
					if (exits[i].close == true)
					{
						printf("The door is closed\n");
						finish = true;
						break;
					}
					else{
						player->pos = exits[i].destination;
						printf("\nYou are in %s\n\n%s \n", player->pos->name, player->pos->description);

						finish = true;
						break;
					}
				}
			}
		}
		if (finish == false)
		{
			printf("\nThere is nothing there, you can't go this way\n");
		}
	}
}

void World::Look(const char op[]) //Look the exit
{
	int direc = INVALID;
	int  i = 0;
	bool finish = false;   //Check if go action is completed
	direc = Direction(op); //Look if the direction is valid

	if (direc == INVALID)
	{
		printf("Invalid direction\n");
		return;
	}

	else
	{
		for (i = 0; i < NUM_EXITS; i++)
		{

			if (exits[i].origin->name == player->pos->name) //Compares the player position with the origin room of the exit
			{
				if (exits[i].direction == direc)
				{
					printf("\nYou see %s\n%s ", exits[i].name, exits[i].description);
					finish = true;
					break;
				}
			}
		}
		if (finish == false)
		{
			printf("\nThere are nothing here\n");
		}
	}
}

void World::Open(char op[]) //Open doors
{
	int direc = INVALID;
	int i = 0;
	bool done = false;  //Check if go action is completed
	direc = Direction(op);  //Check if direction is valid

	if (direc == INVALID){
		printf("Invalid direction\n");
		return;
	}
	else
	{
		for (i = 0; i < NUM_EXITS; i++)
		{

			if (exits[i].origin->name == player->pos->name) //Compares the player position with the origin room of the exit
			{
				if (exits[i].direction == direc)
				{
					if (exits[i].gate == true)
					{
						if (exits[i].close == true) // If the door is closed, open it
							exits[i].close = false;
						printf("\nThe door is open\n");
						done = true;
						break;
					}

					else
					{
						break;
					}
				}
			}
		}
		if (done == false)
		{
			printf("\nThere is nothing to open or It's already open\n");
		}
	}
}

void World::Close(char op[]) //Close doors, same function of Open, but it closes the door
{
	int direc = INVALID;
	int i = 0;
	bool finish = false;
	direc = Direction(op);

	if (direc == INVALID)
	{
		printf("Invalid direction\n");
		return;
	}
	else
	{
		for (i = 0; i < NUM_EXITS; i++)
		{

			if (exits[i].origin->name == player->pos->name)
			{
				if (exits[i].direction == direc)
				{
					if (exits[i].gate == true)
					{
						if (exits[i].close == false)
							exits[i].close = true;
						printf("The door is closed\n");
						finish = true;
						break;
					}
					else{
						break;
					}
				}
			}
		}

		if (finish == false){
			printf("There is no doors to close or It's already closed\n");
		}
	}
}
 
void World::Tutorial() const //Controls of the game
{
	printf("CONTROLS:\n\tYou can use these commands:\n\tgo [direction], look [direction], open/close [direction], help and quit\n\twith these directions:\n\t<north, south, east, west, up, down>\n\t<n, s, e, w, u, d>\n\tDefault action is 'go' if you only introduce the direction.\n");
}


void World::Action(char do1[], char do2[]) //Do the action that the player input
{

	/*With 1 word input*/
	/*Go actions (every 'if' does the same function)*/
	if (strcmp(do1, "north") == 0 || strcmp(do1, "n") == 0)
	{
		Go(do1);
		return;
	}
	if (strcmp(do1, "south") == 0 || strcmp(do1, "s") == 0)
	{
		Go(do1);
		return;
	}
	if (strcmp(do1, "east") == 0 || strcmp(do1, "e") == 0)
	{
		Go(do1);
		return;
	}
	if (strcmp(do1, "west") == 0 || strcmp(do1, "w") == 0)
	{
		Go(do1);
		return;
	}
	if (strcmp(do1, "up") == 0 || strcmp(do1, "u") == 0)
	{
		Go(do1);
		return;
	}
	if (strcmp(do1, "down") == 0 || strcmp(do1, "d") == 0)
	{
		Go(do1);
		return;
	}
	

	/*With 2 words input*/
	else if (strcmp(do1, "go") == 0 || strcmp(do1, "g") == 0)
	{
		Go(do2);
		return;
	}
	else if (strcmp(do1, "look") == 0 || strcmp(do1, "l") == 0)
	{
		Look(do2);
		return;
	}
	else if (strcmp(do1, "open") == 0 || strcmp(do1, "o") == 0)
	{
		Open(do2);
		return;
	}
	else if (strcmp(do1, "close") == 0 || strcmp(do1, "c") == 0)
	{
		Close(do2);
		return;
	}

	/*Quit and help*/
	else if (strcmp(do1, "quit") == 0)
	{
		return;
	}
	else if (strcmp(do1, "help") == 0 || strcmp(do1, "h") == 0)
	{
		Tutorial();
		return;
	}
	
	/*If the user introduces invalid action*/
	else{
		printf("I don't understand\n");
	}

}
