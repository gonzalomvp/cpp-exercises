// practica11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma warning( disable : 4710)

#include "TList.h"
#include "fileUtils.h"

int main()
{
	const char *string;
	TList list;

	NFileUtils::getListFromFile("ints.txt", list);
	
	printf("size: %d\n", list.Size());
	string = list.First();
	while (string) {
		printf("%s\n", string);
		string = list.Next();
	}

	printf("POP: %s\n", list.Pop());
	printf("POP: %s\n", list.Pop());
	printf("POP: %s\n", list.Pop());
	printf("POP: %s\n", list.Pop());
	printf("POP: %s\n", list.Pop());
	printf("POP: %s\n", list.Pop());
	printf("POP: %s\n", list.Pop());
	printf("POP: %s\n", list.Pop());

	printf("size: %d\n", list.Size());
	string = list.First();
	while (string) {
		printf("%s\n", string);
		string = list.Next();
	}

	getchar();
    return 0;
}

