#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exit.h"
#include "room.h"

Exit::Exit()
{}

Exit::Exit(const char* _name, const char* desc, Room* orig, Room* dest, const dir direc)
{
	if (_name != NULL && desc != NULL && orig != NULL && dest != NULL)
	{
		strcpy_s(name, _name);
		strcpy_s(description, desc);
		origin = orig;
		destination = dest;
		direction = direc;
	}
}


Exit::~Exit()
{}

void Exit::Init(const char* _name, const char* desc, Room* orig, Room* dest, const dir direc)
{
	bool ret = true;

	if (ret = (_name != NULL && desc != NULL && orig != NULL && dest != NULL))
	{
		strcpy_s(name, _name);
		strcpy_s(description, desc);
		origin = orig;
		destination = dest;
		direction = direc;
	}
}