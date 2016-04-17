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


	//ITEMS

	item.push_back(new Items("Guitar", "You can use this object to attract the monkey\n", room[6], 10, 0, Hand));
	item.push_back(new Items("Pearl", "It seems very expensive\n", room[1], 10, 0, Cant_Equip));
	item.push_back(new Items("Harpoon", "It seems powerful and dangerous\n", room[7], 10, 20, Hand));
	item.push_back(new Items("Oyster", "Maybe constains something with value inside\n", room[1], 10, 0, Cant_Equip));
	item.push_back(new Items("Goggles", "This should allow me to snorquel\n", room[6], 10, 0, Head));
	item.push_back(new Items("Knife", "It cuts, should be careful\n", room[5], 10, 20, Hand));
	item.push_back(new Items("Rotten banana", "It doesn't smell good\n", room[8], 10, 0, Hand));
	item.push_back(new Items("Chest", "There are something inside it\n", room[8], 10, 0, Cant_Equip));
	item.push_back(new Items("Box", "I should take that and open It\n", room[6], 10, 0, Cant_Equip));
	item.push_back(new Items("Boat", "It allows you to navegate in the sea\n", room[0], 10, 0, Drive));
	item[9]->equipped = true;

	CreatePlayer();
}


void World::Mayus(String& str)//Transform capital letters to lowercase and iniciate the loop with Action
{
	str.tolower_method();//transforms in to lowercase
	Vector <String> word = str.SplitString(); //divide the principal string in to differents strings
	 
	//str.Token(str, word); 

	Action(word); // Future method witch will send the information to go, look, open or close
}

