#ifndef _ROOMS__
#define _ROOMS__

class Room : public Entity
{
public:
	Vector <Room*> room;
	Vector <Exit*> exit;
	Room();
	Room(const char* _name, const char* desc);
	~Room();

	bool Init(const char* _name, const char* desc);
};

#endif