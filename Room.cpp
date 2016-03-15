#include <stdio.h>
#include <stdlib.h>
#include "World.h"
#include "Room.h"
#include "Exit.h"
#include <string.h>

Room::Room()
{}

Room::Room(const char* _name, const char* desc)
{
	if (_name != NULL && desc != NULL)
	{
		strcpy_s(name, _name);
		strcpy_s(description, desc);
	}
}



Room::~Room()
{}


bool Room::Init(const char* _name, const char* desc)
{
	bool ret = true;

	if (ret = (_name != NULL && desc != NULL))
	{
		strcpy_s(name, _name);
		strcpy_s(description, desc);
	}

	return ret;
}


