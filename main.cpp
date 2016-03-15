#include <stdio.h>
#include <stdlib.h>
#include "Room.h"
#include "World.h"
#include "Exit.h"
#include "Player.h"


int main() {
	World world; 
	world.CreateWorld();

	bool exit = false;
	char direction;

	while (!exit)
	{
		world.PrintScreen();
		scanf_s("%c", &direction);
<<<<<<< HEAD
		exit = world.HandleInput(direction);
=======
		exit = world.HandleInput(&direction);
>>>>>>> origin/master
	}

	system("pause");
	return 0;
}

