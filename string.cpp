#include<string.h>
#include<stdio.h>
#include"string.h"
#include"vector.h"
#include <iostream>
#include <ctime>
#include <ctype.h>
#include <cmath>
#include <windows.h>


//VOID CONSTRUCTOR
String::String()
{}

//CONSTRUCTOR
String::String(const char* str)
{
	int size = strlen(str) + 1;
	my_string = new char[size];
	max_size = size;
	strcpy_s(my_string, size, str);
}

//COPY CONSTRUCTOR
String::String(const String& other)
{
	int size = strlen(other.my_string) + 1;
	my_string = new char[size];
	max_size = size;
	strcpy_s(my_string, size, other.my_string);
}

//STRING LONGITUDE
unsigned int String::lenght() const
{
	return max_size;
}

//RETURN STRING
char* String::c_str() const
{
	return my_string;
}

//IS STRING EMPTY?
bool String::empty() const
{
	return strlen(my_string) == 0;
}

//== OPERATOR

//compare 2 string classes
bool String::operator==(const String &other) const
{
	return _stricmp(my_string, other.my_string) == 0;
}

//compare string(class) - string
bool String::operator==(const char *string) const
{
	return _stricmp(my_string, string) == 0;
}


//= OPERATOR
void String::operator=(const String& other)
{
	int size = strlen(other.my_string) + 1;
	if (other.lenght() > max_size)
	{
		delete[] my_string;
		my_string = new char[size];
		max_size = size;
	}
	strcpy_s(my_string, max_size, other.my_string);
}

//copy string(class) - string

void String::operator=(const char* other)
{
	unsigned int size = strlen(other) + 1;
	if (size > max_size)
	{
		delete[] my_string;
		my_string = new char[size];
		max_size = size;
	}
	strcpy_s(my_string, max_size, other);
}

//OPERATOR +=
void String::operator+=(const String& other)
{
	char* temp = nullptr;
	unsigned int size = other.lenght() + max_size;
	temp = new char[max_size];
	strcpy_s(temp, max_size, my_string);

	if (max_size < size)
	{
		delete[] my_string;
		my_string = new char[size];
		max_size = size;
	}

	strcpy_s(my_string, size, temp);
	strcat_s(my_string, size, other.my_string);
	delete[] temp;
}

//+ OPERADOR
String String::operator+(const String& other)
{
	String new_str("New String");
	int size = strlen(my_string) + strlen(other.my_string) + 1;
	new_str.my_string = new char[size];
	strcpy_s(new_str.my_string, size, other.my_string);
	strcpy_s(new_str.my_string, size, other.my_string);
	return new_str;
}

//!= OPERATOR

bool String::operator!=(const String& other) const
{
	return _stricmp(my_string, other.my_string) != 0;
}

bool String::operator!=(const char* other) const
{
	return _stricmp(my_string, other) != 0;
}

char String::return_word(const int& number) const
{
	return my_string[number];
}

//TOKEN 
Vector<String> String::SplitString()
{
	Vector<String> words;
	char *temp, *restant_string, *context;
	char* divide = nullptr;

	int len = strlen(my_string);
	temp = new char[len + 1];
	strcpy_s(temp, len + 1, my_string);

	restant_string = strtok_s(temp, divide, &context);
	while (restant_string != NULL)
	{
		words.push_back(p);
		restant_string = strtok_s(NULL, divide, &context);
	}
	delete[] temp;
	return words;
}



void String::tolower_method()
{
	int i = 0;
	if (my_string != NULL)
	{
		while (my_string[i] != '\0')
		{
			my_string[i] = tolower(my_string[i]);
			i++;
		}
	}

}
int const String::spaces() const
{
	int i = 0;
	int spaces = 0;
	while (my_string[i] != '\0')
	{
		if (my_string[i] == ' ') spaces++;
		i++;
	}
	return spaces;
}

//DESTRUCTOR
String::~String()
{
	delete[] my_string;
}