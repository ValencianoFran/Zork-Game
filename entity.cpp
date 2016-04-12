#include "room.h"
#include "player.h"
#include "exit.h"
#include "entity.h"
#include <stdio.h>

#define NUM_EXITS 16

Entity::Entity()
{
	room = new Room[9];     // 9 rooms
	exits = new Exit[NUM_EXITS];
}

Entity::~Entity()
{
	delete[] room;
	delete[] exits;
}

void Entity::CreateDescriptions() const
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

}