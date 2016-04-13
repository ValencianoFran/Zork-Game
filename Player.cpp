#include <stdio.h>
#include <stdlib.h>
#include "player.h"


Player::Player(int _hp, int _dmg, Room* _pos)
{
	hp = _hp;
	damage = _dmg;
	position = _pos;
}