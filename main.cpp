#include"world.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main() {
	fflush(stdin);
	World world;
	world.CreateWorld(); //Create the world

	char direction[30]; //The direction that user will input

	printf("WELCOME TO MY ZORK!\nYou are lost in one island and you have to scape.\nHave fun!\n\n");
	world.Tutorial(); //Controls
	printf("Introduce where you want to go:\n");

	while (0 != strcmp(direction, "quit"))
	{
		gets_s(direction, 20);
		world.Mayus(direction);
	}

	system("pause");
	return 0;
}

