#include "exit.h"
#include "room.h"


Exit::Exit(const char* _name, const char* _desc, Room* _orig, Room* _dest, const dir _direc) : Entity(_name, _desc)
{
	origin = _orig;
	destination = _dest;
	direction = _direc;
}

Exit::~Exit()
{}