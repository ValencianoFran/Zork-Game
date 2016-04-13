#ifndef _STRING__
#define _STRING__
#include <string.h>


class String
{
private:

	char* my_string = "";
	unsigned int max_size = strlen(my_string) + 1;

public:

	String();
	String(const char* str);
	String(const String& other);
	unsigned int lenght() const;
	const char* c_str() const;
	bool empty() const;
	const bool operator==(String other) const;
	void operator=(const String& other);
	void operator+=(const String& other);
	String operator+(const String& other);
	~String();
};




#endif