int World::Direction(const String& op) //Check the direction is valid
{

	if (op.c_str() == "north" || op.c_str() == "n")
	{
		return 0;
	}
	if (op.c_str() == "south" || op.c_str() == "s")
	{
		return 1;
	}
	if (op.c_str() == "east" || op.c_str() == "e")
	{
		return 2;
	}
	if (op.c_str() == "west" || op.c_str() == "w")
	{
		return 3;
	}
	if (op.c_str() == "up" || op.c_str() == "u")
	{
		return 4;
	}
	if (op.c_str() == "down" || op.c_str() == "d")
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
					if (exit[i]->destination == room[1] && item[4]->equipped == false)
					{
						printf("You need have googles equiped to do snorquel\n");
						finish = true;
						break;
					}
					if (exit[i]->destination == room[0] && item[9]->equipped == false)
					{
						printf("You need have googles equiped to do snorquel\n");
						finish = true;
						break;
					}
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
	int _item = INVALID;
	int  i = 0, j= 0;
	bool finish = false;   //Check if go action is completed
	_item = Item_verification(op); //Look if the item name is valid
	direc = Direction(op); //Look if the direction name is valid

	if (direc == INVALID && _item == INVALID)
	{
		printf("Invalid command\n");
		return;
	}

	if (direc != INVALID)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{

			if (exit[i]->origin->name == player->position->name) //Compares the player position with the origin room of the exit
			{
				if (exit[i]->direction == direc)
				{
					printf("\nYou see %s\n%s ", exit[i]->name.c_str(), exit[i]->description.c_str());
					printf("You can see this items:\n");
					for (j = 0; j < 8; j++)
					{
						if (item[j]->place == player->position && item[i]->picked == false)
						{
							item[j]->Look();
						}
					}
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

	if (_item != INVALID)
	{
		for (int j = 0; j < 8; j++)
		{
			if (item[j]->name.c_str() == op.c_str())
			{
				item[j]->Look();
				return;
			}
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


void World::Action(Vector<String> &act) //Do the action that the player input
{
	/*With 1 word input*/
	/*Go actions (every 'if' does the same function)*/
	if (act[0].c_str() == "north" || act[0].c_str() == "n")
	{
		Go(act[0]);
		return;
	}
	if (act[0].c_str() == "south" || act[0].c_str() == "s")
	{
		Go(act[0]);
		return;
	}

	/*if (do1 == "east" || do1 == "e")
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
	

	//With 2 words input
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

	//Quit and help
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

	

	//If the user introduces invalid action
	else{
		printf("I don't understand\n");
	}
	*/
}

void World::Inventory(const String&)
{
	int done = 0;
	printf("You have this items in the inventory:\n");
	for (int j = 0; j < 8; j++)
	{
		if (item[j]->picked == true && item[j]->equipped == false)
		{
			printf("%s\n", item[j]->name.c_str());
			done = 1;
		}
	}
	if (done = 0)
	{
		printf("You don't have items yet\n");
	}
}


int World::Item_verification(const String& item_)
{
	for (int j = 0; j < 8; j++)
	{
		if (item[j]->name.c_str() == item_.c_str())
		{
			return 1;
		}
	}
	return INVALID;
}

void World::Pick(const String& _item)
{
	int item_comprovant = INVALID;
	if (player->num_items >= player->bag_capacity)
	{
		printf("The bag is full\n");
		return;
	}

	item_comprovant = Item_verification(_item);
	if (item_comprovant == INVALID)
	{
		printf("Thats a invalid item\n");
		return;
	}

	for (int j = 0; j < 8; j++)
	{
		if (item[j]->name.c_str() == _item.c_str())
		{
			if (item[j]->picked == false)
			{
				item[j]->picked = true;
				printf("You picked %s\n", item[j]->name.c_str());
				return;
			}
		}
	}

	printf("You have already picked that item\n");
	return;
}

void World::Drop(const String& _item)
{
	int item_comprovant = INVALID;
	item_comprovant = Item_verification(_item);
	if (item_comprovant == INVALID)
	{
		printf("Thats a invalid item\n");
		return;
	}

	for (int j = 0; j < 8; j++)
	{
		if (item[j]->name.c_str() == _item.c_str())
		{
			if (item[j]->picked == true)
			{
				item[j]->picked = false;
				item[j]->place = player->position;
				printf("You dropped %s\n", item[j]->name.c_str());
				return;
			}
		}
	}

	printf("You dont have that item in your inventary that item\n");
	return;

}

void World::Equip(const String& _item)
{
	int item_comprovant = INVALID;
	item_comprovant = Item_verification(_item);
	if (item_comprovant == INVALID)
	{
		printf("Thats a invalid item\n");
		return;
	}

	for (int j = 0; j < 8; j++)
	{
		if (item[j]->name.c_str() == _item.c_str())
		{
			if (item[j]->equipped == false)
			{
				if (item[j]->slot == 0 && player->_head == false)
				{
					item[j]->equipped = true;
					player->_head = true;
					printf("You equiped %s\n", item[j]->name.c_str());
					return;
				}
				if (item[j]->slot == 1 && player->_hand == false)
				{
					item[j]->equipped = true;
					player->_hand = true;
					printf("You equiped %s\n", item[j]->name.c_str());
					return;
				}

				if (item[j]->slot == 3 && player->_drive == false)
				{
					item[j]->equipped = true;
					player->_drive = true;
					printf("You equiped %s\n", item[j]->name.c_str());
					return;
				}
				
			}

			else
			{
				if (item[j]->slot == 0)
				{
					printf("Actually your head is equiped\n");
				}
				if (item[j]->slot == 1)
				{
					printf("Actually your hand is equiped\n");
				}
				if (item[j]->slot == 3)
				{
					printf("Actually you have transport\n");
				}
				else
				{
					printf("You can't equip that item\n");
				}
				return;
			}
		}
	}
}

void World::Unequip(const String& _item)
{
	int item_comprovant = INVALID;
	item_comprovant = Item_verification(_item);
	if (item_comprovant == INVALID)
	{
		printf("Thats a invalid item\n");
		return;
	}

	for (int j = 0; j < 8; j++)
	{
		if (item[j]->name.c_str() == _item.c_str())
		{
			if (item[j]->equipped == true)
			{
				item[j]->equipped = false;
				printf("You unequiped %s\n", item[j]->name.c_str());
				return;
			}
			else
			{
				printf("You don't have equiped that item\n");
				return;
			}
		}
	}
}

void Put(const String& _put, const String& _into)
{

}

void Get(const String& _get, const String& _from)
{

}