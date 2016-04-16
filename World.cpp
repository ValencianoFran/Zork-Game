#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <cmath>
#include <windows.h>
#include"world.h"
#include<stdio.h>
#include<string.h>


#define NUM_EXITS 16
#define INVALID -1

World::World()
{
	player = new Player;
}

World::~World()
{
}

void World::CreatePlayer() const
{
	player->position = room[0];
}



void World::CreateWorld()
{
	
	/*  -- Room name and description --   */

	// ROOM 0
	room.push_back(new Room("Shore", "You are in a shore, you can try to do snorquel going down, or explore others directions\n"));
	
	// ROOM 1
	room.push_back(new Room("Depths", "It seems to be a pearl inside the oyster\n"));

	// ROOM 2
	room.push_back(new Room("Sea", "There are sharks!! I will try to come here later with something to kill them\n"));

	// ROOM 3
	room.push_back(new Room("Palmtrees Island", "Wow there are a lot of palmtrees, it seems that there are something on that one on the east\n"));

	// ROOM 4
	room.push_back(new Room("Palmtree", "There are a monkey! what should i do now?"));

	// ROOM 5
	room.push_back(new Room("Outside house", "I can see a cool house in south, but the door is closed\n"));

	// ROOM 6
	room.push_back(new Room("House", "This house is so extravagant\nThere's a man\n"));

	// ROOM 7
	room.push_back(new Room("Shop", "Maybe i should buy something to kill the sharks and leave this islands.\nThere are something down stairs\n"));

	// ROOM 8
	room.push_back(new Room("Store", "Here is the inventory of the shop, I could catch something borrowed"));


	/*  -- EXITS --    */

	//EXIT 0
	exit.push_back(new Exit("Palmtrees Island\n", "There are a lot of trees, seems interesting\n", room[0], room[3], north, false));

	//EXIT 1
	exit.push_back(new Exit("Shore\n", "There is where I begin this adventure, i should try to do snorquel\n", room[3], room[0], south, false));

	//EXIT 2
	exit.push_back(new Exit("Palmtree\n", "Maybe there are something in the top of that palmtree\n", room[3], room[4], east, false));

	//EXIT 3
	exit.push_back(new Exit("Palmtrees Island\n", "There are a lot of trees, seems interesting\n", room [4], room[3], west, false));

	//EXIT 4
	exit.push_back(new Exit("Sea\n", "There are a sea, seems dangerous\n", room[0], room[2], west, false));

	//EXIT 5
	exit.push_back(new Exit("Shore\n", "There is where I begin this adventure, i should try to do snorquel\n", room[2], room[0], east, false));

	//EXIT 6
	exit.push_back(new Exit("Depths\n", "It seems deep\n", room[0], room[1], down, false));

	//EXIT 7
	exit.push_back(new Exit("Shore\n", "There is where I begin this adventure, i should try to do snorquel\n", room[1], room[0], up, false));

	//EXIT 8
	exit.push_back(new Exit("Outside House\n", "There are a pretty garden, i should take a look\n", room[0], room[5], east, false));

	//EXIT 9
	exit.push_back(new Exit("Shore\n", "There is where I begin this adventure, i should try to do snorquel\n", room[5], room[0], west, false));

	//EXIT 10
	exit.push_back(new Exit("Shop\n", "There must be interesting things to buy\n", room[0], room[7], south, false));

	//EXIT 11
	exit.push_back(new Exit("Shore\n", "There is where I begin this adventure, i should try to do snorquel\n", room[7], room[0], north, false));

	//EXIT 12
	exit.push_back(new Exit("Store\n", "What would be down stairs?\n", room[7], room[8], down, false));

	//EXIT 13
	exit.push_back(new Exit("Shop\n", "There must be interesting things to buy\n", room[8], room[7], up, false));

	//EXIT 14
	exit.push_back(new Exit("House\n", "There is a pretty garden!\n", room[5], room[6], south, true));

	//EXIT 15
	exit.push_back(new Exit("Outside House\n", "\n", room[6], room[5], north, false));


	CreatePlayer();
}


