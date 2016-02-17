#include <stdio.h>
#include <stdlib.h>


typedef struct{

	char *north;
	char *south;
	char *east;
	char *west;
	

}position;

position myposition;
position dinningroom;
position kitchen;
position bathroom;
position bedroom;
position pantry;

void move(char a) {

	switch (a) {
	case 'n':
		if (myposition.north != "wall") {
			if (myposition.north == "kitchen") {
				printf("I'm in the kitchen!\n\n");
				myposition = kitchen;
				break;
			}
		}
		printf("There's a wall!\n");
		break;
	case 's':
		if (myposition.south != "wall") {
			if (myposition.south == "bedroom") {
				printf("I'm in the bedroom!\n\n");
				myposition = bedroom;
				break;
			}
			if (myposition.south == "dinningroom") {
				printf("I'm in the dinningroom!\n\n");
				myposition = dinningroom;
				break;
			}
		}
		printf("There's a wall!\n");
		break;
	case 'e':
		if (myposition.east != "wall") {
			if (myposition.east == "bathroom") {
				printf("I'm in the bathroom!\n\n");
				myposition = bathroom;
				break;
				}
			if (myposition.east == "pantry") {
				printf("I'm in the pantry!\n\n");
				myposition = pantry;
				break;
				}
		}
		printf("There's a wall!\n");
		break;
	case 'w':
		if (myposition.west != "wall") {
			if (myposition.west == "dinningroom") {
				printf("I'm in the dinning room!\n\n");
				myposition = dinningroom;
				break;
			}
			if (myposition.west == "kitchen") {
				printf("I'm in the kitchen!\n\n");
				myposition = kitchen;
				break;
			}
		}
		printf("There's a wall!\n");
		break;
	case 'q':
		printf("See you later! ^^\n");
		break;

	default:
		printf("Thats not a direction!\n");
		break;
	}

}

int main() {
	dinningroom.north = "kitchen";
	dinningroom.south = "bedroom";
	dinningroom.east = "bathroom";
	dinningroom.west = "wall";
	kitchen.south = "dinningroom";
	kitchen.east = "pantry";
	kitchen.north = "wall";
	kitchen.west = "wall";
	bathroom.west = "dinningroom";
	bathroom.east = "wall";
	bathroom.north = "wall";
	bathroom.south = "wall";
	bedroom.south = "wall";
	bedroom.west = "wall";
	bedroom.east = "wall";
	bedroom.north = "dinningroom";
	pantry.east = "wall";
	pantry.west = "kitchen";
	pantry.north = "wall";
	pantry.south = "wall";

	char d = 'f';

	myposition = dinningroom;
	
	printf("Where do you want to go?: \n");
	while (d != 'q') {
		scanf_s(" %c", &d);
		move(d);
	}

	system("pause");
	return 0;
}

