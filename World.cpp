#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "World.h"
#include "Room.h"
#include "Exit.h"

World::World()
{
	room = new Room[9];
	player = new Player[5];
}

World::~World()
{
	delete[] room;
}

void World::CreateWorld()
{
	/*-----------------------------------------------------*/
	strcpy_s(room[0].name, "Shore");
	strcpy_s(room[0].description, "Test");

	strcpy(room[1].name, );
	strcpy(room[1].description, );

	strcpy(room[2].name, );
	strcpy(room[2].description, );

	strcpy(room[3].name, );
	strcpy(room[3].description, );
	
	strcpy(room[4].name, );
	strcpy(room[4].description, );

	strcpy(room[5].name, );
	strcpy(room[5].description, );

	strcpy(room[6].name, );
	strcpy(room[6].description, );

	strcpy(room[7].name, );
	strcpy(room[7].description, );

	strcpy(room[8].name, );
	strcpy(room[8].description, );
	/*-----------------------------------------------------*/

}