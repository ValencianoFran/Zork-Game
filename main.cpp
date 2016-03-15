#include <stdio.h>
#include <stdlib.h>
#include "Room.h"
#include "World.h"
#include "Exit.h"
#include "Player.h"
#define NUM_EXITS 16


int main() {
	World world; 
	world.CreateWorld();

	bool exit = false;
	char direction[30];
	int pos = 0;

	printf("Introduce where you want to go <'n', 's', 'w', 'e', 'u', 'd'>\n\n");

	while (exit!=1)
	{
		world.PrintScreen();
		gets_s(direction, 20);
		printf("%s", direction);
		world.Mayus(direction);
		exit = world.HandleInput(direction);
	}

	system("pause");
	return 0;
}

