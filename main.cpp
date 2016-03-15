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
	int pos = 0;

	while (exit!=1)
	{
		
		printf("Introduce where you want to go <'n', 's', 'w', 'e', 'u', 'd'>\n\n");
		world.PrintScreen();
		scanf_s("%c", &direction);
		exit = world.HandleInput(direction, pos);
	}

	system("pause");
	return 0;
}

