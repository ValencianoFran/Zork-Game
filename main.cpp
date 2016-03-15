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

	printf("WELCOME TO MY ZORK!\nYou are lost in one island and you have to scape.\nHave fun!\n\n");
	world.Tutorial();
	printf("Introduce where you want to go:\n");

	while (0 != strcmp(direction, "quit"))
	{
		gets_s(direction, 20);
		world.Mayus(direction);
	}

	system("pause");
	return 0;
}

