#ifndef _ROOMS__
#define _ROOMS__

class Room
{
public:
	char description[300];
	char name[25];
	int allowpass = 0;  // to controle gates ... 0 is open
	
	typedef struct
	{
		char *north;
		char *south;
		char *east;
		char *west;
	}position;

	position myposition;
	position shore;
	position depths;
	position sea;
	position palmtrees;
	position monkey;
	position outsidehouse;
	position house;
	position shop;
	position store;
};



#endif