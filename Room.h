#ifndef _ROOMS__
#define _ROOMS__

class Room
{
public:
	char name[25];
	char description[300];

	Room();
	Room(const char* _name, const char* desc);
	~Room();

	bool Init(const char* _name, const char* desc);
};

#endif