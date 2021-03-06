// practica3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include "assert.h"
#include "practica3.h"
#pragma warning( disable : 4710)

const char * tablaCadenas[] =
{
	"cadena0",
	"cadena1",
	"cadena2"
};

const unsigned int size = sizeof(tablaCadenas) / sizeof(*tablaCadenas);

int main()
{
	unsigned int index = 2;
	const char *string = nullptr;
	

	if (getString(index, string))
	{
		printf("La cadena %d es: %s\n", index, string);
		char *stringInverted = new char[strlen(string) + 1];
		if (getInvertedString(index, stringInverted))
		{
			printf("La cadena %d invertida es: %s\n", index, stringInverted);
		}
		delete []stringInverted;
	}
	
	getchar();
    return 0;
}

bool getString(unsigned int index, const char *&string)
{
	bool res = false;
	if (index < size)
	{
		string = tablaCadenas[index];
		res = true;
	}

	return res;
}

bool getInvertedString(unsigned int index, char *string)
{
	assert(string);
	bool res = false;
	const char *stringSrc = nullptr;
	if (getString(index, stringSrc))
	{
		unsigned int stringLength = strlen(stringSrc);

		for (unsigned int i = 0; i < stringLength; i++)
		{
			*(string + i) = *(stringSrc + stringLength - 1 - i);
		}

		*(string + stringLength) = *(stringSrc + stringLength);
		
		res = true;
	}

	return res;
}