void World::Mayus(String& str) const//Transform capital letters to lowercase and iniciate the loop with Action
{
	String word1("");
	String word2("");
	String word3("");
	String word4("");
	int i = 0, spaces = 0;
	char *context; // Necessary to do strtok

	str.tolower_method();
	spaces = str.spaces();
	
	if (spaces == 0)
	{   //Check if there are spaces to write a second word
		word1 = str;
		word2 = "\0";
		word3 = "\0";
		word4 = "\0";
	}
	if (spaces == 1)
	{
		strcpy_s(word1, strtok_s(str, " ", &context));
		strcpy_s(word2, strtok_s(NULL, " ", &context));
		word3 = "\0";
		word4 = "\0";
	}
	
	if (spaces == 3)
	{
		strcpy_s(word1, strtok_s(str, " ", &context));
		strcpy_s(word2, strtok_s(NULL, " ", &context));
		strcpy_s(word3, strtok_s(NULL, " ", &context));
		strcpy_s(word4, strtok_s(NULL, " ", &context));
	}
	
	Action(word1, word2, word3, word4); // Future method witch will send the information to go, look, open or close
}

int World::Direction(const String& op) //Check the direction is valid
{

	if (op == "north" || op == "n")
	{
		return 0;
	}
	if (op == "south" || op == "s")
	{
		return 1;
	}
	if (op == "east" || op == "e")
	{
		return 2;
	}
	if (op == "west" || op == "w")
	{
		return 3;
	}
	if (op == "up" || op == "u")
	{
		return 4;
	}
	if (op == "down" || op == "d")
	{
		return 5;
	}
	return INVALID;
}


void World::Go(const String& op) //Move player
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
			if (exit[i]->origin->name == player->position->name)
			{
				if (exit[i]->direction == direc)
				{
					if (exit[i]->close == true)
					{
						printf("The door is closed\n");
						finish = true;
						break;
					}
					else{
						player->position = exit[i]->destination;
						printf("\nYou are in %s\n\n%s \n", player->position->name.c_str(), player->position->description.c_str());

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

void World::Look(const String& op) //Look the exit
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

			if (exit[i]->origin->name == player->position->name) //Compares the player position with the origin room of the exit
			{
				if (exit[i]->direction == direc)
				{
					printf("\nYou see %s\n%s ", exit[i]->name.c_str(), exit[i]->description.c_str());
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

void World::Open(const String& op) //Open doors
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

			if (exit[i]->origin->name == player->position->name) //Compares the player position with the origin room of the exit
			{
				if (exit[i]->direction == direc)
				{
					if (exit[i]->close == true)
					{		// If the door is closed, open it
						exit[i]->close = false;
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

void World::Close(const String& op) //Close doors, same function of Open, but it closes the door
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

			if (exit[i]->origin->name == player->position->name)
			{
				if (exit[i]->direction == direc)
				{
					if (exit[i]->close == true)
					{
						exit[i]->close = false;
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


void World::Action(const String& do1, const String& do2, const String& do3, const String& do4) //Do the action that the player input
{
	/*With 1 word input*/
	/*Go actions (every 'if' does the same function)*/
	if (do1 == "north" || do1 == "n")
	{
		Go(do1);
		return;
	}
	if (do1 == "south" || do1 == "s")
	{
		Go(do1);
		return;
	}
	if (do1 == "east" || do1 == "e")
	{
		Go(do1);
		return;
	}
	if (do1 == "west" || do1 == "w")
	{
		Go(do1);
		return;
	}
	if (do1 == "up" || do1 == "u")
	{
		Go(do1);
		return;
	}
	if (do1 == "down" || do1 == "d")
	{
		Go(do1);
		return;
	}
	

	/*With 2 words input*/
	else if (do1 == "go" || do1 == "g")
	{
		Go(do2);
		return;
	}

	else if (do1 == "look" || do1 == "l")
	{
		Look(do2);
		return;
	}
	else if (do1 == "open" || do1 == "o")
	{
		Open(do2);
		return;
	}
	else if (do1 == "close" || do1 == "c")
	{
		Close(do2);
		return;
	}

	/*Quit and help*/
	else if (do1 == "quit")
	{
		return;
	}
	else if (do1 == "help" || do1 == "h")
	{
		Tutorial();
		return;
	}
	
	else if (do1 == "pick")
	{
		printf("I will pick a item\n");
		//Pick(do2);
		return;
	}

	else if (do1 == "drop")
	{
		printf("I will drop a item\n");
		//Drop(do2);
		return;
	}

	else if (do1 == "inventory" || do1 == "inv" || do1 == "i")
	{
		printf("I will show the inventory\n");
		//Inventory(do2);
		return;
	}

	else if (do1 == "equip")
	{
		printf("I will equip a item\n");
		//Equip(do2);
		return;
	}

	else if (do1 == "unequip")
	{
		printf("I will unequip a item\n");
		//Drop(do2);
		return;
	}

	else if (do1 == "put" && do3 == "into")
	{
		printf("I will put a item into another item\n");
		//Put(do2);
		return;
	}

	

	/*If the user introduces invalid action*/
	else{
		printf("I don't understand\n");
	}

}
