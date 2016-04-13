#include <stdio.h>
#include <stdlib.h>
#include "world.h"
#include "room.h"
#include "exit.h"
#include <string.h>

Room::Room(const char* _name, const char* _desc) : Entity(_name, _desc)
{}

Room::~Room()
{}


