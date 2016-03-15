#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "world.h"
#include "exit.h"
#include "player.h"



int main() {
	World world;
	world.CreateWorld();

	char direction[30];

	printf("Introduce where you want to go <'n', 's', 'w', 'e', 'u', 'd'>\n\n");

	while (0 != strcmp(direction, "quit"))
	{
		gets_s(direction, 20);
		world.Mayus(direction);
	}

	system("pause");
	return 0;
}

